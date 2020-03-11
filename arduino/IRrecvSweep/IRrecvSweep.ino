/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#include <IRremote.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos = 0;    // variable to store the servo position

int RECV_PIN = 9;

IRrecv irrecv(RECV_PIN);
int servopin = 4;
int pulse = 1500;
decode_results results;

void setup() {
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  pinMode(servopin, OUTPUT);
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    if (results.value == 2704) {
      digitalWrite(servopin, HIGH);
      delayMicroseconds(pulse);
      digitalWrite(servopin, LOW);
      for (pos = 0; pos <= 25; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(5);                       // waits 15ms for the servo to reach the position
      }
      delay(300);
      for (pos = 25; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(5);                       // waits 15ms for the servo to reach the position
      }
      //      irrecv.resume(); // Receive the next value
    }
    irrecv.resume(); // Receive the next value
  }
  delay(20);
}
