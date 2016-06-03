/*
_______________________________________________________________________

   Motor.cpp - Motor control library for EPROCON 2014
   Created by Nguyen Tung, January 13, 2014
   Vietnamese German University
   Internal use only
_______________________________________________________________________
*/

#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int spPin, int dirPin)
{
  pinMode(spPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  _spPin = spPin;
  _dirPin = dirPin;
  _base = 100;
}

void Motor::run(int sp)
{
  sp = constrain(sp, - _base, _base);
  if (sp < 0)
  {
    digitalWrite(_dirPin, HIGH);
  }
  else
  {
    digitalWrite(_dirPin, LOW);
  }
  analogWrite(_spPin, sp);
}

void Motor::base(int base)
{
  _base = base;
}