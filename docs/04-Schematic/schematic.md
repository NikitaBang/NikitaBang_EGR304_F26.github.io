---
title: Schematics
---

# Schematics

This is the schematic for my Main Control Board. It has the 9-12V power input and 5V regulator, the Curiosity Nano, the cup sensor with the op amp, the LCD, the buttons and LEDs, and the three ribbon cables that connect to my teammates' boards over UART.

![Main Control Board schematic](Nikita-Main-Control-Schematic.png){ width="100%" }

Figure 1: Main Control Board schematic (click to enlarge)

## Ribbon Cables

| Header | Teammate | Pin 1 | Pin 2 | Pin 8 |
|---|---|---|---|---|
| J1 | Cole | TX (RC6) | RX (RC7) | GND |
| J2 | Clay | TX (RD3) | RX (RD4) | GND |
| J3 | Troy | TX (RF6) | RX (RF5) | GND |

Pin 1 is my TX going to their RX, and pin 2 is their TX coming into my RX.

## Files

- [Schematic PDF](Nikita-Main-Control-Schematic.pdf)
- [KiCad project ZIP](EGR304_Main_Control_Nikita.zip)
