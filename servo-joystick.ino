#include <Servo.h>  // include the Servo library

Servo myservo;  // create a servo object

int xAxis = A0;  // analog pin for X axis of joystick
int yAxis = A1;  // analog pin for Y axis of joystick
int button = 2;  // digital pin for button

void setup() {
  myservo.attach(9);  // attach the servo to pin 9
  pinMode(button, INPUT);  // set button pin to INPUT
}

void loop() {
  // read X and Y values from joystick
  int xValue = analogRead(xAxis);
  int yValue = analogRead(yAxis);

  // calculate desired angle for servo based on joystick values
  int angle = map(xValue, 0, 1023, 0, 180);

  // set angle of servo
  myservo.write(angle);

  // check button state and perform action if necessary
  int buttonState = digitalRead(button);
  if (buttonState == HIGH) {
    // turn servo off
    myservo.detach();
  }
}
