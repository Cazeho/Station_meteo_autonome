//code fonctionel 1



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
/*#include <SoftwareSerial.h>
 
SoftwareSerial mySerial(4, 5); // Arduino RX --> e22 TX - Arduino TX --> e22 RX
 
void setup() {
  Serial.begin(9600);
  delay(500);
 
  Serial.println("i'm going to send a message");
 
  mySerial.begin(1200);
  mySerial.write("hello world");
}
 
void loop() {
  mySerial.write("hello world");
  delay(500);
  /*if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
  

}*/

  
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
 
SoftwareSerial mySerial(4, 5); // Arduino RX --> e22 TX - Arduino TX --> e22 RX
 
void setup() {
  Serial.begin(9600);
  delay(500);
 
  Serial.println("Hi, I'm going to send message!");
 
  mySerial.begin(1200);
  mySerial.print(8);
}
 
void loop() {
  unsigned char randomChar;

  randomChar = analogRead(A1);
  mySerial.write(randomChar);
  Serial.println(randomChar);
  delay(5000);
}
