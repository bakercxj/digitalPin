/*
* Example sketch using the "digitalPins" library.
*
* Reads a switch on pin D2, toggles the builtin LED.
*
* Norman Dunbar
* 26 August 2021.
*/
// Include the library header.

#define LED_PIN 2


#include "digitalPin.h"
// Create a digitalPin connected to the built in LED
// and configure it as output.
digitalPin ledPin(LED_PIN, OUTPUT);
// And another attached to D2, configured as an input
// with pullup.
digitalPin switchPin(1, INPUT_PULLUP);


void setup() 
{
// No setup specifically required, but quick
// flash the LED a couple of times "manually".
  for (byte x = 0; x < 5; x++) 
  {
    ledPin.setState(HIGH);
    delay(250);
    ledPin.setState(LOW);
    delay(100);
  }
// Delay before starting the loop.
  delay(1500);
}


void loop() {
// Read the switch and if pressed, toggle
// the built in LED.
// BEWARE: Without debouncing, this might be
// somewhat random.
  if (switchPin.getState() == LOW) 
  {
// Switch pressed, toggle the ledPin.
    ledPin.toggleState();
  }
// A small delay.
  delay(200);
}