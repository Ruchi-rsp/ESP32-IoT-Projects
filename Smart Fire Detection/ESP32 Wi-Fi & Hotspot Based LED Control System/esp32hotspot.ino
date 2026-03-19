#include <WiFi.h>

// Set your desired SSID and password
const char* ssid = "ESP32_Hotspot";
const char* password = "12345678";  // Must be at least 8 characters

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Start Wi-Fi in Access Point mode
  WiFi.softAP(ssid, password);

  Serial.println("ESP32 started as Wi-Fi Hotspot");
  Serial.print("Hotspot Name (SSID): ");
  Serial.println(ssid);
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  // Nothing to do here
}
