---
title: Welcome
---
<center>
<font size="6">Nikita Bangiyev Datasheet</font><br>
as part of<br>
<font size="8">Fill-A-Bot</font><br>
for<br>
<font size="5">Team 201</font><br>

<b>Updated: November 9, 2026</b>
</center>

## About

This is my individual datasheet for EGR 304. It covers my part of our team project, the Main Control Board for Fill-A-Bot.

## Fill-A-Bot

Fill-A-Bot is our team's automatic water dispenser. You pick an amount, press start, and it fills your cup and stops by itself. Each of us builds one board, and the boards talk to each other over ribbon cables. Our team site is [here](https://egr304-2026-f-201.github.io/).

* Nikita Bangiyev: Main Control Board (me)
* Cole Trask: flow sensing
* Clay Belsher: pump control
* Troy Reynolds: liquid amount sensing

It's meant for home kitchen use with plain drinking water, like getting a set amount of water for cooking, coffee, or a water bottle without a measuring cup. We picked kitchen use over lab use because a lab version would need cleaning, sterilization, and chemical safety rules we can't meet this semester. It isn't sterile and isn't meant for other liquids. There's more on this on our team's [Product Requirements](https://egr304-2026-f-201.github.io/04-Product-Requirements/#target-customer-and-use) page.

## My Board

My board has the buttons and status LEDs the user sees, a light sensor that checks for a cup, and the Curiosity Nano that runs the fill. It tells Troy's board which preset was picked and tells Clay's board when to run the pump. Then it reads the weight status from Troy and the flow status from Cole, and stops the pump when the cup is full.

* [Block Diagram](01-Block-Diagram/Block-Diagram.md)
* [Component Selection](02-Component-Selection/Component-Selection.md)
* [Bill of Materials](03-BOM/BOM.md)
* [Schematics](04-Schematic/schematic.md)
* [Power Budget](05-Power-Budget/Power-Budget.md)
* [PCB](06-PCB/PCB.md)
