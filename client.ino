/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP32     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <WiFi.h>

WiFiClient client;

String myurl = "/";
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

}


void loop()
{

    if (client.connect("192.168.1.10", 9000)) {
      myurl += "data1";
      client.print(String("GET ") + myurl + " HTTP/1.1\r\n" +
                "Host: " + "192.168.1.10" + "\r\n" +
               "Connection: close\r\n\r\n");
      myurl="/";

    }
    delay(1000);
    if (client.connect("192.168.1.10", 9000)) {
      myurl += "data2";
      client.print(String("GET ") + myurl + " HTTP/1.1\r\n" +
                "Host: " + "192.168.1.10" + "\r\n" +
               "Connection: close\r\n\r\n");
      myurl="/";

    }
    delay(1000);
    if (client.connect("192.168.1.10", 9000)) {
      myurl += "data3";
      client.print(String("GET ") + myurl + " HTTP/1.1\r\n" +
                "Host: " + "192.168.1.10" + "\r\n" +
               "Connection: close\r\n\r\n");
      myurl="/";

    }
    delay(1000);

}
