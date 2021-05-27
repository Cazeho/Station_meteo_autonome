#include <SoftwareSerial.h>
 
SoftwareSerial mySerial(16, 17);


int donnee = 0; // for incoming serial data



#include <WiFi.h>

#include <FirebaseESP32.h>

#define FIREBASE_HOST "https://stma-d42c3-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "HYBE0RjC17SjgmpIOFcSon4aWUYmFChwhSgPBq7z"
FirebaseData firebaseData;

void setup()
{
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



  mySerial.begin(1200);
  Serial.println("Hi, I'm going to receive message!");

}


void loop()
{

    if (mySerial.available()) {
    // read the incoming byte:
    donnee = mySerial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println((byte)donnee);
    delay(500);
    signed char temp=-40+0.647*(byte)donnee;

    if ((Firebase.setInt(firebaseData, "/temperature", ((byte)donnee))) == true) {
      Serial.println((byte)donnee);

    } else {
      Serial.println("error");

    }



    
  }

    

}





 

