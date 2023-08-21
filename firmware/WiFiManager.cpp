#include "WiFiManager.h"

// Fixed IP settings
// IPAddress local_IP(192, 168, 1, 184);     // ESP32's fixed IP address
// IPAddress gateway(192, 168, 1, 1);       // Router's IP address
// IPAddress subnet(255, 255, 255, 0);      // Subnet mask
// IPAddress primaryDNS(8, 8, 8, 8);        // Preferred DNS server
// IPAddress secondaryDNS(8, 8, 4, 4);      // Alternate DNS server


void WiFiManager::connect(const char* ssid, const char* password) {

    // if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    //   Serial.println("STA Failed to configure");
    // }

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi!");
    Serial.print("ESP32 IP Address: ");
    Serial.println(WiFi.localIP().toString());
}
