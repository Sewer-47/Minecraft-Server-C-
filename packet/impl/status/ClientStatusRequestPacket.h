//
// Created by Sewerynek on 21.02.2024.
//

#ifndef UNTITLED6_CLIENTSTATUSREQUESTPACKET_H
#define UNTITLED6_CLIENTSTATUSREQUESTPACKET_H


#include "../../Packet.h"

class ClientStatusRequestPacket : public Packet {

public:
    void read(PacketReader in) override;
};


#endif //UNTITLED6_CLIENTSTATUSREQUESTPACKET_H
