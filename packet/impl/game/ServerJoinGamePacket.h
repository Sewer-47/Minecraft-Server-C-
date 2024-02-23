//
// Created by Sewerynek on 22.02.2024.
//

#ifndef UNTITLED6_SERVERJOINGAMEPACKET_H
#define UNTITLED6_SERVERJOINGAMEPACKET_H


#include "../../Packet.h"

class ServerJoinGamePacket : public Packet {//TODO

public:
    void write(PacketWritter out) override;
};


#endif //UNTITLED6_SERVERJOINGAMEPACKET_H
