#define BLYNK_TEMPLATE_ID 
#define BLYNK_TEMPLATE_NAME 
#define BLYNK_AUTH_TOKEN 

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "your_ssid";
char pass[] = "your_pass";

int gasPin = 34;  // MQ-2 analog pin (use A0 or ADC pin)
int threshold = 300;  // Adjust based on testing
int gasValue;

BlynkTimer timer;

void sendSensorData() {
  gasValue = analogRead(gasPin);
  int percentage = map(gasValue, 0, 4095, 0, 100); // Map to percentage
  Blynk.virtualWrite(V0, percentage); // Send to gauge on V0

  if (gasValue > threshold) {
    Blynk.logEvent("gas_alert", "⚠️ Gas leak detected! Please check immediately.");
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(gasPin, INPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(2000L, sendSensorData); // Send every 2 seconds
}

void loop() {
  Blynk.run();
  timer.run();
}
