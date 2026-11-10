---
title: Appendix
---

# Appendix

## Ribbon Wiring for All Four Boards

Each signal between boards is 2 plain wires (4 states), and 00 is the safe default. The ribbon is straight through, so pin 1 on my header is pin 1 on the teammate's header. This is what each board has to wire to match mine.

| Ribbon pin | Cole (flow, J1) | Clay (pump, J2) | Troy (weight, J3) |
|---|---|---|---|
| 1 | Not used | Pump command C1 in (from my RD4) | Preset C1 in (from my RF6) |
| 2 | Not used | Pump command C0 in (from my RD3) | Preset C0 in (from my RF5) |
| 3 | Flow status S1 out (to my RC7) | Not used | Weight status S1 out (to my RE1) |
| 4 | Flow status S0 out (to my RC6) | Not used | Weight status S0 out (to my RE0) |
| 5-7 | Not used | Not used | Not used |
| 8 | GND | GND | GND |

All boards use 5V logic. Every input has a 100k pull-down so an unplugged cable reads 00, and every output starts low at power-up. There's no power pin on the ribbon. My outputs go through a diode, so a high on my side shows up as about 4.7V.

## Main Board States

This is the plan for my firmware, based on Cole's flow chart. The timing numbers will get tuned on the real boards.

| State | Pump command | Preset | Waiting for | Goes to |
|---|---|---|---|---|
| Idle | 00 (stop) | Preset 1 or 2 | UP picks preset 1, DOWN picks preset 2. START with a cup in place and weight status 01 | Filling |
| Filling | 01 (run) | Locked | Weight status 10 | Done |
| | | | No flow for 3 seconds, or flow status 11 | Error |
| | | | STOP, or the cup is removed | Cancel |
| Error | 00 (stop) | Preset | Fault LED flashes until STOP | Idle |
| Done | 00 (stop) | Preset | Done LED stays on for 3 seconds | Idle |
| Cancel | 00 (stop) | Preset | LEDs off for 1 second | Idle |

STOP cancels from any state, and a weight status of 11 (error) also goes to Error. A ribbon input only counts once it reads the same 3 times in a row (10 ms apart), so a read in the middle of a change gets ignored. The container weight is hard-coded on Troy's board for the demo.

## Revision History

| Rev | Date | Changes |
|---|---|---|
| 1 | Oct 19, 2026 | First schematic (UART ribbon) |
| 2 | Oct 25, 2026 | Footprints, 9V power LED (R25, D6), LCD notes |
| 3 | Oct 25, 2026 | 2-wire ribbon signals, 100k pull-downs, jumpers and test points on the ribbon signals, part numbers on every part |
| 4 | Oct 30, 2026 | Cleanup after the design review, simpler block diagram |
| 5 | Nov 4, 2026 | Regulator changed to the LD1085V50, new ribbon connector symbol, new C4 part number |
| 6 | Nov 6, 2026 | Footprints moved into my NB library, Nano socket and heat sink footprints added |
| 7 | Nov 7, 2026 | LCD, J6, J9, and the ribbon jumpers removed. Diodes and pull-downs added on the ribbon outputs. J5 changed to 2x5 and spare pins sent to test pads |
| 7 (PCB) | Nov 9, 2026 | PCB finished: trace fixes, bigger NB, 3D models, silkscreen cleanup, 5 mil solder mask clearance |
