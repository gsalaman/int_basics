//Next iteration:  pin change interrupts.

const byte ledPin = 13;
volatile byte state = LOW;
 
void setup()
{
   pinMode(ledPin, OUTPUT);
   pinMode(A0, INPUT_PULLUP);
   PCMSK1 = B00000001;  
   PCIFR =  B00000000;
   PCICR =  B00000010;
}
 
void loop()
{
   digitalWrite(ledPin, state);
}
 
ISR(PCINT1_vect)
{
   state = !state;
}
