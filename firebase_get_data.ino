/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP32     //
// Website: Easycoding.tn      //
/////////////////////////////////
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

}


void loop()
{

    if (Firebase.getString(firebaseData, "/temperature")) {
      Serial.println("string variable");
      Serial.println((firebaseData.stringData()));

    }
    delay(1000);

}
