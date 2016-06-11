#define   KeyPadCol1    0
#define   KeyPadCol2    1
#define   KeyPadCol3    2
#define   KeyPadRow1    3
#define   KeyPadRow2    4 
#define   KeyPadRow3    5
#define   KeyPadRow4    6
#define   cols     3
#define   rows     4

#define   MotorSpd1     A0
#define   MotorDir1     A1

#define   MotorSpd2     A2
#define   MotorDir2     A3

#define   MotorSpd3     A4
#define   MotorDir3     A5

#define   MotorSpd4     11
#define   MotorDir4     12

//load default pin mapping
  Finger finger1 (MotorSpd1, MotorDir1); // create motor 1 object
  Finger finger2 (MotorSpd2, MotorDir2); // create motor 2 object
  Finger finger3 (MotorSpd3, MotorDir3); // create motor 3 object
  Finger finger4 (MotorSpd4, MotorDir4); // create motor 4 object

/*Motor motor (MotorSpd1, MotorDir1);
Motor motor1 (MotorSpd1, MotorDir1);
Motor motor2 (MotorSpd2, MotorDir2);
Motor motor3 (MotorSpd3, MotorDir3);
Motor motor4 (MotorSpd4, MotorDir4);*/

//declare timer
unsigned long timer = 0;
unsigned long ex_timer = 0;

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
