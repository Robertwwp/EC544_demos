/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

/* Modified September 1st, 2017
   EC544 Fall 2017
   Emily Lam */

#include <IRremote.h>

// Commands
#define OFF     0xA90
#define RED     0xB90
#define GREEN   0xC90
#define BLUE    0xD90
#define YELLOW  0xE90
#define HAZARD  0xF90

int RECV_PIN = 11;
int rLED = 2;
int gLED = 3;
int bLED = 4;
int yLED = 5;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  pinMode(rLED, OUTPUT);
  pinMode(gLED, OUTPUT);
  pinMode(bLED, OUTPUT);
  pinMode(yLED, OUTPUT);
}

// Read and decode, show appropriate LED status
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
    if (results.value == OFF) {
      digitalWrite(rLED, LOW);
      digitalWrite(gLED, LOW);
      digitalWrite(bLED, LOW);
      digitalWrite(yLED, LOW);
    }
    else if (results.value == RED) {
      digitalWrite(rLED, HIGH);
      digitalWrite(gLED, LOW);
      digitalWrite(bLED, LOW);
      digitalWrite(yLED, LOW);
    }
    else if(results.value == GREEN) {
      digitalWrite(rLED, LOW);
      digitalWrite(gLED, HIGH);
      digitalWrite(bLED, LOW);
      digitalWrite(yLED, LOW);
    }
    else if (results.value == BLUE) {
      digitalWrite(rLED, LOW);
      digitalWrite(gLED, LOW);
      digitalWrite(bLED, HIGH);
      digitalWrite(yLED, LOW);
    }
    else if (results.value == YELLOW) {
      digitalWrite(rLED, LOW);
      digitalWrite(gLED, LOW);
      digitalWrite(bLED, LOW);
      digitalWrite(yLED, HIGH);
    }
    else if (results.value == HAZARD) {
      digitalWrite(rLED, HIGH);
      digitalWrite(gLED, HIGH);
      digitalWrite(bLED, HIGH);
      digitalWrite(yLED, HIGH);
    }
  }
  delay(10);
}
