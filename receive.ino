#include <SoftwareSerial.h>
 
SoftwareSerial mySerial(16, 17);


int donnee = 0; // for incoming serial data

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  mySerial.begin(9600);
  Serial.println("Hi, I'm going to receive message!");
 
}

void loop() {
  // send data only when you receive data:
  if (mySerial.available()) {
    // read the incoming byte:
    donnee = mySerial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(donnee, DEC);
  }
}

//
#include <SoftwareSerial.h>
 
SoftwareSerial mySerial(16, 17);


int donnee = 0; // for incoming serial data

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  mySerial.begin(1200);
  Serial.println("Hi, I'm going to receive message!");
 
}

void loop() {
  // send data only when you receive data:
  if (mySerial.available()) {
    // read the incoming byte:
    donnee = mySerial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println((char)donnee);
    delay(500);
  }
}

