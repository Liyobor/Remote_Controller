#include <Arduino.h>
#include "WiFiManager.h"
#include "IRManager.h"
#include "SocketServer.h"

// 其他的代碼 (例如 SocketServer 和主程序的 setup 和 loop)

WiFiManager wifiManager;
IRManager irManager(5, 4);
SocketServer socketServer(8080, irManager);

const char* ssid = "Pixel7";
const char* password = "87654321";


bool socketServerStarted = false;
void setup() {
    Serial.begin(115200);
    irManager.begin();
}

void loop() {
    if (WiFi.status() != WL_CONNECTED) {
        wifiManager.connect(ssid, password);
        delay(5000); // Wait for 10 seconds before trying again
    } else if (!socketServerStarted) {
      Serial.println("WiFi connected!");
      socketServer.begin();
      socketServerStarted = true;
      Serial.println("Start socketServer!");
    }

    if (socketServerStarted) {

      socketServer.handleClient();
    }
}