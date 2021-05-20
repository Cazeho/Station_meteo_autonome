#include <WiFi.h>

#include <FirebaseESP32.h>

#define FIREBASE_HOST "https://stma-d42c3-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "HYBE0RjC17SjgmpIOFcSon4aWUYmFChwhSgPBq7z"
FirebaseData firebaseData;










#include <SoftwareSerial.h>
 
SoftwareSerial mySerial(16, 17);



void setup() {
  Serial.begin(9600);

  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
  WiFi.begin("stma","wpss7866");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("..");

  }
  Serial.println("Connected");
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP()));
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  mySerial.begin(1200);
  Serial.println("Hi, I'm going to receive message!");
 
}

void loop() {
  // send data only when you receive data:
  if (mySerial.available()>0) {
    // read the incoming byte:
    

    // say what you got:
    Serial.print("I received: ");
    Serial.println(int(mySerial.read()));
    delay(500);
  

     if ((Firebase.setInt(firebaseData, "/temperature", int(mySerial.read()))) == true) {
      Serial.println("data send");

    } else {
      Serial.println("error");

    }

  }
}







 

