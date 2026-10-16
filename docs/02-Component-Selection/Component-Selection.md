---
title: Component Selection
---

# Component Selection

**Everything on this page is for my individual subsystem, the Main Control Board.**

My board reads the UP, DOWN, START, and STOP buttons, checks that a cup is there, runs the team I2C bus, and shows the amount and status on a display. Prices are from DigiKey for one part (October 2026).

## 1. Power Source

| Solution | Pros | Cons |
|---|---|---|
| ![Triad WSU090 adapter](adapter-triad-wsu090.jpg){ width="110" }<br>Option 1.<br>Triad Magnetics WSU090-1300<br>9V 1.3A wall adapter<br>$8.65/each<br>[DigiKey](https://www.digikey.com/en/products/detail/triad-magnetics/WSU090-1300/3094977) / [Datasheet](https://catalog.triadmagnetics.com/Asset/WSU090-1300.pdf) | - Most inexpensive<br>- In stock<br>- Long 6 ft cord | - Less than the regulator's 1.5A rating<br>- Output can be off by 5%<br>- Big body blocks the next outlet |
| ![MEAN WELL GST18U adapter](adapter-meanwell-gst18u09.jpg){ width="110" }<br>Option 2.<br>MEAN WELL GST18U09-P1J<br>9V 2A wall adapter<br>$14.10/each<br>[DigiKey](https://www.digikey.com/en/products/detail/mean-well-usa-inc/GST18U09-P1J/7703633) / [Datasheet](https://www.meanwellusa.com/upload/pdf/GST18U/GST18U-spec.pdf) | - 2A is more than enough<br>- Lowest ripple<br>- Wide temperature range | - Most expensive<br>- Out of stock<br>- Short 1.2 m cord |
| ![Triad WSU090 adapter](adapter-triad-wsu090.jpg){ width="110" }<br>Option 3.<br>Triad Magnetics WSU090-2000<br>9V 2A wall adapter<br>$12.43/each<br>[DigiKey](https://www.digikey.com/en/products/detail/triad-magnetics/WSU090-2000/3094951) / [Datasheet](https://catalog.triadmagnetics.com/Asset/WSU090-2000.pdf) | - 2A covers the regulator's full 1.5A<br>- In stock<br>- Long 6 ft cord | - Costs more than the 1.3A one<br>- Output can be off by 5%<br>- Only rated up to 40 C |

**Choice:** Option 3: Triad WSU090-2000

**Rationale:** The class power budget checks the adapter against the regulator's full 1.5A rating, so I need at least 1.5A. The 2A Triad passes that, it's in stock, and it costs less than the MEAN WELL. It has the 5.5 x 2.1 mm center-positive plug that fits my barrel jack.

## 2. 5V Linear Regulator

| Solution | Pros | Cons |
|---|---|---|
| ![TI TO-220 regulator](regulator-ti-to220.jpg){ width="110" }<br>Option 1.<br>Texas Instruments LM7805CT/NOPB<br>5V 1.5A, TO-220<br>$1.86/each<br>[DigiKey](https://www.digikey.com/en/products/detail/texas-instruments/LM7805CT-NOPB/3901929) / [Datasheet](https://www.ti.com/lit/ds/symlink/lm340.pdf) | - Really common part<br>- Built-in thermal protection<br>- Easy to solder | - Output can be 4.75 to 5.25V<br>- About 2V dropout<br>- Out of stock |
| ![ST TO-220 regulator](regulator-st-l7805cv.jpg){ width="110" }<br>Option 2.<br>STMicroelectronics L7805CV<br>5V 1.5A, TO-220<br>$1.08/each<br>[DigiKey](https://www.digikey.com/en/products/detail/stmicroelectronics/L7805CV/585964) / [Datasheet](https://www.st.com/resource/en/datasheet/l78.pdf) | - Most inexpensive<br>- Lots in stock<br>- Standard 7805 pinout | - Output can be 4.75 to 5.25V<br>- About 2V dropout<br>- Gets just as hot as the others |
| ![TI TO-220 regulator](regulator-ti-to220.jpg){ width="110" }<br>Option 3.<br>Texas Instruments LM1086IT-5.0/NOPB<br>5V 1.5A low dropout, TO-220<br>$2.58/each<br>[DigiKey](https://www.digikey.com/en/products/detail/texas-instruments/LM1086IT-5-0-NOPB/363580) / [Datasheet](https://www.ti.com/lit/ds/symlink/lm1086.pdf) | - Output stays 4.9 to 5.1V<br>- Only 1.5V max dropout<br>- In stock | - Needs a 10uF tantalum output cap<br>- Different pinout than a 7805<br>- Costs a little more |

**Choice:** Option 3: TI LM1086IT-5.0/NOPB

**Rationale:** My LCD backlight needs 4.9 to 5.1V, and the LM1086 is the only one that stays in that range. The 7805s can go up to 5.25V. It turns about 2W into heat at my full budget, so I'm adding a Same Sky HSE14-384225P heat sink with an insulating pad. That keeps it around 71 C, well under its 125 C limit.

## 3. Cup Sensor (Analog)

| Solution | Pros | Cons |
|---|---|---|
| ![PDV-P8103 photoresistor](sensor-pdv-p8103.jpg){ width="110" }<br>Option 1.<br>Advanced Photonix PDV-P8103<br>Photoresistor (LDR)<br>$0.72/each<br>[DigiKey](https://www.digikey.com/en/products/detail/advanced-photonix/PDV-P8103/480610) / [Datasheet](https://media.digikey.com/pdf/data%20sheets/photonic%20detetectors%20inc%20pdfs/pdv-p8103.pdf) | - Big change between light and shadow<br>- Sees normal room light<br>- Used it in my photoresistor lab | - Slow (about 60ms)<br>- Room light changes the reading<br>- Each one is a little different |
| ![TEPT4400 phototransistor](sensor-tept4400.jpg){ width="110" }<br>Option 2.<br>Vishay TEPT4400<br>Phototransistor<br>$0.50/each<br>[DigiKey](https://www.digikey.com/en/products/detail/vishay-semiconductor-opto-division/TEPT4400/1681191) / [Datasheet](https://www.vishay.com/docs/81341/tept4400.pdf) | - Most inexpensive<br>- Fast<br>- Responds like the human eye | - Big part-to-part difference<br>- Can max out in bright light<br>- Narrow viewing angle |
| ![BPW34 photodiode](sensor-bpw34.jpg){ width="110" }<br>Option 3.<br>Vishay BPW34<br>Photodiode<br>$1.37/each<br>[DigiKey](https://www.digikey.com/en/products/detail/vishay-semiconductor-opto-division/BPW34/1681149) / [Datasheet](https://www.vishay.com/docs/81521/bpw34.pdf) | - Very linear<br>- Large sensing area<br>- Fast | - Needs a different amp circuit<br>- Also picks up infrared<br>- Really small currents |

**Choice:** Option 1: Advanced Photonix PDV-P8103

**Rationale:** It's simple, inexpensive, and I already know how it works from lab. It sits under the cup spot with a 10k resistor, and a cup's shadow drops the voltage. A divider alone doesn't count as an analog sensor for this class, so it goes through the op amp below before the ADC. I'll still need to test it with our real cups, since a clear cup may not make much of a shadow.

## 4. Op Amp

| Solution | Pros | Cons |
|---|---|---|
| ![MCP6002 op amp](opamp-mcp6002-ip.jpg){ width="110" }<br>Option 1.<br>Microchip MCP6002-I/P<br>Dual op amp, 8-pin DIP<br>$0.45/each<br>[DigiKey](https://www.digikey.com/en/products/detail/microchip-technology/MCP6002-I-P/500875) / [Datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/MCP6001-1R-1U-2-4-1-MHz-Low-Power-Op-Amp-DS20001733L.pdf) | - Rail-to-rail on 5V<br>- Two op amps in one chip<br>- Very low current | - Higher offset<br>- Only 1MHz<br>- Doesn't quite reach the rails |
| ![TLV2372 op amp](opamp-tlv2372ip.jpg){ width="110" }<br>Option 2.<br>Texas Instruments TLV2372IP<br>Dual op amp, 8-pin DIP<br>$2.38/each<br>[DigiKey](https://www.digikey.com/en/products/detail/texas-instruments/TLV2372IP/413506) / [Datasheet](https://www.ti.com/lit/ds/symlink/tlv2372.pdf) | - Rail-to-rail<br>- Wide supply range<br>- 3MHz | - About 5x the price<br>- Uses more current<br>- Speed isn't needed |
| ![OPA2340 op amp](opamp-opa2340ua.jpg){ width="110" }<br>Option 3.<br>Texas Instruments OPA2340UA<br>Dual op amp, SOIC-8<br>$4.63/each<br>[DigiKey](https://www.digikey.com/en/products/detail/texas-instruments/OPA2340UA-2K5/301193) / [Datasheet](https://www.ti.com/lit/ds/symlink/opa2340.pdf) | - Low offset<br>- 5.5MHz<br>- Rail-to-rail | - Most expensive<br>- Surface mount is harder to solder<br>- Uses the most current |

**Choice:** Option 1: Microchip MCP6002-I/P

**Rationale:** A cup sensor is slow, so I don't need a fast op amp. The MCP6002 is inexpensive, comes in a DIP, and has two op amps. One buffers the LDR, and the other amplifies it with a gain of -3 around a 2.5V reference (Rin 10k, Rf 30k). I'll set the cup threshold in code after testing.

## 5. Display

| Solution | Pros | Cons |
|---|---|---|
| ![4-digit 7-segment display](display-7seg-kw4-56ncuya.jpg){ width="110" }<br>Option 1.<br>Lucky Light KW4-56NCUYA-P (Adafruit 811)<br>4-digit 7-segment display<br>$3.95/each<br>[DigiKey](https://www.digikey.com/en/products/detail/adafruit-industries-llc/811/5774235) / [Datasheet](https://cdn-shop.adafruit.com/datasheets/811datasheet.pdf) | - Big, easy to read digits<br>- Bright<br>- Inexpensive | - Can't show words like Ready or Filling<br>- Can't show units<br>- Needs a driver chip |
| ![14-segment display](display-14seg-pdc54.jpg){ width="110" }<br>Option 2.<br>Kingbright PDC54-11SURKWA<br>2-character 14-segment display<br>$5.60/each (need 4)<br>[DigiKey](https://www.digikey.com/en/products/detail/kingbright/PDC54-11SURKWA/16602198) / [Datasheet](https://www.kingbrightusa.com/images/catalog/SPEC/PDC54-11SURKWA.pdf) | - Can show letters<br>- Bright, high contrast<br>- Big characters | - 4 of them are too wide for my board<br>- Needs a driver chip<br>- Only 8 characters |
| ![16x2 LCD](display-lcd-nhd-0216k1z.jpg){ width="110" }<br>Option 3.<br>Newhaven Display NHD-0216K1Z-FL-YBW<br>16x2 character LCD<br>$7.83/each<br>[DigiKey](https://www.digikey.com/en/products/detail/newhaven-display-intl/NHD-0216K1Z-FL-YBW/1701171) / [Datasheet](https://newhavendisplay.com/content/specs/NHD-0216K1Z-FL-YBW.pdf) | - Shows the amount, units, and status at once<br>- Built-in controller, no driver chip<br>- Backlit | - Backlight uses up to 156mA<br>- Needs a contrast pot<br>- Uses 6 pins |

**Choice:** Option 3: Newhaven NHD-0216K1Z-FL-YBW

**Rationale:** Our team requirements say the display has to show the amount, the units, and words like Ready, Filling, and Finished. The LCD is the only option that can do all of that at once. It wires straight to the Nano in 4-bit mode (RC0-RC5), so I don't need a driver chip or an I2C backpack.

## Pin Assignments

| Pin | Use | Connects to |
|---|---|---|
| RA0-RA3 | Digital input | UP, DOWN, START, STOP buttons (10k pull-ups) |
| RA5 | ADC | Cup sensor (op amp output) |
| RD0-RD2 | Digital output | Dispensing, Done, Fault LEDs |
| RB2 / RB1 | I2C SDA / SCL | Ribbon connectors J1-J3, pins 1 and 2 |
| RC0-RC3 | Digital output | LCD DB4-DB7 |
| RC4 | Digital output | LCD RS |
| RC5 | Digital output | LCD E |
| VTG | Power | 5V from the LM1086 (VOFF tied to GND) |
| GND | Ground | Board ground and ribbon pin 8 |

## References

1. Triad Magnetics WSU090-2000: [DigiKey](https://www.digikey.com/en/products/detail/triad-magnetics/WSU090-2000/3094951), [datasheet](https://catalog.triadmagnetics.com/Asset/WSU090-2000.pdf)
2. TI LM1086IT-5.0/NOPB: [DigiKey](https://www.digikey.com/en/products/detail/texas-instruments/LM1086IT-5-0-NOPB/363580), [datasheet](https://www.ti.com/lit/ds/symlink/lm1086.pdf)
3. Same Sky HSE14-384225P heat sink: [DigiKey](https://www.digikey.com/en/products/detail/same-sky-formerly-cui-devices/HSE14-384225P/26460932), [datasheet](https://www.sameskydevices.com/product/resource/hse14-384225p.pdf)
4. Advanced Photonix PDV-P8103: [DigiKey](https://www.digikey.com/en/products/detail/advanced-photonix/PDV-P8103/480610), [datasheet](https://media.digikey.com/pdf/data%20sheets/photonic%20detetectors%20inc%20pdfs/pdv-p8103.pdf)
5. Microchip MCP6002-I/P: [DigiKey](https://www.digikey.com/en/products/detail/microchip-technology/MCP6002-I-P/500875), [datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/MCP6001-1R-1U-2-4-1-MHz-Low-Power-Op-Amp-DS20001733L.pdf)
6. Newhaven NHD-0216K1Z-FL-YBW: [DigiKey](https://www.digikey.com/en/products/detail/newhaven-display-intl/NHD-0216K1Z-FL-YBW/1701171), [datasheet](https://newhavendisplay.com/content/specs/NHD-0216K1Z-FL-YBW.pdf)
7. Microchip PIC18F57Q43 Curiosity Nano: [user guide](https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/UserGuides/PIC18F57Q43-Curiosity-Nano-HW-UserGuide-DS40002186B.pdf)

Part photos are from DigiKey.
