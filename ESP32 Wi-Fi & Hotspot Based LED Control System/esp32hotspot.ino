#include <WiFi.h>
#include <WebServer.h>

const int ledPin = 2; // Built-in LED

// WiFi credentials
const char* ssid = "YourWiFiName";
const char* password = "YourPassword";

// Access Point credentials
const char* ap_ssid = "ESP32_LED";
const char* ap_password = "12345678";

WebServer server(80);

void handleRoot() {
  String html = "<h1>ESP32 LED Control</h1>";
  html += "<a href=\"/on\"><button>ON</button></a>";
  html += "<a href=\"/off\"><button>OFF</button></a>";
  server.send(200, "text/html", html);
}

void handleOn() {
  digitalWrite(ledPin, HIGH);
  server.send(200, "text/html", "LED ON");
}

void handleOff() {
  digitalWrite(ledPin, LOW);
  server.send(200, "text/html", "LED OFF");
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  // Try connecting to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  int count = 0;
  while (WiFi.status() != WL_CONNECTED && count < 10) {
    delay(1000);
    Serial.print(".");
    count++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConnected to WiFi");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nSwitching to AP Mode");
    WiFi.softAP(ap_ssid, ap_password);
    Serial.println(WiFi.softAPIP());
  }

  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);

  server.begin();
}

void loop() {
  server.handleClient();
}
