#include "temp_controller.h"
#include "Arduino.h"

// Initialises the controller and its pins
TempController::TempController(int heater_pin, int thermister_pin) {
  // Setting up the output and input pin
  _heater_pin = heater_pin;
  _thermister_pin = thermister_pin;
  pinMode(_heater_pin, OUTPUT);
  pinMode(_thermister_pin, INPUT);
}

// Parsing the temperature data into double
double TempController::read(void) {
  return (double)measureTemp();
}

// Parsing the output into PWM 0-255 range
void TempController::write(double output) {
  // Clamp the output values
  int o = (int)output;
  if( o > 255) o = 255;
  else if(o < 0) o = 0;

  setHeaterOutput(o);
}

// Returns the temperature in Celsius
int TempController::measureTemp(void) {
  return analogRead(_thermister_pin);
float voltage = o * 5.0;
voltage /= 1024.0; //converting voltage at thermistor pin to milivolts
float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree with 500 mV offset
                                               //to degrees ((voltage - 500mV) times 100)
  return (double)temperatureC();
  Serial.print(temperatureC); Serial.println(" degrees C");
}

// Controls the output power of the heater
// (value from 0-255)
void TempController::setHeaterOutput(int output) {
  analogWrite(_heater_pin, output);
}
