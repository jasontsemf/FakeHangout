/*
   IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
   An IR LED must be connected to Arduino PWM pin 3.
   Version 0.1 July, 2009
   Copyright 2009 Ken Shirriff
   http://arcfn.com
*/



#include <IRremote.h>
#define SEND_PIN  5
const int buttonPin = 8;
int buttonState = 0;
IRsend irsend;

void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    // turn LED on:
    Serial.println("high");
  } else {
    // turn LED off:
    Serial.println("low");
    for (int i = 0; i < 3; i++) {
      irsend.sendSony(0xa90, 12);
      delay(40);
    }
    delay(5000); //5 second delay between each signal burst
  }

  //	for (int i = 0; i < 3; i++) {
  //		irsend.sendSony(0xa90, 12);
  //		delay(40);
  //	}
  //	delay(5000); //5 second delay between each signal burst
}
