//3a: 
//The difference between pinMode(PIN, INPUT) and pinMode(PIN, INPUT_PULLUP) is the the latter will output a high value when the pin is left floating, while the former can output either randomly decided. 
//3b: 
//The ! operator is the NOT operator. In a binary sense, it invertes the bit, but when used with an equal symbol, it create the 'not equal to' function, outputting a high signal, if the two conditions are not the same. 
//3c: 
//1: Set bool isLatch to 0 to operate as a hold button
//2: Set bool isLatch to 1 to operate as a latch
//3d: 
//The program checks every 100ms, which we find to be reasonable, as it isn't likely to miss a button press, but isn't running all the time either

#include <Arduino.h>

#define button 2 //Connects button to digital pin 2
#define LED 3 //Connects LED to digital pin 3

bool isLatch = 1; //Boolean to determine behavior of button
bool state = 0; //Boolean to track latch state

void setup() {
  pinMode(button, INPUT_PULLUP); //button is configured as an input connected to an internal pullup resistor
  pinMode(LED, OUTPUT); //LED is configured as an output
}

void loop() {
  if (isLatch != 1) { //Checks if the button acts as a hold button
    while (digitalRead(button) == 0) { //A while loop will keep the LED high for as long as the button is held
      digitalWrite(LED, HIGH); 
    }
    digitalWrite(LED, LOW); //Upon releasing the button and breaking the while loop, turns off the LED
  } else 

  if (isLatch == 1) { //Checks if the button acts as a latch
    if (digitalRead(button) == 0) { //Checks if the button is pressed
      if (state == 0) { //If the lights are off, turns on the lights and changes boolean state to reflect that
        digitalWrite(LED, HIGH); 
        state = 1; 
      } else { //If the lights aren't off, turns off the lights, and changes boolean state to reflect that
        digitalWrite(LED, LOW); 
        state = 0; 
      }
      while (digitalRead(button) == 0); //A while loop to keep the light state from flashing while the button is held
    }
  }

  delay(100); //A 100ms delay between button checks
}
