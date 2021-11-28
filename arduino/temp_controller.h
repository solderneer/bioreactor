#ifndef TEMP_CONTROLLER_H
  #define TEMP_CONTROLLER_H

  class TempController {
    public:
      int m_set_point = 35;
      int m_heater_pin = 9;
      int m_thermister_pin = 10;
      
      TempController(int heater_pin, int thermister_pin);
      void setHeaterOutput(int output);
      int measureTemp(void);
  };
#endif
