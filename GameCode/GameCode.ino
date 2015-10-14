
/*
 * YOU HAVE BEEN BLINDED AND THROWN IN A DUNGEON
 * Alex Myers && Jeff Thompson
 * 2012 (updated 2015)
 * 
 * THINGS TO TWEAK IN YOUR INSTALL
 * -- you may need to change the button thresholds
 */

boolean ledFeedback =   true;       // play patterns on the LED?

const int width =       20;         // width of the level
const int height =      20;         // ditto height

// level stored as 2D array
byte level[height][width] = {
  {3, 4, 3, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1},
  {2, 3, 3, 3, 3, 1, 2, 2, 1, 2, 2, 1, 1, 2},
  {2, 2, 3, 3, 3, 1, 2, 2, 1, 2, 1, 1, 1, 2},
  {2, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2},
  {2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 2, 1, 2, 2},
  {3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
  {1, 3, 2, 1, 2, 2, 2, 2, 2, 2, 2, 1, 2, 3},
  {1, 3, 3, 3, 3, 3, 3, 2, 2, 1, 2, 2, 2, 3},
  {1, 3, 3, 3, 1, 1, 1, 3, 2, 2, 3, 2, 2, 3},
  {1, 3, 1, 1, 1, 1, 3, 3, 3, 2, 2, 2, 2, 2},
  {3, 3, 1, 2, 2, 2, 3, 1, 1, 1, 1, 2, 2, 2},
  {2, 2, 2, 1, 1, 2, 1, 3, 3, 3, 3, 2, 1, 1},
  {2, 2, 2, 3, 3, 0, 3, 3, 1, 1, 2, 3, 2, 2},
  {1, 1, 2, 3, 3, 2, 1, 1, 1, 2, 2, 2, 2, 1}
};

// player coordinates
const int startX =    5;
const int startY =    12;
char prevDir =        ' ';      // store previous button state (prevents retriggering)
int x, y;

// pins
const int motor =     0;        // ATtiny: 0, Arduino: 13
const int buttons =   3;        // ATtiny: 3, Arduino 0
const int led =       1;        // on "fancy badges" only

// intro to be played as morse code at the start
boolean morseIntro =  true;     // false = do not play

// "you have been blinded and thrown in a dungeon..."
char intro[] = { "-.-- --- ..- .... .- ...- . -... . . -. -... .-.. .. -. -.. . -.. .- -. -.. - .... .-. --- .-- -. .. -. .- -.. ..- -. --. . --- -. .-.-.-" };

const int refreshRate = 50;


void setup() {
  pinMode(motor, OUTPUT);
  pinMode(led, OUTPUT);

  // set initial player position
  resetPlayerPosition();

  // if testing on regular Arduino, print the level over USB
  // comment out or delete for final code on ATtiny
  // Serial.begin(9600);
  // printLevel();

  // play that intro, please
  if (morseIntro) morseCode(intro, sizeof(intro));
}


void loop() {
  char dir = checkButtons();
  if (dir != prevDir) {
    movePlayer(dir);
    // printLevel();
  }
  prevDir = dir;
  
  delay(refreshRate);
}


