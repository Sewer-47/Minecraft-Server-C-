//
// Created by Sewerynek on 20.02.2024.
//

#ifndef UNTITLED6_SERVERSTATUSRESPONSEPACKET_H
#define UNTITLED6_SERVERSTATUSRESPONSEPACKET_H


#include "../../Packet.h"
#include "iostream"

using namespace std;

class ServerStatusResponsePacket : public Packet {
private:
    string json;

public:

    void write(PacketWritter out) override;
};


#endif //UNTITLED6_SERVERSTATUSRESPONSEPACKET_H
