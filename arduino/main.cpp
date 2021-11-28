#include "Arduino.h"
#include "temp_controller.h"
#include "pid.h"

#define HEATER_PIN 6
#define THERMISTER_PIN A0
  
TempController tc(HEATER_PIN, THERMISTER_PIN);
PIDSystem temp(&tc, 1000);

void setup() {
  // Setting up the parameters
  temp.setParameters(1.0, 10.0, 5.0);
  temp.setLimits(0.0, 255.0);
  temp._setpoint = 30.0;
}

void loop() {
  /*
  int temp = tc.measureTemp();
  Serial.println(temp);
  tc.setHeaterOutput(0);*/
  temp.run();
}
