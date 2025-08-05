

# ESP32 SHT31 Temperature & Humidity Monitor

A web-based temperature and humidity monitoring system using ESP32 and SHT31 sensor with authentication protection.

## Features
- Real-time temperature and humidity monitoring
- Web-based interface with authentication
- Secure access with username/password protection
- Automatic sensor readings every second
- Serial output for debugging

## Hardware Requirements
- ESP32 development board
- Adafruit SHT31 temperature & humidity sensor
- Jumper wires
- Micro USB cable for programming

## Software Requirements
- Arduino IDE
- Required Libraries:
  - `WiFi.h` (built-in with ESP32 core)
  - `WebServer.h` (built-in with ESP32 core)
  - `Wire.h` (built-in)
  - `Adafruit SHT31 Library` (install via Library Manager)

## Installation
1. Install the Adafruit SHT31 Library:
   - In Arduino IDE, go to **Sketch > Include Library > Manage Libraries...**
   - Search for "Adafruit SHT31" and install

2. Connect the SHT31 sensor to ESP32:
   - SHT31 SDA → ESP32 GPIO 21 (default SDA pin)
   - SHT31 SCL → ESP32 GPIO 22 (default SCL pin)
   - SHT31 VIN → ESP32 3.3V
   - SHT31 GND → ESP32 GND

3. Configure the code:
   - Update WiFi credentials in the code:
     ```cpp
     const char* ssid = "YOUR_WIFI_SSID";       // Replace with your WiFi network name
     const char* password = "YOUR_WIFI_PASSWORD"; // Replace with your WiFi password
     ```
   - (Optional) Change authentication credentials:
     ```cpp
     const char* http_username = "admin";        // Username for web access
     const char* http_password = "1234";         // Password for web access
     ```

4. Upload the code to your ESP32

## Usage
1. After uploading, open Serial Monitor (115200 baud rate) to see connection details
2. Once connected to WiFi, note the IP address displayed
3. Open a web browser and go to the displayed IP address
4. When prompted, enter the username and password (default: admin/1234)
5. The web page will display current temperature and humidity readings

## Code Overview
- The SHT31 sensor is initialized on I2C address 0x44
- Temperature and humidity are read every second
- A web server runs on port 80 with authentication protection
- The web interface displays sensor readings in a simple HTML page

## Troubleshooting
- If the sensor isn't detected, check wiring connections
- If WiFi connection fails, verify SSID and password
- If web page doesn't load, check the IP address in Serial Monitor
- For authentication issues, verify username and password

## Contributing
If you have suggestions for improvements or encounter issues:
1. Fork the repository
2. Create your feature branch
3. Commit your changes
4. Push to the branch
5. Create a new Pull Request

## License 
This project is open source and available under the MIT License.

## Contact
For questions or support, please create an issue in the repository.
