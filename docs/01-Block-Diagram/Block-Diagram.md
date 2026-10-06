---
title: Block Diagram
hide:
  - navigation
  - toc
---

# Block Diagram

Nikita Bangiyev, Team 201, Fill-A-Bot (automatic liquid dispenser)

## Overview

I'm doing the main control board. It's the I2C host for the team. It reads the buttons, tells Clay's board to run the pump, gets the flow and weight readings from Cole's and Troy's boards, and shows the amount on a 4-digit display. My sensor is a photoresistor under the cup spot with an op amp, so the pump only starts when a cup is there.

![Main control board block diagram](nikita-block-diagram.png){ width="100%" }

Figure 1: Main control board block diagram (click to enlarge). Draw.io file: [nikita-block-diagram.drawio](nikita-block-diagram.drawio)

## Power

- 9V 3A wall adapter into a barrel jack (unregulated)
- LM7805 makes 5V (regulated, 1.5A max) for the rest of the board
- The Nano gets 5V on VTG with VOFF tied to GND
- My board draws about 150 mA, so the LM7805 doesn't need a heat sink

## Pin Assignments

| Pin | Use | Connects to |
|---|---|---|
| RA0-RA3 | Digital input | UP, DOWN, START, STOP buttons |
| RA5 | ADC | Cup sensor (op amp output) |
| RD0-RD2 | Digital output | Dispensing, Done, Fault LEDs |
| RB2 / RB1 | I2C SDA / SCL | Display driver and all 3 ribbon connectors |

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
| 5V regulator (U2) | Texas Instruments | LM7805CT |
| Barrel jack (J4) | Same Sky | PJ-102AH |
| Photoresistor (LDR1) | Advanced Photonix | PDV-P8103 |
| Op amp (U3) | Microchip | MCP6002-I/P |
| Display driver (U4) | Holtek | HT16K33 |
| 7-segment display (DS1) | Lucky Light | KW4-56NCUYA-P |
| Buttons (SW1-SW4) | Omron | B3F-1000 |
| Ribbon headers (J1-J3) | Wurth Elektronik | 61200821621 |

## Notes

- I put the HT16K33 chip on my own board instead of using an Adafruit display backpack, since daughter boards aren't allowed.
- The op amp is needed because a photoresistor and resistor alone don't count as an analog sensor. It's the same circuit from my photoresistor lab.
- The pin assignments and some part numbers might still change during component selection.

## References

1. Microchip, PIC18F57Q43 Curiosity Nano Hardware User Guide. [Link](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/UserGuides/PIC18F57Q43-Curiosity-Nano-HW-UserGuide-DS40002186B.pdf)
2. Texas Instruments, LM7805 datasheet. [Link](https://www.ti.com/lit/ds/symlink/lm340.pdf)
3. Holtek, HT16K33 datasheet. [Link](https://cdn-shop.adafruit.com/datasheets/ht16K33v110.pdf)
4. Lucky Light, KW4-56NCUYA-P display datasheet. [Link](https://cdn-shop.adafruit.com/datasheets/811datasheet.pdf)
5. Microchip, MCP6002 datasheet. [Link](https://ww1.microchip.com/downloads/en/DeviceDoc/MCP6001-1R-1U-2-4-1-MHz-Low-Power-Op-Amp-DS20001733L.pdf)
6. Advanced Photonix, PDV-P8103 datasheet. [Link](https://media.digikey.com/pdf/data%20sheets/photonic%20detetectors%20inc%20pdfs/pdv-p8103.pdf)
7. Same Sky, PJ-102AH datasheet. [Link](https://www.sameskydevices.com/product/resource/pj-102ah.pdf)
8. Omron, B3F tactile switch. [Link](https://components.omron.com/us-en/products/switches/B3F)
9. Wurth Elektronik, WR-BHD box header. [Link](https://www.we-online.com/en/components/products/WTB_WR_BHD_BOX_HEADER_2_54MM_MALE_PCB)
10. EGR 304 Project Description. [Link](https://embedded-systems-design.bitbucket.io/304/course-info/project-description/)
