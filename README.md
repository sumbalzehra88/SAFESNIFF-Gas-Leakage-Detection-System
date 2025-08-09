# SAFESNIFF-Gas-Leakage-Detection-System
Gas leaks pose a serious threat to public safety, often going undetected until it's too late. Traditional detection methods lack real-time alerts and accessibility. SAFESNIFF is an IoT-powered, real-time LPG gas leakage detection and alert system that detects harmful gas presence, triggers immediate local alarms, and sends instant mobile notifications via the Blynk IoT platform.

![WhatsApp Image 2025-08-08 at 2 53 07 PM](https://github.com/user-attachments/assets/6d0ae678-4535-4097-a4c2-d8ab875ff9f9)

## 💡 Features
- 🔍 Real-time gas monitoring using **MQ-2 sensor**
- 📲 Instant alerts via **buzzer**, **LED**, and **Blynk mobile app**
- 🌐 Live gas readings on a **dashboard** (built using Blynk)
- ⚙️ Powered by **ESP32** for Wi-Fi connectivity
- 💰 Low-cost and portable design for home and industrial use

## 🔧 Hardware Used
- ESP32 Dev Board  
- MQ-2 Gas Sensor  
- Buzzer  
- LED  
- Jumper Wires  
- Breadboard  

## 🧠 Why ESP32?
After comparing different microcontrollers, we selected ESP32 for its:
- Built-in **Wi-Fi & Bluetooth**
- Cost-effectiveness
- Better integration than Arduino UNO (which requires extra Wi-Fi modules)
- More affordable than Raspberry Pi for this use-case

## 🔁 System Workflow
1. Gas leakage is detected by the MQ-2 sensor  
2. ESP32 processes the signal and triggers alerts  
3. Buzzer and LEDs activate for immediate local warning  
4. Live gas level updates are sent to Blynk dashboard  
5. User receives mobile notifications via the app as well as an email notification via Gmail.

## 📲 IoT Dashboard (Blynk)
- Gauge → Displays real-time gas levels

- LED Widget → Lights up when gas detected
- Button → Manually silence buzzer from anywhere
- Push Notifications → Immediate mobile alerts

## 📦 Applications
- Homes with gas appliances  
- Small-scale industries or kitchens  
- Safety-first educational labs  

## 📊 Why This Matters
According to Rescue 1122, dozens of gas-related incidents occur every winter in Pakistan due to poor detection systems and delayed responses. Most cases happen in homes and small industries where no real-time alert system is installed.

## 👥 Team
Developed by:
- [Sumbal Zehra](www.linkedin.com/in/sumbal-zehra-ba14461b6)
- [Arfa Tariq](www.linkedin.com/in/arfa-tariq-1008a8300)
- [Khadija Sehar]

## 📜 License
This project is open-source under the MIT License.




