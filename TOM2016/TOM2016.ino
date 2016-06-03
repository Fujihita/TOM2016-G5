#include <Motor.h> // include Motor control library
#include <Keypad.h>

#define   KeyPadCol1    3
#define   KeyPadCol2    4
#define   KeyPadCol3    5
#define   KeyPadRow1    6
#define   KeyPadRow2    7
#define   KeyPadRow3    8
#define   KeyPadRow4    9
#define   cols     3
#define   rows     4

#define   MotorSpd1     3
#define   MotorDir1     2

#define   MotorSpd2     5
#define   MotorDir2     4

#define   MotorSpd3     6
#define   MotorDir3     7

#define   MotorSpd4     9
#define   MotorDir4     8

#define   TimeDelay     2000
#define   TimeDebounce  50

//load default pin mapping
  Motor motor1 (MotorSpd1, MotorDir1); // create motor 1 object
  Motor motor2 (MotorSpd2, MotorDir2); // create motor 2 object
  Motor motor3 (MotorSpd3, MotorDir3); // create motor 2 object
  Motor motor4 (MotorSpd4, MotorDir4); // create motor 2 object

//declare timer
long timer = 0;

//setup keypad
char keys[rows][cols] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[rows] = {KeyPadRow4, KeyPadRow3, KeyPadRow2, KeyPadRow1}; //connect to the row pinouts of the keypad
byte colPins[cols] = {KeyPadCol3, KeyPadCol2, KeyPadCol1}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );

void setup()
{
  Serial.begin(9600);
/*  
//initialize starting values
  motor1.base(255);
  motor2.base(255);
  motor3.base(255);
  motor4.base(255);
  
  motor1.run(0);
  motor2.run(0);
  motor3.run(0);
  motor4.run(0);
*/
}

void loop()
{
  char key = keypad.getKey();

  if (key != NO_KEY){
    Serial.println(key);
/* if(digitalRead(IN1) == HIGH)
 {
  motor1.run(255);
  motor2.run(255);
  motor3.run(255);
  motor4.run(255);
 }
 else
 {
  motor1.run(0);
  motor2.run(0);
  motor3.run(0);
  motor4.run(0);
 }
*/ 
}
}
