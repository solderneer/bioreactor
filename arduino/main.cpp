#include "Arduino.h"
#include "temp_controller.h"

#define HEATER_PIN 6
#define THERMISTER_PIN A0
  
TempController tc(HEATER_PIN, THERMISTER_PIN);

void setup() {
}

void loop() {
  int temp = tc.measureTemp();
  Serial.println(temp);
  tc.setHeaterOutput(100);
}
