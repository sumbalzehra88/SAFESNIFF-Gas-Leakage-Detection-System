## ⚙️ Blynk Dashboard Setup
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
