/***************************************************
 *  SAFESNIFF - IoT Gas Leakage Alert System
 *  Hardware: ESP32 + MQ-2 Gas Sensor + Buzzer + LED
 *  Platform: Arduino + Blynk IoT
 *  
 *  Features:
 *    - Monitors MQ-2 gas sensor values in real-time
 *    - Displays live readings on Blynk dashboard gauge
 *    - Sends push notifications on gas detection
 *    - Blinking red LED + buzzer alert on detection
 *    - Manual buzzer stop control via Blynk button
 *  
 *  IMPORTANT: Replace placeholder values with your own
 *  credentials before uploading to your device.
 ***************************************************/

/* ---- Blynk Template Settings ---- */
#define BLYNK_TEMPLATE_ID   "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "YOUR_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN    "YOUR_AUTH_TOKEN"

/* ---- Debugging Output ---- */
#define BLYNK_PRINT Serial

/* ---- Library Includes ---- */
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

/* ---- WiFi Credentials ---- */
char auth[] = BLYNK_AUTH_TOKEN;    // Blynk Auth Token
char ssid[] = "YOUR_WIFI_SSID";    // Wi-Fi SSID
char pass[] = "YOUR_WIFI_PASS";    // Wi-Fi Password

/* ---- Pin Definitions ---- */
#define MQ2_PIN   35  // Analog input pin for MQ-2
#define LED_PIN   14  // Red alert LED
#define BUZZER    13  // Buzzer pin
#define GREEN     12  // Green "safe" LED

/* ---- Variables ---- */
int gasValue = 0;                  // Latest gas sensor reading
int threshold = 1800;              // Gas detection threshold (set according to your own sensor)
bool buzzerOverride = false;       // Manual buzzer control flag
bool alertSent = false;            // Prevent duplicate alerts
bool blinkState = false;           // For LED blinking effect

/* ---- Blynk Virtual Widgets ---- */
WidgetLED appLED(V1); // Virtual LED widget for gas detection status

BlynkTimer timer;

/* ---- Blynk Function: Manual Buzzer Control ---- */
BLYNK_WRITE(V2) {
  buzzerOverride = param.asInt(); // 1 = override buzzer, 0 = normal
}

/* ---- Setup ---- */
void setup() {
  Serial.begin(9600);

  pinMode(MQ2_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(GREEN, OUTPUT);

  // Connect to Blynk + Wi-Fi
  Blynk.begin(auth, ssid, pass);

  // Check gas every 1 second
  timer.setInterval(1000L, checkGasLevel);

  // Blink LED every 0.5 seconds for SOS alert
  timer.setInterval(500L, blinkLED);
}

/* ---- Main Loop ---- */
void loop() {
  Blynk.run();
  timer.run();
}

/* ---- Gas Detection Logic ---- */
void checkGasLevel() {
  int total = 0;

  // Take 10 readings for a stable average
  for (int i = 0; i < 10; i++) {
    total += analogRead(MQ2_PIN);
    delay(20);
  }
  gasValue = total / 10;

  // Send reading to Blynk gauge widget
  Blynk.virtualWrite(V0, gasValue);

  // Print for debugging
  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  // Gas detected
  if (gasValue > threshold && !buzzerOverride) {
    digitalWrite(GREEN, LOW);   // Turn off safe LED
    digitalWrite(BUZZER, HIGH); // Turn on buzzer
    appLED.on();                // Virtual LED ON in Blynk

    // Send notification only once until cleared
    if (!alertSent) {
      Blynk.logEvent("gas_alert", "⚠️ Gas Leak Detected! Check Immediately.");
      alertSent = true;
    }
  }
  // Safe condition
  else {
    digitalWrite(GREEN, HIGH);  // Safe LED ON
    digitalWrite(BUZZER, LOW);  // Buzzer OFF
    digitalWrite(LED_PIN, LOW); // Stop blinking LED
    appLED.off();               // Virtual LED OFF in Blynk
    alertSent = false;
  }
}

/* ---- Blinking LED Logic ---- */
void blinkLED() {
  if (gasValue > threshold && !buzzerOverride) {
    blinkState = !blinkState;
    digitalWrite(LED_PIN, blinkState);
  } else {
    blinkState = false;
    digitalWrite(LED_PIN, LOW);
  }
}
