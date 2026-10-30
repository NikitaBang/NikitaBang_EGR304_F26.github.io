---
title: Schematics
---

# Schematics

This is the schematic for my Main Control Board (rev 4, October 30, 2026). It has the 9-12V power input and 5V regulator, the Curiosity Nano, the cup sensor with the op amp, the LCD, the buttons and LEDs, and the three ribbon cables to my teammates' boards. Each signal on the ribbons is 2 plain digital wires with 4 states (00, 01, 10, 11). There's no UART, I2C, or SPI between boards.

![Main Control Board schematic](Nikita-Main-Control-Schematic.png){ width="100%" }

Figure 1: Main Control Board schematic (click to enlarge)

## How It Meets the Requirements

The numbers in brackets are from our team's [Product Requirements](https://egr304-2026-f-201.github.io/04-Product-Requirements/) page ("Design" means the Requirement Criteria Specifications list).

- **Power [6.7]:** The barrel jack takes 9-12V, goes through a swappable T800mA fuse, and the LM1086 linear regulator makes 5V. It has the input and output caps from the TI datasheet (10uF tantalum on the output) and a 0.1uF bypass cap at every IC power pin. The worst-case load is 432mA with margin, well under the regulator's 1.5A, and the heat sink keeps it near 71 C. D6 and D5 show that the 9V and 5V rails are on.
- **Picking the amount [2.1, 3.1, 4.1, Design 2.4]:** UP and DOWN pick one of the 4 fill presets, and START starts the fill. Each button has a 10k pull-up and an RC debounce, so one press reads as one press. J9 lets the buttons be mounted off the board.
- **Stopping at any time [6.1, Design 1.5, Design 3.4]:** STOP is its own button on RA3. The firmware sets the pump command to 00 (stop) from any step.
- **Cup sensor:** The photoresistor goes through a buffer, a gain stage, and a low-pass filter into the ADC (RA5), so the pump only starts when a cup is in place. This answers the open question on our requirements page about checking for a container before dispensing.
- **Display and status [3.2, 3.3, 3.4, Design 2.1]:** The 16x2 LCD shows the preset amount and the status (Ready, Filling, Finished, Error). Three LEDs show Dispensing, Done, and Fault, and the Fault LED flashes when there's no flow.
- **Measuring and stopping at the target [1.2, 2.2, 2.3, 6.4]:** My board sends the preset to Troy's board (RF6, RF5) and the run command to Clay's board (RD4, RD3). It watches the weight status from Troy (RE1, RE0) and the flow status from Cole (RC7, RC6), and stops the pump when the target is reached. J1, J2, and J3 follow the class ribbon standard with pin 8 as ground and no power pin. Pins 1-2 are always my outputs and pins 3-4 are always the teammate's outputs back to me.
- **No unintended dispensing [2.6]:** The ribbon outputs start low, so the pump command is 00 (stop) at power-up. R26-R29 are 100k pull-downs on my four ribbon inputs, so an unplugged cable reads 00 (no flow or not ready) instead of floating, and the pump won't run.
- **Repeat fills [2.4]:** After a fill is done, the firmware goes back to picking a preset without a restart.
- **Debugging:** There's a debug LED (RF2), a debug button (RF4), jumpers to cut the power and every ribbon signal, 17 test points (including one on every ribbon signal), and spare Nano pins on the J5 and J6 headers.
- **Part numbers and ERC:** Every part has its manufacturer part number in the KiCad file, matching my [BOM](../03-BOM/BOM.md). ERC shows 0 errors and 0 warnings (the report is in the KiCad ZIP).

## Ribbon Cables

| Header | Teammate | Pin 1 | Pin 2 | Pin 3 | Pin 4 | Pins 5-7 | Pin 8 |
|---|---|---|---|---|---|---|---|
| J1 | Cole (flow) | NC | NC | Flow S1 in (RC7) | Flow S0 in (RC6) | NC | GND |
| J2 | Clay (pump) | Pump C1 out (RD4) | Pump C0 out (RD3) | NC | NC | NC | GND |
| J3 | Troy (weight) | Weight C1 out (RF6) | Weight C0 out (RF5) | Weight S1 in (RE1) | Weight S0 in (RE0) | NC | GND |

Each ribbon signal goes through a jumper (JP3, JP4, JP6-JP11) and has a test point, so I can unplug one line or check it with a meter.

## Signal Codes

| Signal | 00 | 01 | 10 | 11 |
|---|---|---|---|---|
| Pump command (to Clay) | Stop | Run | Not used (stop) | Not used (stop) |
| Weight command (to Troy) | Preset 1 | Preset 2 | Preset 3 | Preset 4 |
| Weight status (from Troy) | Not ready | Below target | Target reached | Error |
| Flow status (from Cole) | No flow | Flowing | Not used (no flow) | Sensor fault |

## Changes in Rev 4

After the design review I cleaned up the schematic without adding or removing any parts: the 9V LED branch and the fuse output now use a VIN power arrow instead of a long wire, and the 100k pull-downs (R26-R29) sit right on their ribbon lines next to J1 and J3 instead of being joined by net labels from another section. I also renamed the spare Nano nets so they don't look like UART (GPIO_RF0, GPIO_RF1, GPIO_RF3, DBG_BTN_RF4) and moved the signal codes into one note in the ribbon section.

## Files

- [Schematic PDF](Nikita-Main-Control-Schematic.pdf)
- [KiCad project ZIP](EGR304_Main_Control_Nikita.zip)
