#include<ESP8266WiFi.h>
#include<PubSubClient.h>

#define CLIENT_ID "homeauto"
#define port 1883

const char *ssid ="Ahil choyen";
const char *pswd ="8008913599";
const char *mqtt_Server="3.84.236.93";

WiFiClient espclient;
PubSubClient client(espclient);
  
void setup() 
{
  Serial.begin(9600);
  WiFi.begin(ssid,pswd);
  while(WiFi.status()!=WL_CONNECTED)
    {
      Serial.print("...");
      delay(200);
    }  
    Serial.println("\n WIFI CONNECTED");
    Serial.println(ssid);
    Serial.println(WiFi.localIP());
    client.setServer(mqtt_Server,1883);
    client.subscribe("topic");
    client.setCallback(callback);
    pinMode(16,OUTPUT);
}

void reconnect()
  {
    while(!client.connected())
      {
      Serial.print("Attempting MQTT connection...");
      
    if(client.connect(CLIENT_ID))
      {
      Serial.println("connected");
      client.subscribe("topic");
      }  
      } 
  }
void callback(char* topic, byte* payload, unsigned int length) 
 {
  Serial.print("Message arrived");
  Serial.print(topic);
  for (int i = 0; i < length; i++) 
   {
    Serial.print((char)payload[i]);
   }
   if((char)payload[0]=='1')
    {
    digitalWrite(16,LOW);
    }
   else
   {
    digitalWrite(16,HIGH);
    } 
 }
  
void loop() 
{
  if(!client.connected())
    {
      reconnect();
    }
  client.loop();
}
