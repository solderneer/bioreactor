#include "Arduino.h"
#include "temp_controller.h"
#include "pid.h"

#define HEATER_PIN 6
#define THERMISTER_PIN A0
  
TempController tc(HEATER_PIN, THERMISTER_PIN);
PIDSystem temp(&tc, 1000);

const int log_time = 1000;
unsigned long last_time = 0;

void setup() {
  // Setting up the parameters
  temp.setParameters(1.0, 1.0, 1.0);
  temp.setLimits(0.0, 255.0);
  temp._setpoint = 600.0;

  Serial.begin(9600);
}

void loop() {
  /*
  int temp = tc.measureTemp();
  Serial.println(temp);
  tc.setHeaterOutput(0);*/
  temp.run();

  unsigned long now = millis();
  int time_change = now - last_time;

  if(time_change >= log_time) {
    temp.print();
    last_time = now;
  }
}
