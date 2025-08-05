#include <WiFi.h>
#include <WebServer.h>
#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_SHT31.h"

Adafruit_SHT31 sht31 = Adafruit_SHT31();
// تنظیمات شبکه وای‌فای
const char* ssid = "Name_of_your_ethernet";       // نام شبکه وای‌فای
const char* password = "Your_password"; // رمز عبور وای‌فای

// تنظیمات احراز هویت
const char* http_username = "admin";        // نام کاربری برای صفحه
const char* http_password = "1234";         // رمز عبور برای صفحه

// عددی که باید نمایش داده شود
int displayNumber = 42; // می‌توانید این عدد را تغییر دهید
float temp;
float humidity;
WebServer server(80); // ایجاد وب‌سرور روی پورت 80

void setup() {
  Serial.begin(115200);
    if (! sht31.begin(0x44)) {   
    Serial.println("Check circuit. SHT31 not found!");
    while (1) delay(1);
  }
  // اتصال به وای‌فای
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected! IP: " + WiFi.localIP().toString());

  // تنظیم مسیر اصلی با احراز هویت
  server.on("/", []() {
    if (!server.authenticate(http_username, http_password)) {
      return server.requestAuthentication(); // درخواست احراز هویت
    }
    // صفحه HTML پس از ورود موفق
    String html = "<!DOCTYPE html><html><head>";
    html += "<meta charset='UTF-8'>";
    html += "<title>Protected Number</title>";
    html += "<style>body { font-family: Arial; text-align: center; margin-top: 50px; }</style>";
    html += "</head><body>";
    html += "<h1>Number Display</h1>";
    html += "<p>دما تو خونه ی شما : <strong>" + String(temp) + "</strong></p>";
    html += "<p>رطوبت خونه ی شما : <strong>" + String(humidity) + "</strong></p>";
    html += "</body></html>";
    server.send(200, "text/html", html);
  });

  server.begin(); // شروع وب‌سرور
}

void loop() {
  server.handleClient(); // مدیریت درخواست‌های کلاینت
    temp = sht31.readTemperature();
    humidity = sht31.readHumidity();

  if (! isnan(temp)) { 
    Serial.print("Temperature(°C): "); 
    Serial.print(temp); 
    Serial.print("\t\t");
  } else { 
    Serial.println("Failed to read temperature!");
  }
  
  if (! isnan(humidity)) {  
    Serial.print("Humidity(%): "); 
    Serial.println(humidity);
  } else { 
    Serial.println("Failed to read humidity!");
  }

  delay(1000);
}


