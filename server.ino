/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP32     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <WiFi.h>

String  ClientRequest;
IPAddress staticIP145_10(192,168,1,10);
IPAddress gateway145_10(192,168,1,1);
IPAddress subnet145_10(255,255,255,0);

WiFiServer server(9000);

WiFiClient client;

String myresultat;

String ReadIncomingRequest(){
while(client.available()) {
ClientRequest = (client.readStringUntil('\r'));
 if ((ClientRequest.indexOf("HTTP/1.1")>0)&&(ClientRequest.indexOf("/favicon.ico")<0)){
myresultat = ClientRequest;
}
}
return myresultat;
}

void setup()
{
ClientRequest = "";

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
  WiFi.config(staticIP145_10, gateway145_10, subnet145_10);
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP()));
  server.begin();

}


void loop()
{

    client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    ClientRequest = (ReadIncomingRequest());
    client.flush();
    Serial.println("HTTP request");
    Serial.println((client.remoteIP()));
    Serial.println("original request");
    Serial.println(ClientRequest);
    ClientRequest.remove(0, 5);
    ClientRequest.remove(ClientRequest.length()-9,9);
    Serial.println("request with clear");
    Serial.println(ClientRequest);

}
