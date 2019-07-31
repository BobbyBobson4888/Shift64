# Shift64

Quick and dirty solution to "i have 64 things to control but only 4 pins on my arduino."

Basically:
- Take 9 shift registers (i used 74hc595's. if you have something else, double check the pin numbers).
- Connect their shift clock pins (pin 11) together and to a pin (clock_pin) on the arduino.
- Connect their data pins (pin 14) together and to a pin (data_pin) on the arduino.
- On one shift register:
  - Connect output enable (pin 13) to ground through a transitor, and connect the base of that transistor to a pin (dl_pin) on the arduino.
  - Connect latch clock (pin 12) to a pin (al_pin) on the arduino.
- On the other eight shift registers:
  - Connect output enable (pin 13) to ground.
  - Connect each latch clock (pin 12) to one of the output pins on the first shift register.

Slightly Non-ideal Schematic:
![](/images/2019/07/schematic.jpg)