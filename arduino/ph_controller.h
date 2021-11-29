#ifndef PH_CONTROLLER_H
#define PH_CONTROLLER_H

#include "pid.h"

class PhController : public Controller {
  public:
    PhController(int ph_pin, int acid_pin, int alkali_pin);
    double read();
    void write(double output);

    // Calibrating the internal linear model by passing in reading @ 5pH and 9pH
    void calibrate(double ph_5, double ph_9);
    double measurePh(void);
    void flowMs(int flow_time);

  private:
    int _ph_pin = 9;
    int _acid_pin = 10;
    int _alkali_pin = 11;

    // Calibration values
    double _m, _c;
};

#endif
