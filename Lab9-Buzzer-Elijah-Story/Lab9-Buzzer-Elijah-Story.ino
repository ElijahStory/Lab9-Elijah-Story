//Elijah Story
//11-27-2020
//NMD211 Lab9 

//Everything below was taken from the tutorial page in the lab folder.
//I did change the melody.

/* Plays a melody - circuit: 8-ohm speaker on digital pin 8 */

#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_B4, NOTE_D5, NOTE_D5, NOTE_F5, NOTE_E5, NOTE_E5, NOTE_B4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4};

int lengthInt = 10;

void setup() {
}

void loop() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < lengthInt; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}