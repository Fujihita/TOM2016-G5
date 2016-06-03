/*
_______________________________________________________________________

   Motor.h - Motor control library for EPROCON 2014
   Created by Nguyen Tung, January 13, 2014
   Vietnamese German University
   Internal use only
_______________________________________________________________________
*/

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