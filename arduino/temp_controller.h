#ifndef TEMP_CONTROLLER_H
#define TEMP_CONTROLLER_H

#include "pid.h"

class TempController : public Controller {
  public: 
    TempController(int heater_pin, int thermister_pin);
    double read();
    void write(double ouput);

    void setHeaterOutput(int output);
    void calibrate(double r_fix, double a1, double a2, double a3);
    double measureTemp(void);
    
  private:
    int _heater_pin = 9;
    int _thermister_pin = 10;
    double _r_fix;
    double _a1, _a2, _a3;
};
#endif
