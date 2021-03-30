/*
 * LoRa E22 
 * Start device or reset to send a message
 * https://www.mischianti.org
 *
 * E22        ----- Arduino UNO
 * M0         ----- GND
 * M1         ----- GND
 * TX         ----- PIN D4
 * RX         ----- PIN D5
 * AUX        ----- Not connected
 * VCC        ----- 3.3v/5v
 * GND        ----- GND
 *
 */
#include "Arduino.h"
 
#include <SoftwareSerial.h>
 
SoftwareSerial mySerial(D5, D4); // Arduino RX --> e22 TX - Arduino TX --> e22 RX
 
void setup() {
  Serial.begin(9600);
  delay(500);
 
  Serial.println("Hi, I'm going to send message!");
 
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
}
 
void loop() {
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}
