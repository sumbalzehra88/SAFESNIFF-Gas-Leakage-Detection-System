# 🚀 Setup Instructions
## 1. Hardware Wiring

- MQ-2 → ESP32 analog pin (e.g., GPIO35)

- LED → GPIO14

- Buzzer → GPIO13

- Ground & VCC connections according to ESP32 pinout

## 2. Code Upload

- Install Arduino IDE & ESP32 board package

- Install Blynk library

- Update your Blynk Template ID, Auth Token, and Wi-Fi credentials in the code

- Upload to ESP32

## 3. Blynk Dashboard Setup

- Create a new Blynk Template

- Add Gauge (V0), LED (V1), and Button (V2) widgets

- Set event for gas_alert in Blynk console to send push notifications

# ⚙️ Detailed Blynk Dashboard Setup
1. **Create a Blynk Template**
   - Name: `YourProjectName` 
   - Hardware: `ESP32`
   - Connection: `Wi-Fi`
   
2. **Add Widgets**
   - **Gauge Widget** (Virtual Pin V0) → Displays gas readings
   - **LED Widget** (Virtual Pin V1) → Shows detection status
   - **Button Widget** (Virtual Pin V2) → Manual buzzer control
   - **Event Notification** (`gas_alert`) → Push alert when gas detected

3. **Configure Event**
   - Go to **Events → Add Event**
   - Name: `gas_alert`
   - Description: `Gas Leak Detected`
   - Notification Type: Push Notification
