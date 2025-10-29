#include <Arduino.h>
#include <L298N.hpp>
// Assign IR pin numbers
#define IRpin1 8
#define IRpin2 9

void setup()
{
  // Set the IR sensor pin as an input
  pinMode(IRpin1, INPUT);
  pinMode(IRpin2, INPUT);

  // Set motor pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
}

void loop()
{

  // Read the state of the IR sensor
  int IRread1 = digitalRead(IRpin1);
  int IRead2 = digitalRead(IRpin2);

  // The sensor's OUT pin is usually LOW when an obstacle is detected
  if (IRread1 == LOW || IRead2 == LOW)
  {
    // If an obstacle is detected,
    stopMotor();
    Serial.println("Object detected");
  }
  else
  {
    // If no obstacle is detected
    moveForward();
    Serial.println("Path is clear");
  }

  // A small delay to make the readings more stable
  delay(100);
}
