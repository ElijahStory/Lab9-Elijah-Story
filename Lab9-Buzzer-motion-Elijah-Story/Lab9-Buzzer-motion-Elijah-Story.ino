//Elijah Story
//11-27-2020
//NMD211 Lab9 

//Most of the note stuff below was taken from the tutorial page in the lab folder.
//The code loops through a song but pauses when motion is detected.


/* Plays a melody - circuit: 8-ohm speaker on digital pin 8 */

#include "pitches.h"

// notes in the melody:
int melody[] = {NOTE_E5, NOTE_G5, NOTE_C5, NOTE_B4, NOTE_D5, NOTE_D5, NOTE_F5, NOTE_E5, NOTE_E5, NOTE_B4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4};

int lengthInt = 10;     //length of the song
int thisNote = 0;       //current index of the notes
int lastTime = 0;       //the last time a note was played
int noteDuration;       //how long the notes last
int motionPin = 7;      //input pin for the motion sensor
int pinInput = 0;       //the input for the motion sensor


void setup() {
  pinMode(motionPin, INPUT);
}

void loop() {
  int pauseBetweenNotes = noteDuration * 1.30;    //set the pause delay
  pinInput = digitalRead(motionPin);              //read in the sensor
  int elapsed = millis() - lastTime;              //check the elapsed time

  //if no motion is detected and enough time has passed
  if(pinInput == LOW && pauseBetweenNotes <= elapsed){
    noteDuration = 1000 / noteDurations[thisNote];    //update the duration
    tone(8, melody[thisNote], noteDuration);          //play the note
    if(thisNote == lengthInt-1){                      //if the index is the same size as the length of song
      thisNote = 0;                                   //reset index
    }else{
      thisNote++;                                     //increment note index
    }
    lastTime = millis();                              //update last played
  }
}
