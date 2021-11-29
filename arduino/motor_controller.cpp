#include "motor_controller.h"
#include "Arduino.h"

// Initialises the controller and its pins
MotorController::MotorController(int motor_pin, int encoder_pin) {
  _motor_pin = motor_pin;
  _encoder_pin = encoder_pin;
  pinMode(_motor_pin, OUTPUT);
  pinMode(_encoder_pin, INPUT);
}

double MotorController::read(void) {
  return measureSpeed();
}

void MotorController::write(double output) {
  // Clamp output values
  int o = (int)output;
  if( o > 255) o = 255;
  else if(o < 0) o = 0;

  setMotorOutput(o); 
}

double MotorController::measureSpeed(void) {
  // Waiting for IR to be unblocked
  while(digitalRead(_encoder_pin) == true);
  // Waiting for IR to be blocked
  while(digitalRead(_encoder_pin) == false);
  // Starting timer
  unsigned long start = millis();
  // Waiting for it to be unblocked
  while(digitalRead(_encoder_pin) == true);
  // Waiting for it to be blocked again
  while(digitalRead(_encoder_pin) == false);
  // Ending timing
  unsigned long end = millis();

  // Converting from milliseconds to minutes (60000ms per minute)
  double total = ((double)end - (double)start) / 60000;
  // Each time difference is half a rotation
  double rpm = 1 / (2 * total);
  return rpm;
}

// Controls the output power of the motor
// (value from 0-255)
void MotorController::setMotorOutput(int output) {
  analogWrite(_motor_pin, output);
}
