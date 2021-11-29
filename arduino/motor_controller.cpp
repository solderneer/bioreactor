#include "motor_controller.h"
#include "Arduino.h"

// Initialises the controller and its pins
MotorController::MotorController(int motor_pin, int encoder_pin) {
}

double MotorController::read(void) {
  setMotorOutput()
  return 0.0;
}

void MotorController::write(double output) {
  // Add code here
  return;
}

int MotorController::measureSpeed(void) {
  duration = pulseIn(_encoder_pin, HIGH)
  return;
}

void MotorController::setMotorOutput(int output) {
  if (duration > 2500) {
        digitalWrite( _motor_pin, HIGH);
      }
      else{
        digitalWrite(_motor_pin, LOW)
      }
  return;
}
