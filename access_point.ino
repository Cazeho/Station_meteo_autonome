/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP32     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <WiFi.h>

void setup()
{
Serial.begin(9600);

  delay(3000);
  Serial.println("START");
  WiFi.softAP("stma","wpss7866");
  Serial.println("ip of AP");
  Serial.println((WiFi.softAPIP()));

}


void loop()
{

    Serial.println("Connected");
    Serial.println((WiFi.softAPgetStationNum()));
    delay(1000);

}
