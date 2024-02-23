//
// Created by Sewerynek on 21.02.2024.
//

#ifndef UNTITLED6_SERVERSTATUSPONGPACKET_H
#define UNTITLED6_SERVERSTATUSPONGPACKET_H


#include "../../Packet.h"

class ServerStatusPongPacket : public Packet {

private:
    long payload;

public:
    void write(PacketWritter out) override;

    void setPayload(long payload);
};

#endif //UNTITLED6_SERVERSTATUSPONGPACKET_H
