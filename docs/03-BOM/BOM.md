---
title: Bill of Materials
---

# Bill of Materials

## Overview

This is the full parts list for my Main Control Board. Every part in my schematic has its manufacturer part number saved in the KiCad file (the MPN field), so this table matches the schematic, the block diagram, and my Component Selection page. Prices are DigiKey prices for one piece (checked October 2026).

One board costs about **$65.38** in parts (97 parts on 42 lines), including the 9V wall adapter. The PCB itself isn't included yet.

## Bill of Materials

*Table 1: Main Control Board bill of materials*

| Part | Qty | Unit Cost | Total Cost | Manufacturer | Manufacturer # (DigiKey link) | Schematic Reference |
|---|---|---|---|---|---|---|
| Curiosity Nano board (PIC18F57Q43) | 1 | $10.61 | $10.61 | Microchip | [DM164150](https://www.digikey.com/en/products/detail/microchip-technology/DM164150/11586705) | U1 |
| 5V 1.5A linear regulator, TO-220 | 1 | $2.58 | $2.58 | Texas Instruments | [LM1086IT-5.0/NOPB](https://www.digikey.com/en/products/detail/texas-instruments/LM1086IT-5-0-NOPB/363580) | U2 |
| TO-220 heat sink | 1 | $2.24 | $2.24 | Same Sky | [HSE14-384225P](https://www.digikey.com/en/products/detail/same-sky-formerly-cui-devices/HSE14-384225P/26460932) | U2 |
| TO-220 insulating thermal pad | 1 | $0.35 | $0.35 | Bergquist | [SP900S-0.009-00-104](https://www.digikey.com/en/products/result?keywords=SP900S-0.009-00-104) | U2 |
| Dual op amp, 8-pin DIP | 1 | $0.45 | $0.45 | Microchip | [MCP6002-I/P](https://www.digikey.com/en/products/detail/microchip-technology/MCP6002-I-P/500875) | U3 |
| 16x2 character LCD | 1 | $7.83 | $7.83 | Newhaven Display | [NHD-0216K1Z-FL-YBW](https://www.digikey.com/en/products/detail/newhaven-display-intl/NHD-0216K1Z-FL-YBW/1701171) | DS1 |
| 16-pin male header for the LCD | 1 | $0.28 | $0.28 | Sullins | [PRPC016SAAN-RC](https://www.digikey.com/en/products/result?keywords=PRPC016SAAN-RC) | DS1 |
| Photoresistor (cup sensor) | 1 | $0.72 | $0.72 | Advanced Photonix | [PDV-P8103](https://www.digikey.com/en/products/detail/advanced-photonix/PDV-P8103/480610) | LDR1 |
| 9V 2A wall adapter | 1 | $12.43 | $12.43 | Triad Magnetics | [WSU090-2000](https://www.digikey.com/en/products/detail/triad-magnetics/WSU090-2000/3094951) | off-board |
| DC barrel jack | 1 | $0.77 | $0.77 | Same Sky | [PJ-102AH](https://www.digikey.com/en/products/detail/same-sky-formerly-cui-devices/PJ-102AH/408448) | J4 |
| Fuse, T800mA 250V, 5x20mm time-lag | 1 | $1.56 | $1.56 | Littelfuse | [0218.800MXP](https://www.digikey.com/en/products/result?keywords=0218.800MXP) | F1 |
| 5x20mm fuse holder, PCB | 1 | $1.36 | $1.36 | Schurter | [0031.8201](https://www.digikey.com/en/products/result?keywords=0031.8201) | F1 |
| 2x4 box header (ribbon) | 3 | $1.03 | $3.09 | Wurth Elektronik | [61200821621](https://www.digikey.com/en/products/detail/w%C3%BCrth-elektronik/61200821621/4846916) | J1, J2, J3 |
| 2x8 pin header (spare pins) | 2 | $0.28 | $0.56 | Sullins | [PRPC008DAAN-RC](https://www.digikey.com/en/products/result?keywords=PRPC008DAAN-RC) | J5, J6 |
| 1x16 socket (LCD) | 1 | $0.93 | $0.93 | Sullins | [PPTC161LFBN-RC](https://www.digikey.com/en/products/result?keywords=PPTC161LFBN-RC) | J7 |
| 1x3 pin header (cup sensor) | 1 | $0.10 | $0.10 | Sullins | [PRPC003SAAN-RC](https://www.digikey.com/en/products/result?keywords=PRPC003SAAN-RC) | J8 |
| 1x5 pin header (remote buttons) | 1 | $0.11 | $0.11 | Sullins | [PRPC005SAAN-RC](https://www.digikey.com/en/products/result?keywords=PRPC005SAAN-RC) | J9 |
| 1x2 pin header (jumper) | 11 | $0.10 | $1.10 | Sullins | [PRPC002SAAN-RC](https://www.digikey.com/en/products/result?keywords=PRPC002SAAN-RC) | JP1-JP11 |
| Jumper shunt | 11 | $0.10 | $1.10 | Sullins | [SPC02SYAN](https://www.digikey.com/en/products/result?keywords=SPC02SYAN) | JP1-JP11 |
| Tactile push button | 5 | $0.35 | $1.75 | Omron (now Aratas) | [B3F-1000](https://www.digikey.com/en/products/result?keywords=B3F-1000) | SW1-SW5 |
| 10k trimmer pot (LCD contrast) | 1 | $2.53 | $2.53 | Bourns | [3296W-1-103LF](https://www.digikey.com/en/products/result?keywords=3296W-1-103LF) | RV1 |
| LED, red, 0805 (debug) | 1 | $0.16 | $0.16 | Lite-On | [LTST-C171KRKT](https://www.digikey.com/en/products/result?keywords=LTST-C171KRKT) | D1 |
| LED, yellow, 5 mm (Dispensing) | 1 | $0.23 | $0.23 | Kingbright | [WP7113YD](https://www.digikey.com/en/products/result?keywords=WP7113YD) | D2 |
| LED, green, 5 mm (Done) | 1 | $0.23 | $0.23 | Kingbright | [WP7113GD](https://www.digikey.com/en/products/result?keywords=WP7113GD) | D3 |
| LED, red, 5 mm (Fault) | 1 | $0.16 | $0.16 | Wurth Elektronik | [151051RS11000](https://www.digikey.com/en/products/result?keywords=151051RS11000) | D4 |
| LED, green, 0805 (power) | 2 | $0.15 | $0.30 | Lite-On | [LTST-C171GKT](https://www.digikey.com/en/products/result?keywords=LTST-C171GKT) | D5, D6 |
| Resistor 2.2k 1% 0.125W, 0805 | 2 | $0.10 | $0.20 | Yageo | [RC0805FR-072K2L](https://www.digikey.com/en/products/result?keywords=RC0805FR-072K2L) | R1, R4 |
| Resistor 10k 1% 0.125W, 0805 | 2 | $0.10 | $0.20 | Yageo | [RC0805FR-0710KL](https://www.digikey.com/en/products/result?keywords=RC0805FR-0710KL) | R2, R3 |
| Resistor 4.7k 1% 0.125W, 0805 | 1 | $0.10 | $0.10 | Yageo | [RC0805FR-074K7L](https://www.digikey.com/en/products/result?keywords=RC0805FR-074K7L) | R25 |
| Resistor 10k 1% 0.25W, axial | 12 | $0.10 | $1.20 | Yageo | [MFR-25FRF52-10K](https://www.digikey.com/en/products/result?keywords=MFR-25FRF52-10K) | R5-R8, R11-R18 |
| Resistor 30k 1% 0.25W, axial | 1 | $0.10 | $0.10 | Yageo | [MFR-25FRF52-30K](https://www.digikey.com/en/products/result?keywords=MFR-25FRF52-30K) | R9 |
| Resistor 1k 1% 0.25W, axial | 1 | $0.11 | $0.11 | Yageo | [MFR-25FRF52-1K](https://www.digikey.com/en/products/result?keywords=MFR-25FRF52-1K) | R10 |
| Resistor 2.2k 1% 0.25W, axial | 3 | $0.10 | $0.30 | Yageo | [MFR-25FRF52-2K2](https://www.digikey.com/en/products/result?keywords=MFR-25FRF52-2K2) | R19, R20, R21 |
| Resistor 100k 1% 0.25W, axial | 5 | $0.11 | $0.55 | Yageo | [MFR-25FRF52-100K](https://www.digikey.com/en/products/result?keywords=MFR-25FRF52-100K) | R24, R26-R29 |
| Capacitor 1uF 25V X7R, 0805 | 1 | $0.28 | $0.28 | Yageo | [CC0805KKX7R8BB105](https://www.digikey.com/en/products/result?keywords=CC0805KKX7R8BB105) | C1 |
| Capacitor 0.1uF 25V X7R, 0805 | 1 | $0.10 | $0.10 | Samsung | [CL21B104KACNNNC](https://www.digikey.com/en/products/result?keywords=CL21B104KACNNNC) | C2 |
| Capacitor 10uF 25V aluminum, radial | 1 | $0.21 | $0.21 | KEMET | [ESK106M025AC3AA](https://www.digikey.com/en/products/result?keywords=ESK106M025AC3AA) | C3 |
| Capacitor 10uF 16V tantalum, radial | 1 | $4.10 | $4.10 | KEMET | [T350E106K016AT](https://www.digikey.com/en/products/result?keywords=T350E106K016AT) | C4 |
| Capacitor 0.1uF 50V X7R, radial | 1 | $0.27 | $0.27 | TDK | [FG18X7R1H104KNT06](https://www.digikey.com/en/products/result?keywords=FG18X7R1H104KNT06) | C5 |
| Capacitor 0.1uF 25V X7R, radial | 3 | $0.59 | $1.77 | KEMET | [C320C104K3R5TA](https://www.digikey.com/en/products/result?keywords=C320C104K3R5TA) | C6, C14, C16 |
| Capacitor 1uF 25V X7R, radial | 6 | $0.33 | $1.98 | TDK | [FG18X7R1E105KRT06](https://www.digikey.com/en/products/result?keywords=FG18X7R1E105KRT06) | C7, C8, C10-C13 |
| Capacitor 10uF 16V aluminum, radial | 2 | $0.19 | $0.38 | KEMET | [ESK106M016AC3AA](https://www.digikey.com/en/products/result?keywords=ESK106M016AC3AA) | C9, C15 |
| **Total** | **97** | | **$65.38** | | | |

## Notes

- TP1-TP17 are bare test pads on the PCB, so they don't need a part.
- JP1-JP11 are 2-pin headers with a jumper shunt on each, so the shunts are their own line.
- The LCD plugs into J7, a 16-pin socket, so the LCD gets a 16-pin male header soldered on.
- The screw, nut, and shoulder washer that hold U2 on its heat sink aren't picked yet.
- How the Nano attaches to the PCB (sockets or soldered headers) gets picked with the PCB layout.
- The ribbon cables between boards are shared by the team, so they aren't on my BOM.
- The Omron B3F switch line is now sold under the Aratas name on DigiKey. The part number didn't change.
