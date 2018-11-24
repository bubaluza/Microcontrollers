/*        Obstacle Sensor spreadsheet(google sheet)
  Author: Gabriel J Schiller
  Whatever a obstacle sensor it's activade, print the time activaded on a google sheet
*/
// ---------------- INCLUDES ----------------
#include <WiFi.h>
#include "WiFiClientSecure.h"
// ---------------- NETWORK CREDENTIALS ---------------- 

//const char* ssid = "YOURSSID";
//const char* password = "YOURPASSWORD";

// ---------------- GET URL ---------------- 

//String textFix = "ADDRESS";

WiFiClientSecure client;
// ---------------- SENSOR PIN ---------------- 
#define pinSensor 19
#define pinVCC 5
#define pinGND 18
// ---------------- FUNCTION DECLARATION ---------------- 
void submit(long b);
// ---------------- SETUP ---------------- 
void setup(){
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  delay(2000);
  pinMode(pinSensor,INPUT);
  pinMode(pinVCC,OUTPUT);
  pinMode(pinGND,OUTPUT);  
  digitalWrite(pinVCC,HIGH);
  digitalWrite(pinGND, LOW);
}
// ---------------- LOOP ---------------- 
void loop(){
  if(!digitalRead(pinSensor)){                     
    Serial.println("obstacle");
    long aux = millis();
    while(!digitalRead(pinSensor));
    long pressed = millis()-aux;
    submit(pressed);
    delay(100);
  }
}
// ---------------- FUNCTION ---------------- 
void submit(long b){
  if(client.connect("docs.google.com", 443)){
      String toSend = textFix;//
      toSend += (String)b;
      toSend += "&submit=Submit HTTP/1.1";
      client.println(toSend);
      client.println("Host: docs.google.com");
      client.println();
      client.stop();
      Serial.println("sent");
  }
}
