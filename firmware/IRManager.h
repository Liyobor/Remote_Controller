#ifndef IR_MANAGER_H
#define IR_MANAGER_H

#include <IRsend.h>
#include <IRrecv.h>

class IRManager {
    IRrecv irrecv;
    IRsend irsend;
    decode_results results; // Declare results here

public:
    uint64_t lastReceivedIR = 0;

    IRManager(int recvPin, int sendPin);
    void begin();
    bool tryReceive();
    void sendSignal(uint64_t signal);
};

#endif // IR_MANAGER_H
