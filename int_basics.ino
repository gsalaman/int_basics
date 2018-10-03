
#include <PinChangeInt.h>
 
const byte ledPin = 13;
volatile byte state = LOW;
 
void setup()
{
   pinMode(ledPin, OUTPUT);
   pinMode(A0, INPUT_PULLUP);
   PCintPort::attachInterrupt(A0, isr, CHANGE);
}
 
void loop()
{
   digitalWrite(ledPin, state);
}
 
void isr() 
{
   state = !state;
}
