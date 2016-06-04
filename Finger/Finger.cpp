#include "Arduino.h"
#include "Motor.h"
#include "Finger.h"

Finger::Finger(int spPin, int dirPin) : _motor(spPin, dirPin)
{
  _motor.base(255);
  _timeout = 6000; //3 secs
  _dir = true;
  _status = 0;
  _offset = 0;
  
  _timer = millis();	
  lock();
}

void Finger::timeout(unsigned long timeout){
    _timeout = timeout;    
}

void Finger::lock(){
//_motor.run(0);
	_setLock();
	_status = 0;
	Serial.print("From lock: ");
	Serial.println(_offset);

}

void Finger::reset(){
	_status = 1;
	// start motor in reverse direction
	if (_dir)
	{
		_dir = false;
		_offset = _timeout - _offset; 	// inverse offset progress
	}
	
	Serial.print("From reset: ");
	Serial.println(_offset);
}

void Finger::unlock(){
//_motor.run(255);
	_status = 2;
	Serial.print("From unlock: ");
	Serial.println(_offset);
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
	_timer = millis();
}

// Private functions

void Finger::_setLock()
{
   // function to lock a finger in place
   _motor.run(0);
}

void Finger::_releaseLock()
{
	_offset = _offset + (millis() - _timer);
  	// function fo free a finger
	if (_offset > _timeout)
	{
		_motor.run(-255);
		_dir = false;
		_offset = 0;
	}
	else if (_offset < 0)
	{
		_motor.run(255);
		_dir = true;
		_offset = 0;
	}
}

void Finger::_backToStart()
{
	_offset = _offset + (millis() - _timer);
  	// function fo reset a finger
  	if (_offset > _timeout)
	{
		_dir = true;
		_offset = 0;
		lock();
	}
}