#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

const char* ssid     = "tinfoilhat";  
const char* password = "fatherknowsbest";

const char* host     = "209.141.40.39"; // Your domain  
String path          = "/status.json";  
const int pin1        = 0;
const int pin2        = 2;

void setup() {  
  pinMode(pin1, OUTPUT); 
  pinMode(pin1, HIGH);
  pinMode(pin2, OUTPUT); 
  pinMode(pin2, HIGH);
  Serial.begin(115200);

  delay(10);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  int wifi_ctr = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");  
  Serial.println("IP address: " + WiFi.localIP());
}

void loop() {  
  Serial.print("connecting to ");
  Serial.println(host);
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  client.print(String("GET ") + path + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: keep-alive\r\n\r\n");

  delay(500); // wait for server to respond

  // read response
  String section="header";
  while(client.available()){
    String line = client.readStringUntil('\r');
    // Serial.print(line);
    // we’ll parse the HTML body here
    if (section=="header") { // headers..
      Serial.print(".");
      if (line=="\n") { // skips the empty space at the beginning 
        section="json";
      }
    }
    else if (section=="json") {  // print the good stuff
      section="ignore";
      String result = line.substring(1);

      // Parse JSON
      int size = result.length() + 1;
      char json[size];
      result.toCharArray(json, size);
      StaticJsonBuffer<200> jsonBuffer;
      JsonObject& json_parsed = jsonBuffer.parseObject(json);
      
      Serial.print("json =  ");
      Serial.println(json);
      
      if (!json_parsed.success())
      {
        Serial.println("parseObject() failed");
        return;
      }

      // Make the decision to turn off or on the LED
      if (strcmp(json_parsed["status"], "green") == 0) {
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW); 
        Serial.println("green led on, red led off");
      }
      else {
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        Serial.println("red led on, green led off");
      }
    }
  }
  Serial.print("closing connection. ");
}
