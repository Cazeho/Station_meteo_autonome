#include <WiFi.h>

WiFiServer server(80);

WiFiClient client;

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
  server.begin();

}


void loop()
{

    client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<head>");
    client.println("</head>");
    client.println("<body>");
      client.println("<h1 style=""color:#ff0000"">");
      client.println("server web");
      client.println("</h1>");
      client.println("<span style=""color:#009900;font-size:14px"">");
      client.println("salut");
      client.println("</span>");
      client.println("<br>");
      client.println("<span style=""color:#6600cc;font-size:14px"">");
      client.println("server marche depuis");
      client.println("</span>");
      client.println("<span style=""color:#ff0000;font-size:20px"">");
      client.println((millis()/1000));
      client.println("</span>");
      client.println("<span style=""color:#6600cc;font-size:14px"">");
      client.println("secondes");
      client.println("</span>");
    client.println("</body>");
    client.println("</html>");
    client.stop();
     delay(1);
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("server ok");
    client.println("</html>");
    client.stop();
    delay(1);
   // client.flush();

}
