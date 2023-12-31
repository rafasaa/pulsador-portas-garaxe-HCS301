// This simple example looks for an HCS301 message on the RX_PIN and then repeates it over the TX_PIN.
// It should work with every Arduino compatible microcontroller on almost every pin.

#include <HCS301.h>

#define RX_PIN 11 //receiving pin
//#define TX_PIN 10 //transmitting pin

HCS301 radio1(RX_PIN, TX_PIN);

void setup() {
  Serial.begin(9600);
  Serial.println("Setup OK2");
  pinMode (13, OUTPUT);
  
  
}

void loop() {
  while(!radio1.receive()) {
   //loop until a message is received
  }
  //the following variables store the message for receiving and transmitting
  Serial.println(radio1.rollingCode);
  Serial.println(radio1.serialNr);
  Serial.println(radio1.message);

  if (radio1.serialNr == 200078219 && radio1.message ==42) // comparamos co valor que queremos pulsar no pulsador e que lemos antes
  {
    digitalWrite(13, HIGH);
    delay(1000);                       // wait for a second
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);
  }
}
