#include "Arduino.h"
#include "Motor.h"
#include "Finger.h"

Finger::Finger(int spPin, int dirPin) : _motor(spPin, dirPin)
{
  _motor.base(255);
  _timeout = 3000; //3 secs
  _dir = false;
  _status = 0;
  _timer = millis();
  _offset = 0;
  lock();
}

void Finger::timeout(unsigned long timeout){
    _timeout = timeout;    
}

void Finger::lock(){
_motor.run(0);
/*
	_setLock();
	_status = 0;
	Serial.print("From lock: ");
	Serial.println(_offset);
*/
}

void Finger::reset(){
	_status = 1;
	// start _motor in reverse direction
	if (_offset > 0)
	{
		_motor.run(-255);
		_dir = true;
	}
	else
	{
		_motor.run(255);
		_dir = false;
	}
	_timer = millis();
	Serial.print("From reset: ");
	Serial.println(_offset);
}

void Finger::unlock(){
_motor.run(255);
/*
	_status = 2;
	_timer = millis();
	Serial.print("From unlock: ");
	Serial.println(_offset);
	Serial.println(_dir);	
*/
}

void Finger::run(){
	switch(_status)
	{
		case 1:
		{
			_backToStart();
			break;
		}
		case 2:
		{
			_releaseLock();
			break;
		}
	}
}

// Private functions

void Finger::_setLock()
{
   // function to lock a finger in place
   _motor.run(0);
}

void Finger::_releaseLock()
{
  	// function fo free a finger
	if (_offset > _timeout)
	{
		_motor.run(-255);
		_dir = true;
	}
	else if (_offset < -_timeout)
	{
		
		_motor.run(255);
		_dir = false;
	}
if(_dir)
_offset = _offset - (millis() - _timer);
else
_offset = _offset + (millis() - _timer);

_timer = millis();
}

void Finger::_backToStart()
{
	if (_dir)
	_offset = _offset - (millis() - _timer);
	else
	_offset = _offset + (millis() - _timer);

  	// function fo reset a finger
  	if (((_offset > 0) && _dir) || ((_offset < 0) && !_dir))
	{
		lock();
	}
	_timer = millis();
}