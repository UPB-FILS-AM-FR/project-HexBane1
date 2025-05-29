# Tug of War Game

| | |
|-|-|
|`Author` | Neata Mihnea-Ioan

## Description

A tug of war game where two players press buttons as fast as they can within timed intervals. Their button presses power motors that pull an elastic band toward their side. A central mark on the band indicates the middle of the band and the first player to pull the mark to his side wins. An LCD displays the countdown, current status, and winner.

## Motivation

I was always interested in creating games, this project gave me that opportunity. I also think that this project will help me improve my coding skills and also develop my problem solving skills, by resolving problems as they come up.

## Architecture

### Block diagram

![Block_Schematic](https://github.com/user-attachments/assets/b00a39b4-e2ff-4927-b1e3-b2d3d738a488)


### Schematic

![image](https://github.com/user-attachments/assets/d95d7ab6-fc43-4267-8fe9-d1b2f85bae80)


### Components

| Device | Usage | Price |
|--------|--------|-------|
| Placă de Dezvoltare Compatibilă cu Arduino Nano | Development Board | [24.99 RON](https://www.optimusdigital.ro/ro/compatibile-cu-arduino-nano/1686-placa-de-dezvoltare-compatibila-cu-arduino-nano-atmega328p-i-ch340.html) |
| Modul LCD 1602 cu backlight albastru 5V | Info display | [13.83 RON](https://www.optimusdigital.ro/ro/optoelectronice-lcd-uri/94-modul-lcd-1602-cu-backlight-albastru-de-5-v.html) |
| Motor cu Reductor JGA25-370 170RPM 6V | Pulling Mechanism | [49.00 RON](https://www.optimusdigital.ro/ro/motoare-motoare-cu-reductor-de-25-mm/12256-motor-cu-reductor-jga25-370-6v-170-rpm.html) |
| Modul cu Driver de Motoare Dual L298N Rosu | Motor Configuration | [10.99 RON](www.optimusdigital.ro/ro/drivere-de-motoare-cu-perii/145-driver-de-motoare-dual-l298n.html) |
| Cablu Albastru USB AM - B Mini 30 cm pentru Arduino NANO | Connector for development board | [4.37 RON](https://www.optimusdigital.ro/ro/cabluri-cabluri-usb/3147-cablu-albastru-usb-am-b-mini-30-cm-pentru-arduino-nano.html) |
| Buton cu Capac Rotund Roșu | Buton | [2.00 RON](https://www.optimusdigital.ro/ro/butoane-i-comutatoare/1114-buton-cu-capac-rotund-rou.html) |
| Buton cu Capac Rotund Albastru | Buton | [2.00 RON](https://www.optimusdigital.ro/ro/altele/1118-buton-cu-capac-rotund-albastru.html) |
| Kit Plusivo pentru Introducere în Electronică | Rezistors, wires, breadboard etc. | [39.99 RON](www.optimusdigital.ro/ro/kituri/12026-kit-plusivo-pentru-introducere-in-electronica-0721248990075.html) |
| Gearmotor with Wheel | Pulling Mechanism | [30.00 RON](https://www.optimusdigital.ro/ro/motoare-motoare-cu-reductor-de-25-mm/12256-motor-cu-reductor-jga25-370-6v-170-rpm.html) |

### Libraries

| Library | Description | Usage |
|--------|--------|-------|
|Arduino|Core Arduino functions and definitions|Basic hardware control|
|LiquidCrystal|Controls character LCD|Used to display text on LCD screens|

## Log

### Week 5 - 11 May
Acquired some of pieces, brainstormed ideas for the final prototype of the project.
### Week 12 - 18 May
Acquired all pieces necessary to build the project, finished documentation and started prototyping for the project, finished basic code logic with button implementation.
### Week 19 - 25 May
Finished connecting the power supply, motor driver and lcd display to the nano, implemented it into the code from before, started working on the display case for the project
### Week 26 - 28 May
Finished case, added reset feature, faulty motor caused project to go back to the initial idea of a 2 motor functionality, refined case and finished documentation

## Reference links
https://www.youtube.com/watch?v=E2sTbpFsvXI&ab_channel=RyanChan
https://www.youtube.com/watch?v=r4jHMO23TxM&ab_channel=DIYUSTHAD

## Project test link
www.youtube.com/watch?v=Tg27Zz5y22Y&feature=youtu.be
