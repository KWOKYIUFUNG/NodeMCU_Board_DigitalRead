
const int inputPin1 = 12;
const int inputPin2 = 13;
const int inputPin3 = 15;
#include <ESP8266WiFi.h>
#include "ThingSpeak.h"

//WIFI Setup

const char* ssid = "KKIF";
const char* password = "54001006";
WiFiClient client;

String apiKey = "CYNQFOX0B4SBIFH6";
const char* server = "api.thingspeak.com";
int number = 1;
int i = 0;


 
void setup() 
  { 
  

    Serial.begin(9600);

    //WIFI

  delay(10);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Print the IP address
  Serial.print("IP address: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

  


  }
 

void loop()
{
  Serial.println("start");  
  int val1 = digitalRead(inputPin1); 
  Serial.println(val1); 
  if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field1=";
                             postStr += int(val1);

                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                             Serial.print("number: ");
                             Serial.print(val1);
                             Serial.println(". Send to Thingspeak.");
                             Serial.println("\n**Some people are using**\n");
                        }

    delay (1000);


     int val2 = digitalRead(inputPin2); 
     Serial.println(val2);
     if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field2=";
                             postStr += int(val2);

                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                             Serial.print("number: ");
                             Serial.print(val2);
                             Serial.println(". Send to Thingspeak.");
                             Serial.println("\n**Some people are using**\n");
                        }
   delay(1000);

                       
    int val3 = digitalRead(inputPin3); 
    Serial.println(val3);
    if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field3=";
                             postStr += int(val3);

                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                             Serial.print("number: ");
                             Serial.print(val3);
                             Serial.println(". Send to Thingspeak.");
                             Serial.println("\n**Some people are using**\n");
                        }
  
    delay(1000);
}
