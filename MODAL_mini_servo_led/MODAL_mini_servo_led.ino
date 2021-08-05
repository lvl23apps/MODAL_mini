/* Modal V1 Servo and Led code for the Arduino that is used to drive MODAL|mini.
 * Your setup may differ and you will want to change the code to reflect that for
 * your configuration and build. I claim no mastery in writting this code and 
 * encourage you to make it better. 
 * 
 * The code below is written to be able to handle a servo directly connected to the
 * Arduino instead of 5v line. This is not ussually the reccomended path but because 
 * this is a 9G servo it can handle being driven by 3.7V without issue. There is of
 * course still motor noise when holding a far position so I added a servo.detach to
 * help stop this. It isnt perfect and I am looking into different ways to drive it
 * with lower power.
*/

#include <Servo.h>

Servo topservo;
Servo botservo; /* left side */
Servo boxservo; /* right side */

// twelve servo objects can be created on most boards

const int ledIn = 2;
int topL = 140; // tested to 135
int topR = 75; // tested to 95
int topmid = 80; // 115

int toppos = topmid;

/* LED Stuff */

int led = 13;           // the PWM pin the LED is attached to
int led2 = 12;           // the PWM pin the LED is attached to
int led3 = 11;           // the PWM pin the LED is attached to
int led4 = 10;           // the PWM pin the LED is attached to
int brightness = 5;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

void setup() {
  pinMode(ledIn, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  topservo.attach(9);

  topservo.write(topmid);

  digitalWrite(LED_BUILTIN, HIGH);
  delay(15000);

    // declare leds to be an output:
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  toppos = random(topR, topL);
  topservo.attach(9);
  
  topservo.write(toppos);
    if (toppos > 120) {
    topservo.detach();
  }
 
  delay(10000);
  
  // set the brightness of leds:
  analogWrite(led, brightness);
  analogWrite(led2, brightness);
  analogWrite(led3, brightness);
  analogWrite(led4, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 5 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(5);
}

void openBox() {
  delay(6000);
  topservo.detach();
 }
