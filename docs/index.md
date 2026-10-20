---
title: Welcome
---
<center>
<font size="6">Nikita Bangiyev Datasheet</font><br>
as part of<br>
<font size="8">Fill-A-Bot</font><br>
for<br>
<font size="5">Team 201</font><br>

**Updated: October 19, 2026**
</center>

## Introduction

This is my individual datasheet for EGR 304. It shows my part of our team project, the parts I picked for my board, and how my board is powered.

### Project Summary

Fill-A-Bot is our team's automatic liquid dispenser. You pick how much liquid you want, press start, and it fills your cup and stops on its own. Each of us builds our own board, and the boards talk to each other over a ribbon cable. Our full team report is on the [Team 201 website](https://egr304-2026-f-201.github.io/).

* Nikita Bangiyev: Main Control Board (me)
* Cole Trask: flow sensing
* Clay Belsher: pump control
* Troy Reynolds: liquid amount sensing

### My Contribution

I'm doing the Main Control Board. It reads the UP, DOWN, START, and STOP buttons, uses a photoresistor and an op amp to check that a cup is in place, talks to my teammates' boards over UART, and shows the amount and status on a 16x2 LCD.

* [Block Diagram](01-Block-Diagram/Block-Diagram.md): how my board is laid out and connected
* [Component Selection](02-Component-Selection/Component-Selection.md): the parts I picked for my board and why
* [Schematics](04-Schematic/schematic.md): the full schematic for my board
* [Power Budget](05-Power-Budget/Power-Budget.md): how much current my board needs and how it's powered
