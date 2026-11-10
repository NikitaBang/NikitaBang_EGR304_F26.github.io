---
title: Schematics
---

# Schematics

This is the schematic for my Main Control Board (Rev 7, November 7, 2026). It has the 9-12V power input and 5V regulator, the Curiosity Nano, the cup sensor with the op amp, the buttons and status LEDs, the debug LED and button, the expansion header and test pads, and the three ribbon cables to my teammates' boards. Each signal on the ribbons is 2 plain digital wires with 4 states (00, 01, 10, 11). There's no UART, I2C, or SPI between boards.

![Main Control Board schematic](Nikita-Main-Control-Schematic.png){ width="100%" }

Figure 1: Main Control Board schematic, Rev 7 (click to enlarge)

The PCB made from this schematic is on my [PCB](../06-PCB/PCB.md) page.

## How It Meets the Requirements

The numbers in brackets are from our team's [Product Requirements](https://egr304-2026-f-201.github.io/04-Product-Requirements/) page.

- **Power [6.7]:** The barrel jack (J4) takes 9-12V, center positive. It goes through a swappable T800mA fuse (F1, in a 5x20mm holder), and the LD1085V50 linear regulator (U2) makes 5V. C3 (10uF) and C5 (0.1uF) are on the input and C4 (10uF tantalum) is on the output, which meets the 10uF minimum in the ST datasheet. There's a 0.1uF bypass cap at every IC power pin (C2 at the Nano, C6 at the op amp). U2 sits on an HSE14-384225P heat sink with an insulator, because its tab is at 5V. The worst-case load in my power budget is 432mA with margin (that still counts the old LCD), well under the regulator's 3A. JP1 sits between the regulator and the 5V rail, so I can cut power or measure the board current. D6 shows that fused VIN is on and D5 shows that 5V is on.
- **Picking the amount [2.1, 3.1, 4.1, Design 2.4]:** UP (RA0) and DOWN (RA1) pick one of the 4 fill presets, and START (RA2) starts the fill. Each button has a 10k pull-up and a 10k/1uF RC debounce, so one press reads as one press.
- **Stopping at any time [6.1, Design 1.5, Design 3.4]:** STOP is its own button on RA3. The firmware sets the pump command to 00 (stop) from any step.
- **Cup sensor:** The photoresistor (LDR1) sits under the cup spot and plugs into J8. U3A buffers the divider, U3B has a gain of -3 around a 2.5V reference (R6 and R7), and R10 and C9 make a low-pass filter (about 16 Hz) before the ADC on RA5. So the pump only starts when a cup is in place. JP2 can disconnect the ADC pin, and TP7, TP8, and TP9 let me check the reference, the op amp output, and the ADC input.
- **Status [3.3, 3.4]:** Three LEDs show Dispensing (yellow, RD0), Done (green, RD1), and Fault (red, RD2), and the Fault LED flashes when there's no flow. Rev 7 doesn't have the 16x2 LCD anymore, so my board has no screen to show the preset amount or status words (requirements 3.2 and Design 2.1).
- **Measuring and stopping at the target [1.2, 2.2, 2.3, 6.4]:** My board sends the preset to Troy's board (RF6, RF5) and the run command to Clay's board (RD4, RD3). It watches the weight status from Troy (RE1, RE0) and the flow status from Cole (RC7, RC6), and stops the pump when the target is reached. J1, J2, and J3 follow the class ribbon standard with pin 8 as ground and no power pin. Pins 1-2 are always my outputs and pins 3-4 are always the teammate's outputs back to me.
- **No unintended dispensing [2.6]:** The ribbon outputs start low, so the pump command is 00 (stop) at power-up. Each output goes through a 1N5817 diode (D7-D10) with a 10k pull-down on the cable side (R30-R33), so the line reads low when my pin is low, and current can't flow back from a teammate's board into my PIC pin. R26-R29 are 100k pull-downs on my four ribbon inputs, so an unplugged cable reads 00 (no flow or not ready) instead of floating, and the pump won't run.
- **Repeat fills [2.4]:** After a fill is done, the firmware goes back to picking a preset without a restart.
- **Debugging:** There's a debug LED (D1 on RF2), a debug button (SW5 on RF4), the JP1 and JP2 jumpers, and 7 test points on the power rails and the cup sensor (TP2-TP5, TP7-TP9). The J5 header has +5V, GND, and 8 spare Nano pins, and the other 14 spare pins go to test pads (TP18-TP31) for fixes later.
- **Part numbers and ERC:** Every part I have to buy has its manufacturer part number in the KiCad file. ERC shows 0 errors and 0 warnings.

## Ribbon Cables

| Header | Teammate | Pin 1 | Pin 2 | Pin 3 | Pin 4 | Pins 5-7 | Pin 8 |
|---|---|---|---|---|---|---|---|
| J1 | Cole (flow) | NC | NC | Flow S1 in (RC7) | Flow S0 in (RC6) | NC | GND |
| J2 | Clay (pump) | Pump C1 out (RD4, through D7) | Pump C0 out (RD3, through D8) | NC | NC | NC | GND |
| J3 | Troy (weight) | Weight C1 out (RF6, through D9) | Weight C0 out (RF5, through D10) | Weight S1 in (RE1) | Weight S0 in (RE0) | NC | GND |

There are no jumpers on the ribbon lines anymore. To cut off a teammate's board, I unplug its cable.

J1-J3 are 2x4 IDC box headers (Wurth 61200821621). In the schematic they use the counter-clockwise 2x4 symbol that the team agreed on (Cole, Nov 3). The pin numbers and signals above didn't change.

## Signal Codes

| Signal | 00 | 01 | 10 | 11 |
|---|---|---|---|---|
| Pump command (to Clay) | Stop | Run | Not used (stop) | Not used (stop) |
| Weight command (to Troy) | Preset 1 | Preset 2 | Preset 3 | Preset 4 |
| Weight status (from Troy) | Not ready | Below target | Target reached | Error |
| Flow status (from Cole) | No flow | Flowing | Not used (no flow) | Sensor fault |

## Changes in Rev 7

- Took out the 16x2 LCD (DS1) with its J7 socket, RV1 contrast pot, JP5 backlight jumper, and R24 (the LCD E pull-down). C7, C14, C15, and C16 came out too. The old LCD pins (RC0-RC5) are spare pins now.
- Took out the second expansion header (J6), the remote button header (J9), the ribbon jumpers (JP3, JP4, JP6-JP11), and test points TP1, TP6, and TP10-TP17.
- J5 is now a 2x5 header with +5V, GND, and 8 spare pins. The other 14 spare pins go to new test pads TP18-TP31.
- Added D7-D10 (1N5817) and R30-R33 (10k pull-downs) on the four ribbon outputs.
- ERC shows 0 errors and 0 warnings.

## Changes in Rev 6

No connections changed (the Rev 6 netlist matches Rev 5). I moved the footprints into my own NB footprint library, gave U1 a Curiosity Nano socket footprint, and added a footprint for the HS1 heat sink so it shows up on the PCB.

## Changes in Rev 5

The LM1086 regulator was backordered, so U2 is now the ST LD1085V50 (same TO-220 pinout and the same 4.9 to 5.1V output). J1-J3 now use the counter-clockwise 2x4 connector symbol, and C4's part number is now the KYOCERA AVX TAP106K016SCS that I ordered. No connections changed: the Rev 5 netlist matches Rev 4, and ERC shows 0 errors and 0 warnings.

## Changes in Rev 4

After the design review I cleaned up the schematic without adding or removing any parts: the 9V LED branch and the fuse output now use a VIN power arrow instead of a long wire, and the 100k pull-downs (R26-R29) sit right on their ribbon lines next to J1 and J3 instead of being joined by net labels from another section. I also renamed the spare Nano nets so they don't look like UART (GPIO_RF0, GPIO_RF1, GPIO_RF3, DBG_BTN_RF4) and moved the signal codes into one note in the ribbon section.

## Files

- [Schematic PDF (Rev 7)](Nikita-Main-Control-Schematic.pdf)
- [Schematic image (Rev 7)](Nikita-Main-Control-Schematic.png)
- [KiCad project ZIP (Rev 7)](EGR304_Main_Control_Nikita_Rev7.zip)
