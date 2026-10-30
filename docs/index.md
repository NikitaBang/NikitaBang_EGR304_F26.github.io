---
title: Welcome
---
<center>
<font size="6">Nikita Bangiyev Datasheet</font><br>
as part of<br>
<font size="8">Fill-A-Bot</font><br>
for<br>
<font size="5">Team 201</font><br>

<b>Updated: October 30, 2026</b>
</center>

## Introduction

This is my individual datasheet for EGR 304. It shows my part of our team project, the parts I picked for my board, and how my board is powered.

## Target Customer and Use

For this prototype, Fill-A-Bot is meant for home kitchen use with plain drinking water only (tap or filtered, room temperature). The projected customer is someone at home who wants a set amount of water without using a measuring cup, like for cooking, coffee, or filling a water bottle. We picked kitchen use over lab use because a lab version would have to follow lab rules for cleaning, sterilization, and chemical safety, which adds a lot of restrictions we can't meet this semester. Fill-A-Bot is not sterile and isn't meant for chemicals, medicine, or other liquids. The parts that touch the water should be food-safe and easy to rinse, and the electronics stay separated from the water. A lab version could be a later step. See Target Customer and Use on our team's [Product Requirements](https://egr304-2026-f-201.github.io/04-Product-Requirements/#target-customer-and-use) page.

## Project Summary

Fill-A-Bot is our team's automatic liquid dispenser. You pick how much liquid you want, press start, and it fills your cup and stops on its own. Each of us builds our own board, and the boards talk to each other over ribbon cables using plain digital wires (2 wires per signal, 4 states). Our full team report is on the [Team 201 website](https://egr304-2026-f-201.github.io/).

* Nikita Bangiyev: Main Control Board (me)
* Cole Trask: flow sensing
* Clay Belsher: pump control
* Troy Reynolds: liquid amount sensing

## My Contribution

I'm doing the Main Control Board. It reads the UP, DOWN, START, and STOP buttons, uses a photoresistor and an op amp to check that a cup is in place, sends simple 2-wire digital signals to my teammates' boards (pump command to Clay, preset to Troy) and reads theirs back (flow status from Cole, weight status from Troy), and shows the amount and status on a 16x2 LCD.

* [Block Diagram](01-Block-Diagram/Block-Diagram.md): how my board is laid out and connected
* [Component Selection](02-Component-Selection/Component-Selection.md): the parts I picked for my board and why
* [Schematics](04-Schematic/schematic.md): the full schematic for my board
* [Power Budget](05-Power-Budget/Power-Budget.md): how much current my board needs and how it's powered
