/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

/* Modified September 1st, 2017
   EC544 Fall 2017
   Emily Lam */


#include <IRremote.h>

// Commands in hexadecimal bytes
#define OFF     0xA90
#define RED     0xB90
#define GREEN   0xC90
#define BLUE    0xD90
#define YELLOW  0xE90
#define HAZARD  0xF90

IRsend irsend;      // IR tx -- pin 3

// Pin define
int buttonPin = 2;
int rLED = 11;
int gLED = 12;
int bLED = 13;
int yLED = 10;

// Initial States
int buttonState = 0;
int stateLED = 0;
int numStates = 5;

void setup() {
  Serial.begin(9600);
  pinMode(rLED, OUTPUT);
  pinMode(gLED, OUTPUT);
  pinMode(bLED, OUTPUT);
  pinMode(yLED, OUTPUT);
  pinMode(buttonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), changeState, FALLING);
}

// Rotate through sending 5 different states on button push
void loop() {
  switch (stateLED) {
    case 0:
      digitalWrite(rLED, LOW);
      digitalWrite(gLED, LOW);
      digitalWrite(bLED, LOW);
      digitalWrite(yLED, LOW);
      Serial.println("OFF");
      for (int i = 0; i < 3; i++) {
        irsend.sendSony(OFF, 12);
        delay(40);
      }
      break;
    case 1:    // your hand is close to the sensor
      digitalWrite(rLED, HIGH);
      digitalWrite(gLED, LOW);
      digitalWrite(bLED, LOW);
      digitalWrite(yLED, LOW);
      Serial.println("RED");
      for (int i = 0; i < 3; i++) {
        irsend.sendSony(RED, 12);
        delay(40);
      }
      break;
    case 2:
      digitalWrite(rLED, LOW);
      digitalWrite(gLED, HIGH);
      digitalWrite(bLED, LOW);
      digitalWrite(yLED, LOW);
      Serial.println("GREEN");
      for (int i = 0; i < 3; i++) {
        irsend.sendSony(GREEN, 12);
        delay(40);
      }
      break;
    case 3:
      digitalWrite(rLED, LOW);
      digitalWrite(gLED, LOW);
      digitalWrite(bLED, HIGH);
      digitalWrite(yLED, LOW);
      Serial.println("BLUE");
      for (int i = 0; i < 3; i++) {
        irsend.sendSony(BLUE, 12);
        delay(40);
      }
      break;
    case 4:
      digitalWrite(rLED, LOW);
      digitalWrite(gLED, LOW);
      digitalWrite(bLED, LOW);
      digitalWrite(yLED, HIGH);
      Serial.println("YELLOW");
      for (int i = 0; i < 3; i++) {
        irsend.sendSony(YELLOW, 12);
        delay(40);
      }
      break;
      case 5:
      digitalWrite(rLED, HIGH);
      digitalWrite(gLED, HIGH);
      digitalWrite(bLED, HIGH);
      digitalWrite(yLED, HIGH);
      Serial.println("HAZARD");
      for (int i = 0; i < 3; i++) {
        irsend.sendSony(HAZARD, 12);
        delay(40);
      }
      break;
  }

}


void changeState() {
    if (stateLED == numStates) {
      stateLED = 0;
    }
    else {
      stateLED = stateLED + 1;
    }
    delay(500);
}
