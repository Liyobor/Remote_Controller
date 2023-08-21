#include "IRManager.h"

IRManager::IRManager(int recvPin, int sendPin) : irrecv(recvPin), irsend(sendPin) {}

void IRManager::begin() {
    irsend.begin();
    irrecv.enableIRIn();
}

bool IRManager::tryReceive() {
    if (irrecv.decode(&results)) {
        lastReceivedIR = results.value;
        irrecv.resume();
        return true;
    }
    return false;
}

void IRManager::sendSignal(uint64_t signal) {
    irsend.sendKelon(signal);
}
