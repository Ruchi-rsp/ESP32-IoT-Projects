#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_TEMPLATE_NAME "Fire Detection System"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YourWiFiName";
char pass[] = "YourWiFiPassword";

const int gasPin = 34;

BlynkTimer timer;

uint16_t readAvg(int pin, int n = 20) {
  uint32_t sum = 0;
  for (int i = 0; i < n; i++) {
    sum += analogRead(pin);
    delayMicroseconds(200);
  }
  return sum / n;
}

void sendSensorData() {
  uint16_t raw = readAvg(gasPin);
  uint32_t mv = analogReadMilliVolts(gasPin);

  Serial.print("Gas Value: ");
  Serial.println(raw);

  // Send to Blynk
  Blynk.virtualWrite(V0, raw);

  // Alert condition
  if (raw > 1500) {
    Serial.println("Gas Detected!");
    Blynk.logEvent("Gas Leakage Detected!");
    Blynk.virtualWrite(V1, 1);
  } else {
    Blynk.virtualWrite(V1, 0);
  }
}

void setup() {
  Serial.begin(115200);

  analogReadResolution(12);
  analogSetPinAttenuation(gasPin, ADC_11db);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(1000L, sendSensorData);
}

void loop() {
  Blynk.run();
  timer.run();
}
