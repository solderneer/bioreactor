#include <Arduino.h>
#include "motor_controller.h"

// Initialises the controller and its pins
MotorController::MotorController(int motor_pin, int encoder_pin) {
  _motor_pin = motor_pin;
  _encoder_pin = encoder_pin;
  pinMode(_motor_pin, OUTPUT);
  pinMode(_encoder_pin, INPUT);
}

void MotorController::setThreshold(int v) {
  _threshold = v;
}

double MotorController::read(void) {
  return measureSpeed(500);
}

void MotorController::write(double output) {
  // Clamp output values
  int o = (int)output;
  if( o > 255) o = 255;
  else if(o < 0) o = 0;

  setMotorOutput(o); 
}

double MotorController::measureSpeed(uint32_t timeout) {
  // Timeout parameters
  unsigned long timout_start = millis();

  // Waiting for IR to be unblocked
  while(analogRead(_encoder_pin) > _threshold) {
    if((millis() - timout_start) > timeout)
      return 0.0;
  }
  // Waiting for IR to be blocked
  while(analogRead(_encoder_pin) < _threshold) {
    if((millis() - timout_start) > timeout)
      return 0.0;
  }
  // Starting timer
  unsigned long start = millis();

  // Waiting for it to be unblocked
  while(analogRead(_encoder_pin) > _threshold) {
    if((millis() - timout_start) > timeout)
      return 0.0;
  }
  // Waiting for it to be blocked again
  while(analogRead(_encoder_pin) < _threshold) {
    if((millis() - timout_start) > timeout)
      return 0.0;
  }

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
