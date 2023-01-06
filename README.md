# ArduinoProj

Here is a description of the connections:

Connect the LCD display to the breadboard. The display has 16 pins that can be connected to the breadboard.

Connect the blacklight (e.g. LED) to the breadboard. The blacklight typically has two legs that can be connected to the breadboard.

Connect the Arduino Uno to the breadboard. The Arduino has several pins that can be connected to the breadboard.

Connect the LCD display to the Arduino Uno using jumper wires. The connections will depend on the specific pins that you are using for the LCD display and the Arduino. In the example script above, the LCD is connected to the following pins:

LCD pin 1 (GND) to Arduino GND

LCD pin 2 (VCC) to Arduino 5V

LCD pin 3 (Contrast) to a potentiometer, with the middle pin connected to Arduino pin 3 and the other two pins connected to +5V and GND

LCD pin 4 (RS) to Arduino pin 12

LCD pin 5 (R/W) to Arduino GND

LCD pin 6 (Enable) to Arduino pin 11

LCD pin 11 (Data 4) to Arduino pin 5

LCD pin 12 (Data 5) to Arduino pin 4

LCD pin 13 (Data 6) to Arduino pin 3

LCD pin 14 (Data 7) to Arduino pin 2

Connect the blacklight to the Arduino Uno using a jumper wire. In the example script above, the blacklight is connected to Arduino pin 9.

Connect a power source (e.g. a battery pack or a power supply) to the breadboard. Make sure to connect the positive terminal to the breadboard's + rail and the negative terminal to the breadboard's - rail.
