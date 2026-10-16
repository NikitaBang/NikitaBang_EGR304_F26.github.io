---
title: Power Budget
---

# Power Budget

## Overview

This power budget checks that my 9V adapter and 5V regulator can run everything on my Main Control Board at the same time, with a 25% safety margin. It only covers my board, since each teammate has their own adapter and regulator. I used the class power budget template, and everything runs off one 5V rail.

## A. Major Components

| Component | Part number | Supply voltage | Qty | Max current (mA) | Total (mA) |
|---|---|---|---|---|---|
| Curiosity Nano (PIC18F57Q43) | DM164150 | 1.8 to 5.5V | 1 | 170.000 | 170.000 |
| Dual op amp | MCP6002-I/P | 1.8 to 6.0V | 1 | 0.856 | 0.856 |
| LCD logic | NHD-0216K1Z-FL-YBW | 4.5 to 5.5V | 1 | 3.000 | 3.000 |
| LCD backlight | NHD-0216K1Z-FL-YBW | 4.9 to 5.1V | 1 | 156.000 | 156.000 |
| Cup sensor (LDR + 10k) | PDV-P8103 | 5V | 1 | 0.516 | 0.516 |
| **Subtotal** | | | | | **330.372** |

## B. 5V Rail

| Load | Total (mA) |
|---|---|
| Major components from Section A | 330.372 |
| 2.5V reference divider (two 10k) | 0.258 |
| LCD E pull-down (100k) | 0.052 |
| LCD contrast pot (10k) | 0.638 |
| 3 status LEDs (2.2k each) | 7.026 |
| 4 button pull-ups (10k each) | 2.061 |
| 2 I2C pull-ups (4.7k each) | 2.193 |
| **Total** | **342.600** |
| Safety margin | 25% |
| **Total with margin** | **428.250** |

## C. Regulator

| Regulator | Part number | Max current (mA) | Needed (mA) | Remaining (mA) |
|---|---|---|---|---|
| 5V linear regulator | TI LM1086IT-5.0/NOPB | 1,500 | 428.250 | **1,071.750** |

## D. Power Source

| Power source | Part number | Output | Max current (mA) | Regulator connected (mA) | Remaining (mA) |
|---|---|---|---|---|---|
| Wall adapter | Triad WSU090-2000 | 9V | 2,000 | 1,500 (LM1086) | **500** |

My real draw from the adapter is 438.250mA (428.250mA plus 10mA for the regulator itself), so there's a lot of room left.

## E. Battery Life

N/A. My board runs off a wall adapter.

## Conclusions

The 2A adapter and the LM1086 can easily power everything on my board with the 25% margin, and nothing comes out negative. The biggest load is the LCD backlight. The regulator turns about 2W into heat, so it gets a heat sink, which keeps it around 71 C (its limit is 125 C).

Microchip only lists the PIC's max current at 3V, not 5V, so I used a safe upper estimate of 170mA for the Nano. The real number should be a lot lower, and I'll measure the actual board current once it's built.

## Resources

The full power budget spreadsheet is [here](Fill-A-Bot-Main-Control-Power-Budget.xlsx), and a PDF of this page is [here](Power-Budget.pdf).

Datasheets used: [LM1086](https://www.ti.com/lit/ds/symlink/lm1086.pdf), [Triad WSU090-2000](https://catalog.triadmagnetics.com/Asset/WSU090-2000.pdf), [NHD-0216K1Z-FL-YBW LCD](https://newhavendisplay.com/content/specs/NHD-0216K1Z-FL-YBW.pdf), [MCP6002](https://ww1.microchip.com/downloads/en/DeviceDoc/MCP6001-1R-1U-2-4-1-MHz-Low-Power-Op-Amp-DS20001733L.pdf), [PIC18F57Q43](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/PIC18F27-47-57Q43-Microcontroller-Data-Sheet-XLP-DS40002147.pdf), [PDV-P8103](https://media.digikey.com/pdf/data%20sheets/photonic%20detetectors%20inc%20pdfs/pdv-p8103.pdf), [HSE14-384225P heat sink](https://www.sameskydevices.com/product/resource/hse14-384225p.pdf).
