//Elijah Story
//11-6-2020
//NMD211 Lab8

//This is the current state of my lantern. 
//I have a button set up to manually turn the lantern on/off. 
//When the lantern is on, it has a flickering effect. 
//While it is on, the motion sensor detects somebody, 
//the light turns off for 3 seconds. After the time has passed, 
//it turns back on and flickers.

int lanternLed = 11;            // pin for lantern LED
int sensorInput = 8;            // input pin (for PIR sensor)
int buttonInput = 7;            // input for button

int val = 0;                    // variable for reading the PIR status
boolean state = false;          // if the sensor input is "on"
int button = 0;                 // if the button is pressed
int buttonLast = 0;             // stores what the button was last pressed
int level = 100;                // stores the random level of power for LED
double curTime;                 // this will hold the current time
double pastTime = 0;            // this will hold the last time that was collected
int randDelay;                  //this is the delay between LED levels

void setup() {
  pinMode(lanternLed, OUTPUT);  // declare LED as output
  pinMode(sensorInput, INPUT);  // declare sensor as input
  pinMode(buttonInput, INPUT);  // declare button as input

  Serial.begin(9600);
}

void loop() {
  Serial.println(state);              //prints the "on/off" sensor status
  button = digitalRead(buttonInput);  //gets button input
  if (button == HIGH) {               //if the button is pressed
    if(button != buttonLast){         //if the button is opposite last status
      state = !state;                 //changes the "state" of state
    }
  }
  buttonLast = button;                //updates the last button status

  if (!state) {
    digitalWrite(lanternLed, 0);  // turn button LED OFF
  }

  val = digitalRead(sensorInput);  // read input value

  if (val == LOW) { // check if the input is LOW "PIR sees nothing"
    if (state) {                        //if the button is "on"
      analogWrite(lanternLed, level);   // turn lantern LED ON
      curTime = millis();               //get the current time
      if(curTime - pastTime >= randDelay){  //if the time that has passed is greater delay
        level = random(50,255);             //pick a new power level for LED
        randDelay = random(50,200);         //pick new delay time
        pastTime = curTime;                 //update the past time
      }
    }

  } else {//PIR sees something
    digitalWrite(lanternLed, 0);  // turn lantern LED OFF
  }
}
