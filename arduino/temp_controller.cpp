#include "temp_controller.h"
#include "Arduino.h"

// Reference: http://web.cecs.pdx.edu/~eas199/B/howto/thermistorArduino/thermistorArduino.pdf

// Initialises the controller and its pins
TempController::TempController(int heater_pin, int thermister_pin) {
  // Setting up the output and input pin
  _heater_pin = heater_pin;
  _thermister_pin = thermister_pin;
  pinMode(_heater_pin, OUTPUT);
  pinMode(_thermister_pin, INPUT);

  // Default calibration values
  // Fixed resistor measured resistance for calibration
  _r_fix = 10000.0;

  // Default Co-efficients in the Steinhart-Hart equation
  _a1 =  1.009249522e-03;
  _a2 = 2.378405444e-04;
  _a3 = 2.019202697e-07;
}

// Parsing the temperature data into double
double TempController::read(void) {
  return measureTemp();
}

// Parsing the output into PWM 0-255 range
void TempController::write(double output) {
  // Clamp the output values
  int o = (int)output;
  if( o > 255) o = 255;
  else if(o < 0) o = 0;

  setHeaterOutput(o);
}

void TempController::calibrate(double r_fix, double a1, double a2, double a3) {
  _r_fix = r_fix;
  _a1 = a1;
  _a2 = a2;
  _a3 = a3;
}

// Returns the temperature in Celsius
double TempController::measureTemp(void) {
  int vin = analogRead(_thermister_pin);
  double rt = _r_fix * ((1023.0 / double(vin)) - 1.0);
  double log_rt = log(rt);

  return (1.0/(_a1 + _a2*log_rt + _a3*log_rt*log_rt*log_rt)) - 273.15;
}

// Controls the output power of the heater
// (value from 0-255)
void TempController::setHeaterOutput(int output) {
  analogWrite(_heater_pin, output);
}
