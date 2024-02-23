//
// Created by Sewerynek on 21.02.2024.
//

#ifndef UNTITLED6_CLIENTSTATUSPINGPACKET_H
#define UNTITLED6_CLIENTSTATUSPINGPACKET_H

#include "../../Packet.h"

class ClientStatusPingPacket : public Packet {

private:
    long payload;

public:
    void read(PacketReader in) override;

    long getPayload() const;
};

#endif //UNTITLED6_CLIENTSTATUSPINGPACKET_H
