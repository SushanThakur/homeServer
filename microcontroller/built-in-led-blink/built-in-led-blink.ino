#include <ESP8266WiFi.h>
#include "private.cpp"

#define ledpin 2

WiFiServer server(80);
String header;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, pass);
  Serial.println();
  Serial.print("connecting");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
  }
  Serial.println("Connected Sucessfully.");
  Serial.println(WiFi.localIP());

  pinMode(ledpin, OUTPUT);

  server.begin();

}

void loop() {
  delay(500);
  WiFiClient client = server.available();

  int num;

  if(client){
    String line="";
    int i = 0;
    if(client.connected()){
      Serial.println("Client Connected");
    }
    while(client.connected()){
      if(client.available()){
        char c = client.read();
        line += c;
        if(i==7){
          num = (int) (c - '0');
        }
        if(c == '\n'){
          break;
        }
        i++;
      }
    }
    //Serial.println(line);
    Serial.println(num);
    if(num == 0) {
      pinMode(ledpin, LOW);
    }
    if(num == 1){
      pinMode(ledpin, HIGH);
    }
  }
}
