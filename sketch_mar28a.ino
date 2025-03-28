#include "pitches.h"
#define speaker A0
#define BLUE 6
#define GREEN 5
#define RED 3

int NOTE_DUR = 100;
const int button1 = 11;
const int button2 = 12;
const int button3 = 13;

void setup() {
  /*************************************************
 * Public Constants
 *************************************************/

  //setup buttons
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);

  //setup LEDs
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);

}

void play (int note, int dur) {
  
  tone(speaker, note);
  delay(dur * NOTE_DUR);
  noTone(speaker);
  delay(dur * NOTE_DUR / 3);

}

void rest (int dur) {
  noTone(speaker);
  delay(dur * NOTE_DUR);
}

void playGMajorScale() {
  analogWrite(RED, 0);
  analogWrite(BLUE, 150);
  analogWrite(GREEN, 200);
  play(NOTE_G3, 4);
  play(NOTE_A3, 4);
  play(NOTE_B3, 4);
  play(NOTE_C4, 4);
  play(NOTE_D4, 4);
  play(NOTE_E4, 4);
  play(NOTE_FS4, 4);
  play(NOTE_G4, 4);
  play(NOTE_FS4, 4);
  play(NOTE_E4, 4);
  play(NOTE_D4, 4);
  play(NOTE_C4, 4);
  play(NOTE_B3, 4);
  play(NOTE_A3, 4);
  play(NOTE_G3, 4);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(button3) == HIGH) {
    playGMajorScale();
  }
}
