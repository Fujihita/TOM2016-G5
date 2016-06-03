#include <Motor.h> // include Motor control library
#include <Button.h>

#define   IN1      A0
#define   IN2      A1
#define   IN3      A2
#define   IN4      A3
#define   IN5      A4
#define   IN6      A5

#define   MotorSpd1     3
#define   MotorDir1     2

#define   MotorSpd2     5
#define   MotorDir2     4

#define   MotorSpd3     6
#define   MotorDir3     7

#define   MotorSpd4     11
#define   MotorDir4     12

#define   TimeDelay     2000
#define   TimeDebounce  50

//load default pin mapping
  Motor motor1 (MotorSpd1, MotorDir1); // create motor 1 object
  Motor motor2 (MotorSpd2, MotorDir2); // create motor 2 object
  Motor motor3 (MotorSpd3, MotorDir3); // create motor 2 object
  Motor motor4 (MotorSpd4, MotorDir4); // create motor 2 object
  Button button1 (IN1, TimeDebounce);
  Button button2 (IN2, TimeDebounce);
  Button button3 (IN3, TimeDebounce);
  Button button4 (IN4, TimeDebounce);
  Button button5 (IN5, TimeDebounce);
  Button button6 (IN6, TimeDebounce);

//declare timer
long timer = 0;

void setup()
{
//initialize starting values
  motor1.base(255);
  motor2.base(255);
  motor3.base(255);
  motor4.base(255);
  
  motor1.run(0);
  motor2.run(0);
  motor3.run(0);
  motor4.run(0);
}

void loop()
{
  motor1.run(100);
  motor2.run(100);
  motor3.run(100);
  motor4.run(100);
  delay(2000);
  motor1.run(255);
  motor2.run(255);  
  delay(2000);
  motor1.run(0);
  motor2.run(0); 
  delay(2000);
 /*if(button1.read())
 {
    // function of button 1 
 }
 if(button2.read())
 {
    // function of button 2
 } */
}

