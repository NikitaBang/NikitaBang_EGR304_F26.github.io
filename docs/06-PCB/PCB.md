---
title: PCB
---

# PCB

This is the PCB for my Main Control Board (Rev 7, November 9, 2026). It's a 2-layer board, 100 x 100 mm with chamfered corners, made in KiCad 10 from my [Rev 7 schematic](../04-Schematic/schematic.md).

![Main Control Board PCB layout](PCB_Layout.png){ width="100%" }

Figure 1: PCB layout with the top traces (red), bottom traces (blue), and silkscreen. The ground pours are hidden here so the traces are easy to see (click to enlarge).

![Main Control Board 3D view](PCB_3D.png){ width="100%" }

Figure 2: 3D view of the board from KiCad (click to enlarge)

![Top copper](PCB_Top_Copper.png){ width="49%" } ![Bottom copper](PCB_Bottom_Copper.png){ width="49%" }

Figure 3: Top copper (left) and bottom copper (right) with the ground pours. The bottom is shown from the bottom side, so it's mirrored (click to enlarge).

## Files

- [KiCad project ZIP (Rev 7)](EGR304_Main_Control_Nikita_Rev7.zip): schematic, PCB, my NB footprint library, symbols, and 3D models, so it opens on another PC with nothing missing
- [Gerber files ZIP](NikitaBangiyev201.zip): top and bottom copper, top and bottom solder mask, top and bottom silkscreen, board outline, and the plated and non-plated drill files
- [1:1 print (PDF)](PCB_1to1_Print.pdf): top and bottom copper at actual size, to check that the parts fit before the board is made
- [DRC screenshot](DRC_Confirmation.png)

## Design Rules

| Rule | Class rule | My board |
|---|---|---|
| Copper layers | 2 | 2 (top and bottom) |
| Board size | 100 x 100 mm max | 100 x 100 mm, 2 mm chamfer on each corner |
| Copper weight | 0.5 oz | 0.5 oz (0.0175 mm) |
| Clearance | 10 mil (0.254 mm) | 0.254 mm |
| Signal traces | 15 mil (0.381 mm) min | 0.381 mm |
| Power traces | 40 mil (1.016 mm), sized with a calculator | 1.016 mm on VIN_RAW, VIN, +5V_REG, and +5V |
| Annular ring | 15 mil (0.381 mm) min | 0.381 mm min |
| Vias | 19.7 mil (0.5 mm) drill | 32 vias, 1.3 mm pad, 0.5 mm drill |
| Copper to hole | 10 mil (0.254 mm) | 0.254 mm |
| Hole to hole | 31.5 mil (0.8 mm) | 0.8 mm (the closest pair on the board is 1.06 mm) |
| Solder mask clearance | 5 mil (0.127 mm) | 0.127 mm |

**Power trace width:** With the IPC-2221 trace width formula for an outside layer, a 40 mil trace in 0.5 oz copper can carry about 1.5A with a 10 C rise. My fuse is 800mA and my power budget is 432mA, so the 40 mil power traces have plenty of room. The 15 mil signal traces only carry a few mA.

## Layout

- **Power corner (top left):** The barrel jack (J4) is on the left edge, the fuse (F1) is right next to it, and U2 sits on its heat sink (HS1). There's a keepout on both layers so nothing is routed between the heat sink fins.
- **Curiosity Nano (middle):** U1 plugs into a 2x28 socket in the middle of the board. A keepout on both layers means only the socket pads and their escape traces are under the Nano.
- **Ribbon headers (right edge):** J1 (Cole), J2 (Clay), and J3 (Troy) are all on the top side along the right edge, so the three cables leave the board on one side and don't cross the buttons.
- **Buttons (bottom edge):** STOP, UP, DOWN, and START (SW4, SW1, SW2, SW3) are in one row along the bottom edge, where the user can reach them. The debug button (SW5) is off to the left side.
- **Status LEDs:** D2-D4 (Dispensing, Done, Fault) are in a row above the Nano. The power LEDs (D5, D6) are near the top of the board, next to the power test points.
- **Cup sensor:** J8 for the photoresistor is on the left edge, and the op amp and filter are below the Nano.
- **Bypass caps:** C2 is 5.3 mm from the Nano's VTG pin, C6 is 3.8 mm from the op amp's V+ pin, and the regulator caps (C3, C4, C5) are 5 to 7 mm from U2's pins.
- **Spare pins:** J5 is below the Nano, and the 14 test pads (TP18-TP31) are right next to the Nano pins they connect to.

## Ground and Routing

- **Ground:** There are no ground traces. Ground (Earth) is a copper pour on both sides with thermal reliefs, and islands are removed. All 49 ground pads connect through the pours.
- **Routing:** No autorouter was used. Every bend is 45 degrees. There's one T-junction left on FLOW_S1 near R26, because there's no room to move that branch without rerouting LED_DISP_N.
- **Vias:** 32 vias total.
- **Copper text:** My initials "NB" are on the top copper in a large bold font (6 mm tall, 1.2 mm stroke). "top" and "Fill-A-Bot Team 201" are on the top copper, and "bottom" and "Fill-A-Bot Team 201" are on the bottom copper. The bottom text is mirrored so it reads right from the bottom side. All copper text is at least 0.381 mm thick.
- **Footprints:** My custom footprints have NB in them and are in my NB footprint library (EGR304_Footprints_NB), which is included in the KiCad ZIP.

## DRC

DRC with "Refill all zones" and "Test for parity between PCB and schematic" turned on shows 0 errors, 0 unconnected items, and 0 schematic parity issues. The 13 warnings left are all silkscreen: the J1-J4 and HS1 outlines run to the board edge because those parts sit at the edge, and one LED outline is close to a test pad.

![DRC confirmation](DRC_Confirmation.png){ width="100%" }

Figure 4: DRC results with the board in the same frame (click to enlarge)

## Changes After the First Layout

- Fixed the traces on BTN_START_N, +5V, VREF_2V5, and WT_S0 that had sharp corners or T-junctions, and closed a tiny gap on GPIO_RB0.
- Made the NB on the top copper large and bold.
- Added 3D models for D7-D10 and J5 so they show up in the 3D view.
- Ran the Gerbers through the JLCPCB DFM check and cleaned up the silkscreen: the reference labels are inside their parts where they fit, and none of them sit on a pad or a via hole anymore.
- Set the solder mask clearance to 5 mil to match the class KiCad rules. This only changes the solder mask files, not the copper.
