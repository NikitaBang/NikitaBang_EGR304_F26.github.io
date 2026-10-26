---
title: Appendix
---

# Appendix

Extra info that supports the main pages.

## Ribbon Wiring for All Four Boards

On Oct 22 our team dropped UART and I2C between boards. Each signal is now 2 plain digital wires (4 states), and 00 is the safe default. The ribbon cable is straight through, so pin 1 on my header is pin 1 on the teammate's header. This is what each board has to wire to match my board.

| Ribbon pin | Cole (flow, J1) | Clay (pump, J2) | Troy (weight, J3) |
|---|---|---|---|
| 1 | Not used | Pump command C1 in (from my RD4) | Weight command C1 in (from my RF6) |
| 2 | Not used | Pump command C0 in (from my RD3) | Weight command C0 in (from my RF5) |
| 3 | Flow status S1 out (to my RC7) | Not used | Weight status S1 out (to my RE1) |
| 4 | Flow status S0 out (to my RC6) | Not used | Weight status S0 out (to my RE0) |
| 5-7 | Not used | Not used | Not used |
| 8 | GND | GND | GND |

- All boards use 5V logic.
- Every input gets a 100k pull-down, so an unplugged cable reads 00.
- Every output starts low (00) at power-up.
- There's no power pin on the ribbon.

## Main Board States

This is the plan for my board's firmware, based on Cole's software flow chart. It's a draft and the timing numbers will be tuned on the real boards.

| State | Pump command | Weight command | What it's waiting for | Goes to |
|---|---|---|---|---|
| Idle / select preset | 00 (stop) | Preset 1-4 | UP / DOWN change the preset. START with a cup in place and weight status 01 | Filling |
| Filling | 01 (run) | Preset (locked) | Weight status 10 | Done |
| | | | No flow (flow status not 01) for 3 seconds, or flow status 11 | Error |
| | | | STOP pressed, or the cup is removed | Cancel |
| Error (no flow) | 00 (stop) | Preset | Fault LED flashes until STOP is pressed | Idle |
| Done / reset | 00 (stop) | Preset | Shows Finished for 3 seconds | Idle |
| Cancel | 00 (stop) | Preset | Shows Canceled for 1 second | Idle |

STOP cancels from any state. A weight status of 11 (error) also goes to the error state, with a different message on the LCD. The ribbon inputs only count once they read the same 3 times in a row (10 ms apart), so a read in the middle of a change gets ignored. The container weight is hard-coded on Troy's board for the demo.

## Revision History

| Rev | Date | Changes |
|---|---|---|
| 1 | Oct 19, 2026 | First schematic (UART ribbon) |
| 2 | Oct 25, 2026 | Footprints, 9V power LED (R25, D6), LCD notes |
| 3 | Oct 25, 2026 | 2-wire, 4-state ribbon signals, 100k pull-downs on the ribbon inputs, jumpers and test points on every ribbon signal, manufacturer part numbers on every part |
