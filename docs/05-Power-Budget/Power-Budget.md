---
title: Power Budget
---

# Power Budget

This checks that my 9V adapter and 5V regulator can run everything on my board at once, with a 25% safety margin. It only covers my board, since each teammate has their own adapter and regulator. I used the class template. Everything runs off 5V except the 9V power LED (D6), which is before the regulator.

I made this budget in Rev 5, when the board still had the 16x2 LCD. Rev 7 took the LCD off. The LCD lines below (logic, backlight, and contrast pot) add up to about 160mA, so the real Rev 7 current is a lot lower. The new 10k pull-downs on the ribbon outputs add less than 2mA.

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
| 100k pull-downs driven high: LCD E (R24) plus my 4 ribbon outputs into teammates' 100k pull-downs | 0.260 |
| LCD contrast pot (10k) | 0.638 |
| 3 status LEDs (2.2k each) | 7.026 |
| 5 button pull-ups (10k each, includes the debug button) | 2.576 |
| Debug LED and 5V power LED (2.2k each) | 4.684 |
| **Total** | **345.814** |
| Safety margin | 25% |
| **Total with margin** | **432.268** |

## C. Regulator

| Regulator | Part number | Max current (mA) | Needed (mA) | Remaining (mA) |
|---|---|---|---|---|
| 5V linear regulator | TI LM1086IT-5.0/NOPB | 1,500 | 432.268 | **1,067.732** |

## D. Power Source

| Power source | Part number | Output | Max current (mA) | Regulator connected (mA) | Remaining (mA) |
|---|---|---|---|---|---|
| Wall adapter | Triad WSU090-2000 | 9V | 2,000 | 1,500 (LM1086) | **500** |

My real draw from the adapter is 444.299mA (432.268mA, plus 10mA for the regulator, plus 2.031mA for the 9V LED), so there's lots of room left.

U2 is now the ST LD1085V50 because the LM1086 was backordered. I left the table as it was. The LD1085V50 is rated for 3A, so now the 2A adapter is the limit, and that still leaves about 1.5A.

## E. Battery Life

N/A. My board runs off a wall adapter.

## Conclusions

The adapter and regulator can easily power everything with the 25% margin, and nothing comes out negative. The regulator turns about 2W into heat at this load, so it has a heat sink. With the LD1085V50 that keeps it around 69 C (the limit is 125 C).

Microchip only lists the PIC's max current at 3V, not 5V, so I used 170mA for the Nano to be safe. The real number should be a lot lower. I'll measure the board current through JP1 once it's built.

## Resources

The spreadsheet is [here](Power_Budget_Nikita_Bangiyev.xlsx) and a PDF of this page is [here](Power-Budget.pdf).

Datasheets used: [LM1086](https://www.ti.com/lit/ds/symlink/lm1086.pdf), [LD1085](https://www.st.com/resource/en/datasheet/ld1085.pdf), [Triad WSU090-2000](https://catalog.triadmagnetics.com/Asset/WSU090-2000.pdf), [NHD-0216K1Z-FL-YBW LCD](https://newhavendisplay.com/content/specs/NHD-0216K1Z-FL-YBW.pdf), [MCP6002](https://ww1.microchip.com/downloads/en/DeviceDoc/MCP6001-1R-1U-2-4-1-MHz-Low-Power-Op-Amp-DS20001733L.pdf), [PIC18F57Q43](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/PIC18F27-47-57Q43-Microcontroller-Data-Sheet-XLP-DS40002147.pdf), [PDV-P8103](https://media.digikey.com/pdf/data%20sheets/photonic%20detetectors%20inc%20pdfs/pdv-p8103.pdf), [HSE14-384225P heat sink](https://www.sameskydevices.com/product/resource/hse14-384225p.pdf).
