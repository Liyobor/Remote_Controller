#ifndef SOCKET_SERVER_H
#define SOCKET_SERVER_H

#include <WiFi.h>
#include "IRManager.h"

class SocketServer {
    WiFiServer server;
    IRManager& irManager;

public:
    SocketServer(int port, IRManager& ir);

    void begin();
    void handleClient();
};

#endif // SOCKET_SERVER_H
