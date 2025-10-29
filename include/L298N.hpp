#pragma once
#include <Arduino.h>


// const int motorSpeed = 120;  // Speed range: 0 - 255
extern int motorSpeed;// = 120;  // Speed range: 0 - 255

// Motor pins for L298N
const int ENA = 3;     // PWM pin for speed control
const int IN1 = 5;     // Motor direction
const int IN2 = 4;     // Motor direction

const int ENB = 6;     // PWM pin for speed control
const int IN3 = 7;     // Motor direction
const int IN4 = 2;     // Motor direction

// Prototypes
void moveForward();
void moveBackward();
void stopMotor();