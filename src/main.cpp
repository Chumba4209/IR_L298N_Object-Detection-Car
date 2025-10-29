#include <Arduino.h>
// Assign IR pin numbers
#define IRpin1 8
#define IRpin2 9

// Motor pins for L298N
const int ENA = 3;     // PWM pin for speed control
const int IN1 = 5;     // Motor direction
const int IN2 = 4;     // Motor direction

const int ENB = 6;     // PWM pin for speed control
const int IN3 = 7;     // Motor direction
const int IN4 = 2;     // Motor direction


int motorSpeed = 120;  // Speed range: 0 - 255

// Prototypes
void moveForward();
void moveBackward();
void stopMotor();

void setup() {
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

void loop() {

   // Read the state of the IR sensor
  int IRread1 = digitalRead(IRpin1);
  int IRead2  = digitalRead(IRpin2);

  // The sensor's OUT pin is usually LOW when an obstacle is detected
  if (IRread1 == LOW || IRead2 ==LOW)
   {
    // If an obstacle is detected, 
    stopMotor();
    Serial.println("Object detected");
  } else {
    // If no obstacle is detected
    moveForward();
    Serial.println("Path is clear");
  }
  
  // A small delay to make the readings more stable
  delay(100); 

}

void moveForward(){
  // Move forward
  Serial.println("Moving FORWARD");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, motorSpeed);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, motorSpeed);
}

void moveBackward(){
  // Move backward
  Serial.println("Moving BACKWARD");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, motorSpeed);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, motorSpeed);

}

void stopMotor() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}
