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
