#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include "pid.h"

class MotorController : public Controller {
  public:
    MotorController(int motor_pin, int encoder_pin);
    double read();
    void write(double output);
    int measureSpeed(void);
    void setMotorOutput(int output);

  private:
    int _motor_pin = 9;
    int _encoder_pin = 10;
};

#endif
