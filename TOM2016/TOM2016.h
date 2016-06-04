#define   KeyPadCol1    3
#define   KeyPadCol2    4
#define   KeyPadCol3    5
#define   KeyPadRow1    6
#define   KeyPadRow2    7 // omitted
#define   KeyPadRow3    8
#define   KeyPadRow4    9
#define   cols     3
#define   rows     3

#define   MotorSpd1     11
#define   MotorDir1     10

#define   MotorSpd2     A0
#define   MotorDir2     A1

#define   MotorSpd3     A2
#define   MotorDir3     A3

#define   MotorSpd4     A4
#define   MotorDir4     A5

#define   TimeDelay     2000
#define   TimeDebounce  50

//load default pin mapping
  Finger finger1 (MotorSpd1, MotorDir1); // create motor 1 object
  Finger finger2 (MotorSpd2, MotorDir2); // create motor 2 object
  Finger finger3 (MotorSpd3, MotorDir3); // create motor 3 object
  Finger finger4 (MotorSpd4, MotorDir4); // create motor 4 object

//Motor motor (MotorSpd1, MotorDir1);
//declare timer
unsigned long timer = 0;
unsigned long ex_timer = 0;

//setup keypad
char keys[rows][cols] = {
  {'1','2','3'},
  {'4','5','6'},
  {'*','0','#'}
};
byte rowPins[rows] = {KeyPadRow4, KeyPadRow3, KeyPadRow1}; //connect to the row pinouts of the keypad
byte colPins[cols] = {KeyPadCol3, KeyPadCol2, KeyPadCol1}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );
