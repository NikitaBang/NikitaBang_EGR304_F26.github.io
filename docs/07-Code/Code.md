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
/*
 * rev7_hw_test.c
 * Hardware verification test for the Fill-A-Bot main control board, Rev 7
 * PIC18F57Q43 Curiosity Nano, XC8, no MCC needed (one file)
 * Nikita Bangiyev, EGR 304 Team 201
 *
 * Everything runs at the same time, no menus:
 *
 * 0. Sign of life
 *    The Nano's own little LED (LED0, RF3) blinks about twice a second.
 *    Blinking = the PIC is powered, programmed and running this code.
 *    Not blinking = the PIC is not running (check power, main project, Hold in Reset).
 *
 * 1. Ribbon WRITE
 *    RD4, RD3, RF6, RF5 go high for 2 s, then low for 2 s, forever.
 *    Meter on J2 pin 1, J2 pin 2, J3 pin 1, J3 pin 2:
 *    about 4.4 V high (1N4007 diodes), 0 V low.
 *
 * 2. Ribbon READ
 *    RC7, RC6, RE1, RE0 get read every 10 ms and copied to an LED:
 *      J1 pin 3 (RC7, flow S1 from Cole)    -> D2 yellow
 *      J1 pin 4 (RC6, flow S0 from Cole)    -> D3 green
 *      J3 pin 3 (RE1, weight S1 from Troy)  -> D4 red
 *      J3 pin 4 (RE0, weight S0 from Troy)  -> Watch window only (Nano LED is the heartbeat)
 *    Put 5 V on one of those ribbon pins and its LED turns on.
 *    The 100k pull-downs make an unplugged pin read 0 (LED off).
 *    Watch window: ribbon_in  (bit 3 = RC7, bit 2 = RC6, bit 1 = RE1, bit 0 = RE0)
 *
 * 3. Cup sensor ADC
 *    RA5 (ANA5, TP9 / CUP_ADC) gets read every 10 ms.
 *    Watch window: adc_value (0-4095) and adc_mv (about the same as TP9 on the meter)
 *    Hold any button (UP, DOWN, START or STOP) and the 3 LEDs turn into a level bar:
 *      yellow = over 1/4, + green = over 1/2, + red = over 3/4
 *    Cover the LDR -> AMP_OUT goes up -> more LEDs light.
 *
 * Power order: adapter into J4 FIRST, then USB. VOFF is tied to ground on this
 * board, so USB alone does not power the PIC.
 */

#include <xc.h>
#include <stdint.h>

/* Config bits. If MPLAB complains about one of these lines, delete them and make
 * new ones with Window > Target Memory Views > Configuration Bits
 * (FEXTOSC off, RSTOSC HFINTOSC 64 MHz, WDT off), then paste those in. */
#pragma config FEXTOSC = OFF            /* no external oscillator */
#pragma config RSTOSC = HFINTOSC_64MHZ  /* internal oscillator, 64 MHz */
#pragma config MCLRE = EXTMCLR          /* MCLR pin is reset */
#pragma config WDTE = OFF               /* watchdog off */
#pragma config LVP = ON                 /* low-voltage programming (the Nano uses it) */
#pragma config XINST = OFF              /* normal instruction set */

#define _XTAL_FREQ 64000000UL           /* for __delay_ms() */

/* Put these in the Watch window (Debug mode, then Pause to see them update) */
volatile uint16_t adc_value;   /* 0-4095 */
volatile uint16_t adc_mv;      /* adc_value in mV, assumes VDD = 5.00 V */
volatile uint8_t  ribbon_in;   /* bit3 RC7, bit2 RC6, bit1 RE1, bit0 RE0 */
volatile uint8_t  ribbon_out;  /* 1 = the 4 outputs are high right now */
volatile uint16_t adc_timeouts; /* should stay 0; counts ADC reads that never finished */

#define LED_ON   0u            /* LEDs are active low (anode to 5 V through 2.2k) */
#define LED_OFF  1u

static void init(void)
{
    /* All pins digital except RA5 (cup sensor) */
    ANSELA = 0x20;             /* RA5 analog */
    ANSELB = 0x00;
    ANSELC = 0x00;
    ANSELD = 0x00;
    ANSELE = 0x00;
    ANSELF = 0x00;

    /* Safe starting values before the pins become outputs:
     * LEDs off (high), ribbon outputs low (pump = 00 = stop) */
    LATD = 0x07;               /* RD0-RD2 high = D2-D4 off, RD3/RD4 low */
    LATF = 0x08;               /* RF3 high = Nano LED0 off, RF5/RF6 low */

    TRISA = 0xFF;              /* RA0-RA3 buttons, RA5 cup sensor: inputs */
    TRISB = 0xFF;              /* not used */
    TRISC = 0xFF;              /* RC6, RC7 ribbon inputs */
    TRISE = 0xFF;              /* RE0, RE1 ribbon inputs */
    TRISD = 0xE0;              /* RD0-RD4 outputs, RD5-RD7 inputs (J5, not used) */
    TRISF = 0x97;              /* RF3, RF5, RF6 outputs, the rest inputs */

    /* ADC: VDD/VSS reference, channel ANA5, right justified, ADC's own RC clock */
    ADREF  = 0x00;             /* + ref = VDD, - ref = VSS */
    ADPCH  = 0x05;             /* ANA5 = RA5 */
    ADCON0 = 0x94;             /* ON (bit 7), CS = ADCRC (bit 4), FM = right justified (bit 2) */
    __delay_us(50);            /* let the input settle before the first reading */
}

static uint16_t adc_read_ra5(void)
{
    uint16_t guard = 0;
    ADCON0 |= 0x01u;           /* GO */
    while (ADCON0 & 0x01u) {   /* GO clears when the conversion is done */
        if (++guard > 20000u) {            /* never hang here: give up and move on */
            ADCON0 &= (uint8_t)~0x01u;
            adc_timeouts++;
            return 0;
        }
    }
    return (uint16_t)(((uint16_t)ADRESH << 8) | ADRESL);
}

static void ribbon_outputs(uint8_t level)
{
    LATDbits.LATD4 = level;    /* J2 pin 1, pump C1, through D7 */
    LATDbits.LATD3 = level;    /* J2 pin 2, pump C0, through D8 */
    LATFbits.LATF6 = level;    /* J3 pin 1, preset C1, through D9 */
    LATFbits.LATF5 = level;    /* J3 pin 2, preset C0, through D10 */
}

void main(void)
{
    uint16_t ticks = 0;
    uint8_t  beat = 0;

    init();

    while (1) {
        /* 1. ribbon outputs flip every 2 s (200 loops x 10 ms) */
        if (++ticks >= 200u) {
            ticks = 0;
            ribbon_out ^= 1u;
            ribbon_outputs(ribbon_out);
        }

        /* 0. heartbeat: Nano LED0 toggles every 250 ms (25 loops x 10 ms) */
        if (++beat >= 25u) {
            beat = 0;
            LATFbits.LATF3 ^= 1u;
        }

        /* 2. ribbon inputs */
        uint8_t in = 0;
        if (PORTCbits.RC7) in |= 0x08u;
        if (PORTCbits.RC6) in |= 0x04u;
        if (PORTEbits.RE1) in |= 0x02u;
        if (PORTEbits.RE0) in |= 0x01u;
        ribbon_in = in;

        /* 3. cup sensor */
        uint16_t a = adc_read_ra5();
        adc_value = a;
        adc_mv = (uint16_t)(((uint32_t)a * 5000u) / 4095u);

        /* LEDs: any button held = ADC level bar, otherwise show the ribbon inputs.
         * Buttons pull RA0-RA3 low when pressed. */
        if ((PORTA & 0x0Fu) != 0x0Fu) {
            LATDbits.LATD0 = (a > 1024u) ? LED_ON : LED_OFF;   /* D2 yellow */
            LATDbits.LATD1 = (a > 2048u) ? LED_ON : LED_OFF;   /* D3 green */
            LATDbits.LATD2 = (a > 3072u) ? LED_ON : LED_OFF;   /* D4 red */
        } else {
            LATDbits.LATD0 = (in & 0x08u) ? LED_ON : LED_OFF;  /* RC7 -> yellow */
            LATDbits.LATD1 = (in & 0x04u) ? LED_ON : LED_OFF;  /* RC6 -> green */
            LATDbits.LATD2 = (in & 0x02u) ? LED_ON : LED_OFF;  /* RE1 -> red */
        }

        __delay_ms(10);
    }
}
```
