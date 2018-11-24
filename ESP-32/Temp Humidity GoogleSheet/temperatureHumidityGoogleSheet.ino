// ---------------- LIBRARY ----------------
#include "DHTesp.h"
#include <WiFi.h>
#include "WiFiClientSecure.h"
// ---------------- NETWORK ----------------
const char* ssid = "SSID";
const char* password = "PASSWORD";
// ---------------- OBJECT INSTANCE ----------------
WiFiClientSecure client;
DHTesp dht;
// ---------------- REQUEST ----------------
String textFix = "GET /forms/d/e/1FAIpQLSc1pS7s4cM9XxAa5lIBFoa52fWlC9D1bEbzP5Exy0WQWxkp6/formResponse?ifq&entry.771615963=";

// ---------------- SENSOR PIN ----------------
#define signalPin 26
#define vccPin 25
#define gndPin 33

// ---------------- FUNCTION DECLARATION ----------------
void submit(float a, float b);

// ---------------- SETUP ----------------
void setup(){
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  delay(2000);
  pinMode(signalPin,INPUT);
  pinMode(vccPin,OUTPUT);
  pinMode(gndPin,OUTPUT);
  digitalWrite(vccPin, HIGH);
  digitalWrite(gndPin, LOW);
  dht.setup(signalPin,DHTesp::DHT11);
}

// ---------------- LOOP ----------------
void loop(){
  float temperature =dht.getTemperature();
  float humidity =dht.getHumidity();
  submit(temperature,humidity);
  delay(60000);
}



// ---------------- FUNCTION ---------------- 
void submit(float a, float b){
  if(client.connect("docs.google.com", 443)){
  
      String toSend = textFix;//
      toSend += (String)a;
      toSend += "&entry.913624897=";
      toSend += (String)b;
      toSend += "&submit=Submit HTTP/1.1";
      client.println(toSend);
      client.println("Host: docs.google.com");
      client.println();
      client.stop();
  }
}
