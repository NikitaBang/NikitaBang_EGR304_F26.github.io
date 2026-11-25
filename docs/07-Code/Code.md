---
title: Microcontroller Code
---

# Microcontroller Code

This is the hardware test program I used for the individual subsystem verification (Nov 25, 2026). It runs on the PIC18F57Q43 Curiosity Nano on my Main Control Board and tests my whole board at once: the ribbon outputs, the ribbon inputs, and the cup sensor ADC.

Download: [Rev7_HW_Test.zip](Rev7_HW_Test.zip) (MPLAB X project) or just [main.c](main.c)

I built it with MPLAB X v6.35 and XC8 v3.10. It's one C file and doesn't use MCC.

## What It Does

| Part | Pins | What the code does | How I check it |
|---|---|---|---|
| Heartbeat | RF3 (the Nano's LED) | Blinks about twice a second | If it blinks, the program is running |
| Ribbon outputs | RD4, RD3 (J2), RF6, RF5 (J3) | High for 2 s, low for 2 s, forever | Meter on J2 pins 1-2 and J3 pins 1-2 |
| Ribbon inputs | RC7, RC6 (J1), RE1, RE0 (J3) | Reads them every 10 ms into `ribbon_in`. RC7, RC6, and RE1 also turn on the yellow, green, and red LEDs. | 5V on one pin at a time, then pause the debugger and read `ribbon_in`: 8, 4, 2, 1 |
| Cup sensor | RA5 (ANA5) | 12-bit ADC read every 10 ms into `adc_value` and `adc_mv` | Compare `adc_mv` to the meter on TP9 |

## Bench Results (Nov 24-25)

Every ribbon output switched between 4.4V and 0V every 2 seconds. The high is 4.4V instead of 5V because of the 1N4007 diode drop.

For the cup sensor, I put the meter on TP9 and read `adc_mv` and `adc_value` in the debugger at three light levels:

| Light on the LDR | Meter on TP9 | adc_mv | adc_value |
|---|---|---|---|
| Uncovered | 0.004V | 2 | 2 |
| Hand over it | about 2.34V | 2343 | 1919 |
| Covered | 5.00V | 4997 | 4093 |

The PIC's reading matches the meter at all three levels. The count is about TP9 / 5 x 4095.

## How to Run It

1. Plug the 9-12V adapter into J4 first, then USB into the Nano. VOFF is tied to ground, so USB alone doesn't power the PIC. The JP1 shunt has to be on, and JP2 has to be on for the ADC.
2. Open Rev7_HW_Test.X in MPLAB X and set it as the main project.
3. If the build says "no device-support files specified", open Project Properties, pick your PIC18F-Q_DFP pack and XC8 under Conf: [default], and build again.
4. Click Make and Program Device. The Nano's LED starts blinking.
5. To see the numbers, use Debug Main Project, add `ribbon_in`, `adc_value`, and `adc_mv` to the Watches window, and click Pause to refresh them.

## Code

```c
// Rev7_HW_Test - hardware test for my main control board
// Nikita Bangiyev, EGR 304 Team 201

#include <xc.h>
#include <stdint.h>

#pragma config FEXTOSC = OFF
#pragma config RSTOSC = HFINTOSC_64MHZ
#pragma config MCLRE = EXTMCLR
#pragma config WDTE = OFF
#pragma config LVP = ON
#pragma config XINST = OFF

#define _XTAL_FREQ 64000000

// watch these in the debugger
volatile uint16_t adc_value;
volatile uint16_t adc_mv;
volatile uint8_t ribbon_in;
volatile uint8_t ribbon_out;

uint16_t read_adc(void) {
    uint16_t timeout = 0;
    ADCON0bits.ADGO = 1;
    while (ADCON0bits.ADGO) {
        timeout++;
        if (timeout > 20000) {
            ADCON0bits.ADGO = 0;
            return 0;
        }
    }
    return (uint16_t)((ADRESH << 8) | ADRESL);
}

void main(void) {
    uint8_t loops = 0;
    uint8_t blink = 0;
    uint16_t adc;

    // everything digital except RA5 (cup sensor)
    ANSELA = 0x20;
    ANSELB = 0;
    ANSELC = 0;
    ANSELD = 0;
    ANSELE = 0;
    ANSELF = 0;

    LATD = 0x07;    // LEDs off, ribbon outputs low
    LATF = 0x08;    // Nano LED off
    TRISA = 0xFF;
    TRISB = 0xFF;
    TRISC = 0xFF;
    TRISE = 0xFF;
    TRISD = 0xE0;   // RD0-RD4 outputs
    TRISF = 0x97;   // RF3, RF5, RF6 outputs

    // ADC on RA5, 0-5V, right justified
    ADREF = 0x00;
    ADPCH = 0x05;
    ADCON0 = 0x94;
    __delay_us(50);

    while (1) {
        loops++;
        blink++;

        // Nano LED blinks so I know it's running
        if (blink >= 25) {
            blink = 0;
            LATFbits.LATF3 = !LATFbits.LATF3;
        }

        // ribbon outputs flip every 2 s
        if (loops >= 200) {
            loops = 0;
            ribbon_out = !ribbon_out;
            LATDbits.LATD4 = ribbon_out;
            LATDbits.LATD3 = ribbon_out;
            LATFbits.LATF6 = ribbon_out;
            LATFbits.LATF5 = ribbon_out;
        }

        // ribbon inputs: RC7 = 8, RC6 = 4, RE1 = 2, RE0 = 1
        ribbon_in = (uint8_t)((PORTCbits.RC7 << 3) | (PORTCbits.RC6 << 2) | (PORTEbits.RE1 << 1) | PORTEbits.RE0);

        // cup sensor
        adc = read_adc();
        adc_value = adc;
        adc_mv = (uint16_t)((uint32_t)adc * 5000 / 4095);

        // LEDs are active low (0 = on)
        if ((PORTA & 0x0F) != 0x0F) {
            // any button held: LEDs show the cup sensor level
            LATDbits.LATD0 = !(adc > 1024);
            LATDbits.LATD1 = !(adc > 2048);
            LATDbits.LATD2 = !(adc > 3072);
        } else {
            // no button: LEDs copy the ribbon inputs
            LATDbits.LATD0 = !PORTCbits.RC7;
            LATDbits.LATD1 = !PORTCbits.RC6;
            LATDbits.LATD2 = !PORTEbits.RE1;
        }

        __delay_ms(10);
    }
}
```
