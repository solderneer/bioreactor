#include <Arduino.h>
#include "ph_controller.h"

// Initialises the controller
// Acid and Alkali pins can just be digital pins
PhController::PhController(int ph_pin, int acid_pin, int alkali_pin) {
  _ph_pin = ph_pin;
  _acid_pin = acid_pin;
  _alkali_pin = alkali_pin;

  pinMode(_ph_pin, INPUT);
  pinMode(_acid_pin, OUTPUT);
  pinMode(_alkali_pin, OUTPUT);

  // Default calibration values
  _m = 1.00;
  _c = 1.00;
}

double PhController::read() {
  return measurePh();
}

void PhController::write(double output) {
  flowMs((int)output);
}

// Read the pH value
double PhController::measurePh(void) {
  double vin = (double(analogRead(_ph_pin)) / 1023.0) * 5.0;
  return (_m * (double)vin) + _c;
}

void PhController::calibrate(double ph_4, double ph_10) {
  // Calculate the linear model
  _m = 6 / (ph_10 - ph_4);
  _c = 10 - (_m * ph_10);
}

// Between 0ms and 500ms of flow (+ve means alkali, -ve means acid)
void PhController::flowMs(int flow_time) {
  if(flow_time > 0) {
    digitalWrite(_alkali_pin, HIGH);
    delay(flow_time);
    digitalWrite(_alkali_pin, LOW);
  } else if (flow_time < 0) {
    digitalWrite(_acid_pin, HIGH);
    delay(abs(flow_time));
    digitalWrite(_acid_pin, LOW);
  }
}
