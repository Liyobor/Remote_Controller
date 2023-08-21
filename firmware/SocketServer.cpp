#include "SocketServer.h"

SocketServer::SocketServer(int port, IRManager& ir) : server(port), irManager(ir) {}

void SocketServer::begin() {
    server.begin();
}

void SocketServer::handleClient() {
    WiFiClient client = server.available();

    if (client) {
        Serial.println("New client connected!");
        while (client.connected()) {
            if (client.available()) {
                char c = client.read();
                Serial.print("Received message: ");
                Serial.println(c); // Print received message on serial
                Serial.write(c);
                if (c == 'r') {
                    if (irManager.tryReceive()) {
                        client.println(irManager.lastReceivedIR, HEX);
                    } else {
                        client.println("No data!");
                    }
                } else if (c == 'e') {
                    if (irManager.lastReceivedIR) {
                        irManager.sendSignal(irManager.lastReceivedIR);
                        client.println("Signal sent!");
                    } else {
                        client.println("error");
                    }
                }
            }
        }
        client.stop();
        Serial.println("Client disconnected.");
    }
}
