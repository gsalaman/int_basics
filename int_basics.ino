// First iteration: using HW interrupt, pin 2.
#include "ver_led.h"

const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;
 
void setup()
{
   ver_led_setup(2);
   pinMode(ledPin, OUTPUT);
   pinMode(interruptPin, INPUT_PULLUP);
   attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
}
 
void loop()
{
   digitalWrite(ledPin, state);
   ver_led_run();
}
 
void blink()
{
   state = !state;
}
