---
title: Block Diagram
hide:
  - navigation
  - toc
---

# Block Diagram

Nikita Bangiyev, Team 201, Fill-A-Bot (automatic liquid dispenser)

## Overview

I'm doing the main control board. It's the I2C host for the team. It reads the buttons, tells Clay's board to run the pump, gets the flow and weight readings from Cole's and Troy's boards, and shows the amount and status on a 16x2 LCD. My sensor is a photoresistor under the cup spot with an op amp, so the pump only starts when a cup is there.

![Main control board block diagram](nikita-block-diagram.png){ width="100%" }

Figure 1: Main control board block diagram (click to enlarge). Draw.io file: [nikita-block-diagram.drawio](nikita-block-diagram.drawio)

## Power

- 9V 2A regulated wall adapter (Triad WSU090-2000) into a barrel jack (Same Sky PJ-102AH)
- LM1086IT-5.0 linear regulator makes 5V (1.5A max, 4.9 to 5.1V) for the whole board
- The regulator has a heat sink (Same Sky HSE14-384225P) with an insulating pad, because its tab is at 5V
- The Nano gets 5V on VTG with VOFF tied to GND
- My power budget is 428mA with the 25% margin (see [Power Budget](../05-Power-Budget/Power-Budget.md))

## Pin Assignments

| Pin | Use | Connects to |
|---|---|---|
| RA0, RA1, RA4, RA3 | Digital input | UP, DOWN, START, STOP buttons (active low, 10k pull-ups) |
| RA5 | ADC | Cup sensor (op amp output through 1k + 10nF) |
| RA2 | DAC output | Reference voltage for the op amp gain stage |
| RD0-RD2 | Digital output | Dispensing, Done, Fault LEDs (active low, 2.2k each) |
| RC0-RC3 | Digital output | LCD DB4-DB7 |
| RC4, RC5 | Digital output | LCD RS and E |
| RB2 / RB1 | I2C SDA / SCL | All 3 ribbon connectors |

START moved from RA2 to RA4 so RA2 can be the DAC output. The full pin table is on my [Component Selection](../02-Component-Selection/Component-Selection.md) page.

## Ribbon Connectors

J1 goes to Cole, J2 to Clay, and J3 to Troy. All three are wired the same and follow the class standard.

| Pin | Signal |
|---|---|
| 1 | SDA (RB2) |
| 2 | SCL (RB1) |
| 3-7 | Not connected |
| 8 | GND |

The team diagram currently has +5V on pin 4. I left it unconnected because the class standard says pins 1-7 have to go to the microcontroller, and every board has its own regulator. We'll update the team diagram.

## Parts

| Part | Manufacturer | Part # |
|---|---|---|
| Curiosity Nano (U1) | Microchip | PIC18F57Q43 (DM164150) |
| 5V regulator (U2) | Texas Instruments | LM1086IT-5.0/NOPB |
| Regulator heat sink (HS1) | Same Sky | HSE14-384225P |
| 9V wall adapter | Triad Magnetics | WSU090-2000 |
| Barrel jack (J4) | Same Sky | PJ-102AH |
| Photoresistor (LDR1) | Advanced Photonix | PDV-P8103 |
| Op amp (U3) | Microchip | MCP6002-I/P |
| 16x2 LCD (DS1) | Newhaven Display | NHD-0216K1Z-FL-YBW |
| Buttons (SW1-SW4) | Omron | B3F-1000 |
| Ribbon headers (J1-J3) | Wurth Elektronik | 61200821621 |

## Notes

- I switched from a 4-digit 7-segment display to a 16x2 LCD, because the team requirements need words like Ready, Filling, and Finished. The LCD has its own controller, so the HT16K33 driver is gone. It was discontinued anyway.
- The op amp is needed because a photoresistor and resistor alone don't count as an analog sensor. U3A buffers the divider and U3B amplifies it with a gain of -3. The PIC's DAC sets the reference, so it can re-zero for the room light.
- I switched from the LM7805 to the LM1086 because the LCD backlight needs 4.9 to 5.1V, and a 7805 can be 4.75 to 5.25V.

## References

1. Microchip, PIC18F57Q43 Curiosity Nano Hardware User Guide. [Link](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/UserGuides/PIC18F57Q43-Curiosity-Nano-HW-UserGuide-DS40002186B.pdf)
2. Microchip, PIC18F27/47/57Q43 data sheet. [Link](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/PIC18F27-47-57Q43-Microcontroller-Data-Sheet-XLP-DS40002147.pdf)
3. Texas Instruments, LM1086 datasheet. [Link](https://www.ti.com/lit/ds/symlink/lm1086.pdf)
4. Same Sky, HSE14-384225P heat sink datasheet. [Link](https://www.sameskydevices.com/product/resource/hse14-384225p.pdf)
5. Triad Magnetics, WSU090-2000 datasheet. [Link](https://catalog.triadmagnetics.com/Asset/WSU090-2000.pdf)
6. Newhaven Display, NHD-0216K1Z-FL-YBW datasheet. [Link](https://newhavendisplay.com/content/specs/NHD-0216K1Z-FL-YBW.pdf)
7. Microchip, MCP6002 datasheet. [Link](https://ww1.microchip.com/downloads/en/DeviceDoc/MCP6001-1R-1U-2-4-1-MHz-Low-Power-Op-Amp-DS20001733L.pdf)
8. Advanced Photonix, PDV-P8103 datasheet. [Link](https://media.digikey.com/pdf/data%20sheets/photonic%20detetectors%20inc%20pdfs/pdv-p8103.pdf)
9. Same Sky, PJ-102AH datasheet. [Link](https://www.sameskydevices.com/product/resource/pj-102ah.pdf)
10. Omron, B3F tactile switch. [Link](https://components.omron.com/us-en/products/switches/B3F)
11. Wurth Elektronik, WR-BHD box header. [Link](https://www.we-online.com/en/components/products/WTB_WR_BHD_BOX_HEADER_2_54MM_MALE_PCB)
12. EGR 304 Project Description. [Link](https://embedded-systems-design.bitbucket.io/304/course-info/project-description/)
