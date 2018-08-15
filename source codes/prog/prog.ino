/*
 * MotorKnob
 *
 * A stepper motor follows the turns of a potentiometer
 * (or other sensor) on analog input 0.
 *
 * http://www.arduino.cc/en/Reference/Stepper
 * This example code is in the public domain.
 */

#include <Stepper.h>
#include<Servo.h>

// change this to the number of steps on your motor
#define STEPS 100
Servo myservo1;
Servo myservo2;

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 8, 9, 10, 11);
int pos1=0;
int pos2=0;
// the previous reading from the analog input
int previous = 0;

void setup() {
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(100);
  myservo1.attach(3);
  myservo2.attach(6);
  Serial.begin(9600);
}

void loop() {
  // get the sensor value
  int val = analogRead(0);

  // move a number of steps equal to the change in the
  // sensor reading
  stepper.step(val - previous);

  // remember the previous value of the sensor
  previous = val;
 int pos1=30;
 int pos2=30;
  myservo1.write(pos1);
  myservo2.write(pos2);
  }
