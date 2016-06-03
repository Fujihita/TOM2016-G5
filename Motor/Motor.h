#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor
{
  public:
  Motor(int spPin, int dirPin);
  void run(int sp);
  void base(int base);
  
  private:
  int _base;
  int _spPin;
  int _dirPin;  
};

#endif