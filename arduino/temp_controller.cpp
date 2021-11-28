#include "Arduino.h"
#include "temp_controller.h"

// Initialises the controller and its pins
TempController::TempController(int heater_pin, int thermister_pin) {
  // Setting up the output and input pin
  m_heater_pin = heater_pin;
  m_thermister_pin = thermister_pin;
  pinMode(m_heater_pin, OUTPUT);
  pinMode(m_thermister_pin, INPUT);
}

// Returns the temperature in Celsius
int TempController::measureTemp(void) {
  return analogRead(m_thermister_pin);
}

// Controls the output power of the heater
// (value from 0-255)
void TempController::setHeaterOutput(int output) {
  analogWrite(m_heater_pin, output);
}
