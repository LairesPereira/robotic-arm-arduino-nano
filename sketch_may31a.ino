#include <Servo.h>

Servo servo1;  
Servo servo2;  
Servo servo3;  

int potPin1 = A0;  // Analog input pin that the potentiometer1 is attached to
int potPin2 = A1;  // Analog input pin that the potentiometer2 is attached to
int potPin3 = A2;  // Analog input pin that the potentiometer2 is attached to

void setup() {
  Serial.begin(9600);
  servo1.attach(9);  // attaches the servo1 on pin 9
  servo2.attach(10); // attaches the servo2 on pin 10
  servo3.attach(8); // attaches the servo2 on pin 10
}

void loop() {
  int potValue1 = analogRead(potPin1);            // reads the value of the potentiometer1 (value between 0 and 1023)
  int potValue2 = analogRead(potPin2);            // reads the value of the potentiometer2 (value between 0 and 1023)
  int potValue3 = analogRead(potPin3);            // reads the value of the potentiometer2 (value between 0 and 1023)

  int servoPos1 = map(potValue1, 0, 1023, 0, 180); // scale it to use it with the servo (value between 0 and 180)
  int servoPos2 = map(potValue2, 0, 1023, 0, 180); // scale it to use it with the servo (value between 0 and 180)
  int servoPos3 = map(potValue3, 0, 1023, 0, 180); // scale it to use it with the servo (value between 0 and 180)

  servo1.write(servoPos1);                         // sets the servo position according to the scaled value
  servo2.write(servoPos2);                         // sets the servo position according to the scaled value
  servo3.write(servoPos3);                         // sets the servo position according to the scaled value

  Serial.print(servoPos1);
  Serial.print(" | ");
  Serial.print(servoPos2);
  Serial.print(" | ");
  Serial.println(servoPos3);


  delay(15);                                       // waits for the servo to get there
}