---
title: Bill of Materials
---

# Bill of Materials

**Main Control Board, Fill-A-Bot (schematic Rev 4).** Nikita Bangiyev, EGR 304, Oct 30, 2026.

Every part on the schematic is listed, grouped by value, along with the hardware for debugging and expansion: jumpers and shunts, test points, sockets, headers and the fuse holder. Order quantity = 1 for the breadboard + 1 for the PCB + 1-2 spares. Parts from Peralta 109 or the class kit, and parts I already own, are listed at $0. No parts are smaller than 0805, and there are no new breakout modules.

**DigiKey order: 23 BOM lines (22 cart lines, since C3 and C9/C15 use the same part), $47.78** before tax and shipping, under the $60 budget per team member. DigiKey cart link: [DigiKey cart](https://www.digikey.com/short/bt910f3t)

| # | Ref | Description | Manufacturer | MPN | Vendor | Vendor Part # | Qty/Board | Order Qty | Unit | Ext. | Notes |
|---|---|---|---|---|---|---|---|---|---|---|---|
| 1 | U2 | 5V 1.5A linear regulator, TO-220 | Texas Instruments | [LM1086IT-5.0/NOPB](https://www.digikey.com/en/products/detail/texas-instruments/LM1086IT-5-0-NOPB/363580) | DigiKey | LM1086IT-5.0/NOPB-ND | 1 | 3 | $2.44 | $7.32 | Was out of stock at DigiKey on Oct 30. If it is not restocked, get it from Peralta or use an alternate. |
| 2 | U2 (heat sink) | TO-220 heat sink | Same Sky | [HSE14-384225P](https://www.digikey.com/en/products/detail/same-sky-formerly-cui-devices/HSE14-384225P/26460932) | DigiKey | 2223-HSE14-384225P-ND | 1 | 2 | $2.24 | $4.48 | Not a schematic symbol. |
| 3 | U2 (pad) | TO-220 insulating thermal pad | Bergquist | [SP900S-0.009-00-104](https://www.digikey.com/en/products/detail/bergquist/SP900S-0-009-00-104/307800) | DigiKey | BER178-ND | 1 | 3 | $0.35 | $1.05 | U2 tab is at 5V, so it needs an insulator. |
| 4 | U3 | Dual op amp, 8-pin DIP | Microchip | [MCP6002-I/P](https://www.digikey.com/en/products/detail/microchip-technology/MCP6002-I-P/500875) | DigiKey | MCP6002-I/P-ND | 1 | 3 | $0.45 | $1.35 | U3A/B/C are one package. |
| 5 | DS1 | 16x2 character LCD, 5V, yellow-green backlight | Newhaven Display | [NHD-0216K1Z-FL-YBW](https://www.digikey.com/en/products/detail/newhaven-display-intl/NHD-0216K1Z-FL-YBW/1701171) | DigiKey | NHD-0216K1Z-FL-YBW-ND | 1 | 1 | $7.83 | $7.83 | Plugs into J7. |
| 6 | LDR1 | Photoresistor (cup sensor) | Advanced Photonix | [PDV-P8103](https://www.digikey.com/en/products/detail/advanced-photonix/PDV-P8103/480610) | DigiKey | PDV-P8103-ND | 1 | 3 | $0.77 | $2.31 | Off-board on J8. |
| 7 | F1 (holder) | 5x20 mm fuse holder, PCB | Schurter | [0031.8201](https://www.digikey.com/en/products/detail/schurter-inc/0031-8201/669925) | DigiKey | 486-1258-ND | 1 | 2 | $1.36 | $2.72 | Matches the KiCad footprint. In stock. |
| 8 | J1, J2, J3 | 2x4 box header, 2.54 mm (ribbon to teammates) | Wurth Elektronik | [61200821621](https://www.digikey.com/en/products/detail/w%C3%BCrth-elektronik/61200821621/4846916) | DigiKey | 732-5395-ND | 3 | 4 | $1.03 | $4.12 | Ribbon cables are shared by the team. |
| 9 | J7 | 1x16 female socket, 2.54 mm (LCD) | Sullins | [PPTC161LFBN-RC](https://www.digikey.com/en/products/detail/sullins-connector-solutions/PPTC161LFBN-RC/810154) | DigiKey | S7014-ND | 1 | 2 | $0.93 | $1.86 |  |
| 10 | JP1-JP11 (shunts) | Jumper shunt, 2.54 mm | Sullins | [SPC02SYAN](https://www.digikey.com/en/products/detail/sullins-connector-solutions/SPC02SYAN/76375) | DigiKey | S9001-ND | 11 | 12 | $0.03 | $0.36 | Extra spares because shunts get lost. |
| 11 | RV1 | 10k trimmer pot, 25-turn (LCD contrast) | Bourns | [3296W-1-103LF](https://www.digikey.com/en/products/detail/bourns-inc/3296W-1-103LF/1088045) | DigiKey | 3296W-103LF-ND | 1 | 2 | $2.53 | $5.06 |  |
| 12 | D1 | LED red 0805 | Lite-On | [LTST-C171KRKT](https://www.digikey.com/en/products/detail/liteon/LTST-C171KRKT/386801) | DigiKey | 160-1427-1-ND | 1 | 2 | $0.16 | $0.32 |  |
| 13 | D2 | LED yellow 5 mm | Kingbright | [WP7113YD](https://www.digikey.com/en/products/result?keywords=WP7113YD) | DigiKey | 754-1264-ND | 1 | 3 | $0.23 | $0.69 | Oct 25 price. |
| 14 | D5, D6 | LED green 0805 | Lite-On | [LTST-C171GKT](https://www.digikey.com/en/products/detail/liteon/LTST-C171GKT/386793) | DigiKey | 160-1423-1-ND | 2 | 3 | $0.15 | $0.45 |  |
| 15 | R1, R4 | Resistor 2.2k 1% 1/8W 0805 | Yageo | [RC0805FR-072K2L](https://www.digikey.com/en/products/detail/yageo/RC0805FR-072K2L/727676) | DigiKey | 311-2.20KCRCT-ND | 2 | 3 | $0.10 | $0.30 |  |
| 16 | R2, R3 | Resistor 10k 1% 1/8W 0805 | Yageo | [RC0805FR-0710KL](https://www.digikey.com/en/products/detail/yageo/RC0805FR-0710KL/727535) | DigiKey | 311-10.0KCRCT-ND | 2 | 3 | $0.10 | $0.30 |  |
| 17 | R25 | Resistor 4.7k 1% 1/8W 0805 | Yageo | [RC0805FR-074K7L](https://www.digikey.com/en/products/detail/yageo/RC0805FR-074K7L/727929) | DigiKey | 311-4.70KCRCT-ND | 1 | 2 | $0.10 | $0.20 |  |
| 18 | C2 | Cap 0.1uF 25V X7R 0805 | Samsung | [CL21B104KACNNNC](https://www.digikey.com/en/products/detail/samsung-electro-mechanics/CL21B104KACNNNC/3886757) | DigiKey | 1276-1099-1-ND | 1 | 2 | $0.10 | $0.20 |  |
| 19 | C1 | Cap 1uF 25V X7R 0805 | Yageo | [CC0805KKX7R8BB105](https://www.digikey.com/en/products/detail/yageo/CC0805KKX7R8BB105/2833621) | DigiKey | 311-1456-1-ND | 1 | 2 | $0.28 | $0.56 |  |
| 20 | C7, C8, C10-C13 | Cap 1uF 25V X7R radial | TDK | [FG18X7R1E105KRT06](https://www.digikey.com/en/products/detail/tdk/FG18X7R1E105KRT06/5802875) | DigiKey | 445-173261-1-ND | 6 | 13 | $0.20 | $2.55 | Button debounce caps. |
| 21 | C3 | Cap 10uF 25V aluminum radial | KEMET | [ESK106M025AC3AA](https://www.digikey.com/en/products/detail/kemet/ESK106M025AC3AA/18167956) | DigiKey | 399-ESK106M025AC3AA-ND | 1 | 3 | $0.21 | $0.63 |  |
| 22 | C9, C15 | Cap 10uF 25V aluminum radial (16V min) | KEMET | [ESK106M025AC3AA](https://www.digikey.com/en/products/detail/kemet/ESK106M025AC3AA/18167956) | DigiKey | 399-ESK106M025AC3AA-ND | 2 | 5 | $0.21 | $1.05 | 25V part, same footprint as C3. |
| 23 | C4 | Cap 10uF 16V tantalum radial | KYOCERA AVX | [TAP106K016SCS](https://www.digikey.com/en/products/detail/kyocera-avx/TAP106K016SCS/563942) | DigiKey | 478-1839-ND | 1 | 3 | $0.69 | $2.07 | In stock. 2.5 mm lead spacing; bend leads to fit the 5.0 mm footprint. |
| 24 | U1 | PIC18F57Q43 Curiosity Nano dev board | Microchip | [DM164150](https://www.digikey.com/en/products/detail/microchip-technology/DM164150/11586705) | Already owned | 150-DM164150-ND | 1 | 0 | $0.00 | $0.00 | Already owned; not ordered. Plugs into female sockets. |
| 25 | TP1-TP17 | Test point, bare PCB pad | - | n/a | PCB (no part) | n/a | 17 | 0 | $0.00 | $0.00 | Nothing to buy. |
| 26 | DS1 (header) | 1x16 male header, 2.54 mm (on the LCD) | Sullins | [PRPC016SAAN-RC](https://www.digikey.com/en/products/detail/sullins-connector-solutions/PRPC016SAAN-RC/2775238) | Peralta | 35-PRPC016SAAN-RC-ND | 1 | 2 | $0.00 | $0.00 | From Peralta 109 stock, $0. |
| 27 | J5, J6 | 2x8 male header, 2.54 mm (expansion) | Sullins | [PRPC008DAAN-RC](https://www.digikey.com/en/products/detail/sullins-connector-solutions/PRPC008DAAN-RC/2775286) | Peralta | 35-PRPC008DAAN-RC-ND | 2 | 3 | $0.00 | $0.00 | From Peralta 109 stock, $0. |
| 28 | J8 | 1x3 male header (cup sensor) | Sullins | [PRPC003SAAN-RC](https://www.digikey.com/en/products/detail/sullins-connector-solutions/PRPC003SAAN-RC/2775251) | Peralta | 35-PRPC003SAAN-RC-ND | 1 | 2 | $0.00 | $0.00 | From Peralta 109 stock, $0. |
| 29 | J9 | 1x5 male header (remote buttons) | Sullins | [PRPC005SAAN-RC](https://www.digikey.com/en/products/detail/sullins-connector-solutions/PRPC005SAAN-RC/2775249) | Peralta | 35-PRPC005SAAN-RC-ND | 1 | 2 | $0.00 | $0.00 | From Peralta 109 stock, $0. |
| 30 | JP1-JP11 | 1x2 male header (jumpers) | Sullins | [PRPC002SAAN-RC](https://www.digikey.com/en/products/detail/sullins-connector-solutions/PRPC002SAAN-RC/2775252) | Peralta | 35-PRPC002SAAN-RC-ND | 11 | 12 | $0.00 | $0.00 | From Peralta 109 stock, $0. |
| 31 | SW1-SW5 | Tactile push button 6x6 mm, THT | Omron (Aratas) | [B3F-1000](https://www.digikey.com/en/products/result?keywords=B3F-1000) | Peralta | SW400-ND | 5 | 11 | $0.00 | $0.00 | From Peralta 109 stock, $0. Oct 25 price. |
| 32 | D3 | LED green 5 mm | Kingbright | [WP7113GD](https://www.digikey.com/en/products/detail/kingbright/WP7113GD/1747662) | Peralta | 754-1263-ND | 1 | 3 | $0.00 | $0.00 | From Peralta 109 stock, $0. |
| 33 | D4 | LED red 5 mm | Wurth Elektronik | [151051RS11000](https://www.digikey.com/en/products/detail/w%C3%BCrth-elektronik/151051RS11000/4490012) | Peralta | 732-5016-ND | 1 | 3 | $0.00 | $0.00 | From Peralta 109 stock, $0. |
| 34 | R5-R8, R11-R18 | Resistor 10k 1% 1/4W axial | Yageo | [MFR-25FRF52-10K](https://www.digikey.com/en/products/result?keywords=MFR-25FRF52-10K) | Peralta | 13-MFR-25FRF52-10KCT-ND | 12 | 25 | $0.00 | $0.00 | From Peralta 109 stock, $0. Oct 25 price. |
| 35 | R10 | Resistor 1k 1% 1/4W axial | Yageo | [MFR-25FRF52-1K](https://www.digikey.com/en/products/detail/yageo/MFR-25FRF52-1K/12993) | Peralta | 13-MFR-25FRF52-1KCT-ND | 1 | 3 | $0.00 | $0.00 | From Peralta 109 stock, $0. |
| 36 | R19, R20, R21 | Resistor 2.2k 1% 1/4W axial | Yageo | [MFR-25FRF52-2K2](https://www.digikey.com/en/products/result?keywords=MFR-25FRF52-2K2) | Peralta | 13-MFR-25FRF52-2K2CT-ND | 3 | 7 | $0.00 | $0.00 | From Peralta 109 stock, $0. |
| 37 | R24, R26-R29 | Resistor 100k 1% 1/4W axial | Yageo | [MFR-25FRF52-100K](https://www.digikey.com/en/products/detail/yageo/MFR-25FRF52-100K/14630) | Peralta | 13-MFR-25FRF52-100KCT-ND | 5 | 11 | $0.00 | $0.00 | From Peralta 109 stock, $0. |
| 38 | C5 | Cap 0.1uF 50V X7R radial | TDK | [FG18X7R1H104KNT06](https://www.digikey.com/en/products/detail/tdk/FG18X7R1H104KNT06/5802879) | Peralta | 445-173265-1-ND | 1 | 3 | $0.00 | $0.00 | From Peralta 109 stock, $0. |
| 39 | C6, C14, C16 | Cap 0.1uF 25V X7R radial | KEMET | [C320C104K3R5TA](https://www.digikey.com/en/products/result?keywords=C320C104K3R5TA) | Peralta | 399-C320C104K3R5TA-ND | 3 | 7 | $0.00 | $0.00 | From Peralta 109 stock, $0. |
| 40 | J4 | DC barrel jack, 2.1 mm, PCB | Same Sky | PJ-102AH | Peralta | CP-102AH-ND | 1 | 2 | $0.00 | $0.00 | From Peralta 109 stock, $0. |
| 41 | F1 | Fuse, T800mA 250V, 5x20 mm time-lag | Littelfuse | 0218.800MXP | Peralta | F1744-ND | 1 | 4 | $0.00 | $0.00 | From Peralta 109 (5x20 800 mA), $0. Must be time-lag; if not, order F1744-ND at $1.56. |
| 42 | R9 | Resistor 30k 1% 1/4W axial | Yageo | MFR-25FRF52-30K | Peralta | 13-MFR-25FRF52-30KCT-ND | 1 | 4 | $0.00 | $0.00 | Was out of stock at DigiKey on Oct 30. Get it from the Peralta resistor stock or use an alternate. |
| 43 | U3 (socket) | 8-pin DIP IC socket | - | n/a | Peralta | n/a | 1 | 2 | $0.00 | $0.00 | From Peralta 109, $0. |
| 44 | U1 (sockets) | 1x40 female header, cut to 1x28 (Nano socket) | - | n/a | Peralta | n/a | 2 | 3 | $0.00 | $0.00 | From class stock, $0. |
| | | **DigiKey order total** | | | | | | | | **$47.78** | |

## Notes

- The EGR 304 budget is $60 per team member, so the order keeps 1 for the breadboard + 1 for the PCB + at most 1 spare. Lab-stock parts come from Peralta 109.
- The LCD and the Nano move from the breadboard to the PCB. The Curiosity Nano is already owned.
- Prices are DigiKey prices checked on Oct 30, 2026, except the lines marked "Oct 25 price".
- On Oct 30, DigiKey showed the LM1086 and the 30k resistor as out of stock. If they are not restocked, I will use Peralta stock or an alternate.
- The ribbon cables are shared by the team.
