---
title: Power Budget
---

# Power Budget

Nikita Bangiyev, Team 201, Fill-A-Bot. Updated October 16, 2026.

## Overview

This power budget checks that my 9V adapter and 5V regulator can power everything on my Main Control Board at the same time, with a 25% safety margin. It only covers my board. Cole, Clay, and Troy each have their own adapter and regulator, so their loads are not in my budget.

My board has one power rail: a 9V wall adapter feeds an LM1086 5V linear regulator, and everything runs from that 5V rail. I followed the class [Power Budget Example](https://www.dropbox.com/s/wyeqisp0uzyiics/Power%20Budget%20Example.xlsx?dl=0) template (sections A to E). The full spreadsheet with formulas is in the [Downloads](#downloads) section.

**Results:**

- 5V load: 342.342mA before the margin, **427.928mA** with the 25% margin.
- LM1086 regulator (1,500mA): **1,072.072mA** left, and 792.072mA left before its thermal limit.
- Triad WSU090-2000 adapter (2,000mA): **500mA** left using the class template method, and 1,562.072mA left using the real input current of 437.928mA.
- Regulator junction: about **70.6 C** at a 40 C enclosure temperature. The limit is 125 C.
- Battery life: N/A (no battery).

## A. Major Components

These are the major components from my [Component Selection](../02-Component-Selection/Component-Selection.md) page that use power. Power sources and regulators are not listed here.

| Component | Part number | Supply range | Qty | Max current (mA) | Total (mA) | Value type |
|---|---|---|---|---|---|---|
| Curiosity Nano: PIC18F57Q43 plus board target circuits | DM164150 | 1.8 to 5.5V, 5V used | 1 | 170.000 | 170.000 | Derived ceiling |
| Dual op amp (U3A + U3B) with feedback load | MCP6002-I/P | 1.8 to 6.0V, 5V used | 1 | 0.856 | 0.856 | Datasheet max + calculated |
| LCD logic, including its built-in ST7066U controller | NHD-0216K1Z-FL-YBW | 4.5 to 5.5V | 1 | 3.000 | 3.000 | Datasheet max |
| LCD backlight, full brightness | NHD-0216K1Z-FL-YBW | 4.9 to 5.1V | 1 | 156.000 | 156.000 | Datasheet max |
| LDR cup-sensor divider | PDV-P8103 + 10k ohm | 5V | 1 | 0.516 | 0.516 | Calculated bound |
| **Subtotal** | | | | | **330.372** | |

## B. 5V Rail

Every load goes on the one 5V rail. I also added the small support currents (pull-ups, LEDs, trimmer), even though they are not major components, so nothing is missed. Every support current uses the worst case: a 5.1V rail and each resistor at its lowest value.

| Load on the 5V rail | Part | Total (mA) | How I got it |
|---|---|---|---|
| Curiosity Nano | DM164150 | 170.000 | See [Notes on the Numbers](#notes-on-the-numbers) |
| Dual op amp | MCP6002-I/P | 0.856 | 2 x 0.170mA IQ max + 5.1V / 9.9k ohm |
| LCD logic | NHD-0216K1Z-FL-YBW | 3.000 | IDD max at 5.0V |
| LCD backlight | NHD-0216K1Z-FL-YBW | 156.000 | ILED max at 5.0V |
| LDR divider | PDV-P8103 + 10k ohm | 0.516 | 5.1V / 9.9k ohm |
| LCD E pull-down | 100k ohm | 0.052 | 5.1V / 99k ohm, only while E is high |
| LCD contrast trimmer | 10k ohm | 0.638 | 5.1V / 8k ohm (20% tolerance) |
| Three status LEDs | 2.2k ohm each | 7.026 | 3 x 5.1V / 2.178k ohm, no LED drop counted |
| Four button pull-ups | 10k ohm each | 2.061 | 4 x 5.1V / 9.9k ohm, all pressed |
| Two I2C pull-ups | 4.7k ohm each | 2.193 | 2 x 5.1V / 4.653k ohm, both lines low |
| **Total before margin** | | **342.342** | |
| Safety margin | | 25% | Added once |
| **Total 5V current required** | | **427.928** | 342.342 x 1.25, rounded up |

## C. Regulator

| Regulator | Part number | Rating (mA) | Required (mA) | Remaining (mA) |
|---|---|---|---|---|
| 5V low-dropout linear regulator | TI LM1086IT-5.0/NOPB (TO-220) | 1,500.000 | 427.928 | **1,072.072** |
| Same regulator, thermal limit with my heat sink | HSE14-384225P heat sink | 1,220.000 | 427.928 | **792.072** |

The 1,500mA is what the regulator can supply, not what it uses. The thermal limit is the output current that would heat the junction to 125 C at 40 C (see the [Thermal Check](#thermal-check)).

## D. External Power Source

| Power source | Part number | AC input | DC output | Capacity (mA) |
|---|---|---|---|---|
| Regulated 9V wall adapter | Triad Magnetics WSU090-2000 | 90 to 264VAC | 9V | 2,000.000 |

| Check | Value (mA) |
|---|---|
| Regulators on this source: LM1086 rating (class template method) | 1,500.000 |
| **Total remaining, class template method** | **500.000** |
| Regulator output current with margin | 427.928 |
| Regulator quiescent current, max (added once, after the margin) | 10.000 |
| Real adapter current needed (a linear regulator draws Iout + Iq) | 437.928 |
| **Adapter current remaining, real load** | **1,562.072** |

Both checks are positive. The class template subtracts the full regulator rating, so I picked a 2A adapter instead of the 1.3A one that was in my first draft. The 1.3A adapter would have been -200mA with the template method. The adapter only gives about 3.94W of its 18W rating (9V x 437.928mA).

## E. Battery Life

N/A. My board runs from a wall adapter and has no battery.

## Supply Voltage Check

| Check | Value | Source |
|---|---|---|
| Adapter output | 9V +/-5%, so 8.55 to 9.45V | Triad datasheet |
| Adapter ripple | 150mV peak-to-peak max | Triad datasheet |
| Lowest regulator input | 8.55V - 0.075V (half the ripple) - 0.067V (cord and jack) = 8.408V | Calculated |
| Input needed for regulation | 5.1V + 1.5V max dropout = 6.6V (also above the 6.5V accuracy minimum) | LM1086 datasheet |
| **Dropout headroom** | **1.808V** | Calculated |
| Regulated 5V rail | 4.900 to 5.100V over line, load, and temperature | LM1086 datasheet |
| LCD backlight range | 4.9 to 5.1V, so the rail is inside it | LCD datasheet |
| LCD logic, PIC, Nano level shifters, MCP6002 | 4.5 to 5.5V, 1.8 to 5.5V, 5.5V max, 1.8 to 6.0V | Datasheets |

The regulator's output range is the reason I picked the LM1086. A 7805 can be 4.75 to 5.25V, which is outside the backlight's range. The 150mV of adapter ripple is rejected by the regulator, so it does not show up on the 5V rail in any way that matters. The regulator needs a 10uF input capacitor and a 10uF tantalum output capacitor to stay stable (TI section 7.4.2).

## Thermal Check

A linear regulator turns the extra voltage into heat. I used the worst case: the highest adapter voltage (9.45V), the lowest output (4.9V), the full budget current, and the max quiescent current.

| Item | Value |
|---|---|
| Regulator heat: (9.45 - 4.9)V x 427.928mA + 9.45V x 10mA | **2.042W** |
| Junction to tab (LM1086 TO-220, 4.0 C/W used for both sections) | 4 C/W |
| Insulating pad allowance (SP900S lists 0.61 C/W) | 1 C/W |
| Heat sink HSE14-384225P, still air | 10 C/W |
| Total | 15 C/W |
| Enclosure temperature (design assumption) | 40 C |
| **Junction temperature: 40 + 2.042 x 15** | **70.6 C** |
| Limit (control section; the output section allows 150 C) | 125 C |
| **Margin** | **54.4 C** |
| Heat sink rise above the enclosure air | about 20 C |

The heat sink is rated at 10 C/W at 1W, and its curve shows 19.2 C of rise at 2W (9.6 C/W), so 10 C/W is a safe number. The rating is for open air, so a closed box will make it run hotter. That is why I used 40 C for the inside of the enclosure. I will keep the heat sink away from the LCD, which is only rated to 70 C.

## Notes on the Numbers

**Curiosity Nano (170mA): a derived ceiling, not a datasheet current.** Microchip only lists the PIC's maximum supply current at 3.0V (8.2mA at 64MHz). It does not list a maximum at 5V, so I could not just copy one. The template still needs a maximum, so I built a safe ceiling instead:

- The PIC's absolute-maximum power dissipation is 800mW. At the lowest rail voltage, 800mW / 4.9V = 163.3mA. My PIC pins sink the LED and pull-up currents and barely source anything (only the LCD E line), so this limits the PIC's own supply current.
- The Nano board adds its yellow user LED (1k ohm from the target supply, up to 5.37mA with no LED drop and a -5% resistor) and about 0.1mA for its level shifters and voltage monitor. I rounded that up to 5.5mA.
- 163.3 + 5.5 = 168.8mA, which I rounded up to 170mA.

The real draw should be much lower. The PIC's typical current at 64MHz is 6.7mA (at 3.0V). The 350mA VSS-pin rating is a stress limit, so I did not use it as a current.

**Op amp (0.856mA).** The MCP6002 uses at most 170uA per amplifier (guaranteed at 25 C). The most current its outputs can push through the 10k ohm and 30k ohm feedback resistors is 5.1V / 9.9k ohm = 0.515mA. The +/-30mA "current at supply pins" in the datasheet is an absolute-maximum stress rating, not current it uses, so my first draft's 30mA was too high.

**LCD (3mA + 156mA).** These are the datasheet maximums at 5.0V and 25 C. The ST7066U controller is inside the LCD, so it is only counted once. The backlight is my biggest real load (130mA typical). At 5.1V it could draw a little more than 156mA, but the 25% margin covers that.

**Value types used:**

- Datasheet max: a guaranteed limit from the manufacturer's electrical table.
- Calculated bound: Ohm's law with the rail at 5.1V and the resistor at its minimum value.
- Derived ceiling: built from an absolute-maximum rating because no 5V operating maximum is published.
- Typical values are only mentioned for comparison and are never used in the totals.

## Conclusions

The Triad WSU090-2000 adapter and the LM1086 regulator can power everything on my board at once with the 25% margin. Every remaining-current number is positive, including the class template check (500mA). The regulator has 1.8V of dropout headroom and stays about 54 C below its temperature limit with the HSE14-384225P heat sink. The 5V rail stays between 4.9 and 5.1V, which keeps the LCD backlight inside its rating. My budget is very conservative, mostly because of the 170mA Nano ceiling and the full-brightness backlight. I expect the real board to draw well under the budget, and I will measure it.

**Still needs testing on the prototype (not done yet):**

- Total board current, measured in series with the 9V input
- 5V rail voltage under full load
- Regulator and heat sink temperature inside the closed enclosure
- Plug fit and seating in the PJ-102AH jack

## Downloads

- Spreadsheet with all formulas: [Fill-A-Bot-Main-Control-Power-Budget.xlsx](Fill-A-Bot-Main-Control-Power-Budget.xlsx)
- PDF copy of this page: [Power-Budget.pdf](Power-Budget.pdf)

## References

1. [Component Selection assignment](https://embedded-systems-design.bitbucket.io/304/individual-assignments/component-selection/) (Part 2: Power Budget) and the class [Power Budget Example](https://www.dropbox.com/s/wyeqisp0uzyiics/Power%20Budget%20Example.xlsx?dl=0).
2. Microchip, [PIC18F27/47/57Q43 data sheet, DS40002147H](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/PIC18F27-47-57Q43-Microcontroller-Data-Sheet-XLP-DS40002147.pdf), sections 47.1 and 47.3.2.
3. Microchip, [PIC18F57Q43 Curiosity Nano hardware user guide, DS40002186B](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/UserGuides/PIC18F57Q43-Curiosity-Nano-HW-UserGuide-DS40002186B.pdf), section 3.3.2 and the schematic.
4. Microchip, [MCP6001/2/4 datasheet, DS20001733L](https://ww1.microchip.com/downloads/en/DeviceDoc/MCP6001-1R-1U-2-4-1-MHz-Low-Power-Op-Amp-DS20001733L.pdf).
5. Newhaven Display, [NHD-0216K1Z-FL-YBW datasheet](https://newhavendisplay.com/content/specs/NHD-0216K1Z-FL-YBW.pdf).
6. Advanced Photonix (Luna), [PDV-P8103 datasheet](https://media.digikey.com/pdf/data%20sheets/photonic%20detetectors%20inc%20pdfs/pdv-p8103.pdf).
7. Texas Instruments, [LM1086 datasheet, SNVS039J](https://www.ti.com/lit/ds/symlink/lm1086.pdf), sections 6.4, 6.5, 7.4.2, and 10.3.
8. Triad Magnetics, [WSU090-2000 datasheet](https://catalog.triadmagnetics.com/Asset/WSU090-2000.pdf).
9. Same Sky, [HSE14-384225P heat sink datasheet](https://www.sameskydevices.com/product/resource/hse14-384225p.pdf).
10. Bergquist, [SP900S-0.009-00-54 TO-220 pad, DigiKey product page](https://www.digikey.com/en/products/detail/bergquist/SP900S-0-009-00-54/307797).
11. Same Sky, [PJ-102AH barrel jack datasheet](https://www.sameskydevices.com/product/resource/pj-102ah.pdf).
