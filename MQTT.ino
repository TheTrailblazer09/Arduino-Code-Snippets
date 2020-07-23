#include <WiFi.h>
#include <PubSubClient.h>

char ssid[] = "D6_EXT"; //Put your wifi name.
char pass[] = "pituraj2020"; //Put your wifi password.

const char server[] = "mqtt.flespi.io";
char mqttUserName[] = "vTsqJglhKOhj0kEkXmgE8vVB1ZamieRBW9Pve1BODIYuQqCDAG5y1RXQEY3K2KbO";
char mqttPass[] = "";
const char clientID[] = "9821005152"; // change according to your no.

WiFiClient client;
PubSubClient mqttClient(client);

const char topicBuffer[] = "YTS/Vani_BPM"; // change with your name
const char topicBuffer2[] = "YTS/Vani_Pulse";// change with your name 

unsigned long lastConnectionTime = 0;
const unsigned long postingInterval = 10; 
//Mqtt Ends

void setup() {
  Serial.begin(9600); 
          
  int status = WL_IDLE_STATUS;  

  // Attempt to connect to Wi-Fi network.
  while (status != WL_CONNECTED)
  {
    Serial.println("Trying to connect to wifi....");
    status = WiFi.begin(ssid, pass); // Connect to WPA/WPA2 Wi-Fi network.
    delay(5000);
  }

  Serial.println("Connected to wifi");
  mqttClient.setServer(server, 1883);
}

void loop() {

  if (!mqttClient.connected())
  {
    while (!mqttClient.connected())
    {
      Serial.print("Attempting MQTT connection...");

      if (mqttClient.connect(clientID, mqttUserName, mqttPass)) {
        Serial.println("connected");
      }
      else {
        Serial.print("failed, rc=");
        Serial.print(mqttClient.state());
        Serial.println(" try again in 5 seconds");
        delay(5000);
      }
    }
  }

  mqttClient.loop();   

  if (millis() - lastConnectionTime > postingInterval)
  {
    int i = random(60, 80);
    String data = String(i);
    const char *msgBuffer;
    msgBuffer = data.c_str();
    Serial.println(msgBuffer);

    if (mqttClient.publish( topicBuffer, msgBuffer )) Serial.println("Message published");
    lastConnectionTime = millis();
  }
}
