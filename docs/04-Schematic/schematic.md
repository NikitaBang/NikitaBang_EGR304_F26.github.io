---
title: Schematics
---

# Schematics

This is the schematic for my Main Control Board. It has the 9-12V power input and 5V regulator, the Curiosity Nano, the cup sensor with the op amp, the LCD, the buttons and LEDs, and the three ribbon cables that connect to my teammates' boards over UART.

![Main Control Board schematic](Nikita-Main-Control-Schematic.png){ width="100%" }

Figure 1: Main Control Board schematic (click to enlarge)

## How It Meets the Requirements

- **Power:** The barrel jack takes 9-12V, goes through a swappable T800mA fuse, and the LM1086 linear regulator makes 5V. It has the input and output caps from the TI datasheet (10uF tantalum on the output). D6 and D5 show that the 9V and 5V rails are on.
- **User input:** UP, DOWN, START, and STOP buttons each have a 10k pull-up and an RC debounce, so the user can pick the amount and start or stop a fill. J9 lets the buttons be mounted off the board.
- **Cup sensor:** The photoresistor goes through a buffer, a gain stage, and a low-pass filter into the ADC (RA5). This is how the board knows a cup is there before it starts the pump.
- **Display and status:** The 16x2 LCD shows the amount and status, and three LEDs show Dispensing, Done, and Fault.
- **Team:** Each teammate gets their own UART on a 2x4 ribbon header. Pin 1 is my TX, pin 2 is my RX, and pin 8 is ground.
- **Debugging:** There's a debug LED (RF2), a debug button (RF4), jumpers to cut the power and signal lines, 15 test points, and spare Nano pins on the J5 and J6 headers.
- **ERC:** 0 errors and 0 warnings.

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
