#ifndef CONTROLLER_H
#define CONTROLLER_H

#define MANUAL 0
#define AUTOMATIC 1

// Heavily inspired by http://brettbeauregard.com/blog/2011/04/improving-the-beginners-pid-introduction/

// ABC for all subsystem controllers
class Controller {
  public:
    virtual double read() = 0;
    virtual void write(double output) = 0;
};

typedef struct {
  double input;
  double output;
  double kp;
  double ki;
  double kd;
} PIDLog;


class PIDSystem {
  public:
    double _setpoint;

    PIDSystem(Controller* controller, int sample_time);
    void run(void);
    void setParameters(double kp, double ki, double kd); 
    void setLimits(double out_min, double out_max);
    void setMode(int mode);
    PIDLog log(void);

  private:
    Controller* _controller;

    unsigned long _last_time = 0;
    int _sample_time = 1000;
    int _mode = 1;

    double _kp, _ki, _kd;
    double _iterm, _last_input;
    double _input, _output;
    double _out_min, _out_max;
};
#endif
