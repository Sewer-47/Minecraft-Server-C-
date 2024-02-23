//
// Created by Sewerynek on 22.02.2024.
//

#ifndef UNTITLED6_CLIENTLOGINSTARTPACKET_H
#define UNTITLED6_CLIENTLOGINSTARTPACKET_H


#include "../../Packet.h"
#include <array>

class ClientLoginStartPacket : public Packet {

private:
    string name;
    array<unsigned char, 16> uniqueId;

public:
    void read(PacketReader in) override;

    const string &getName() const;

    const array<unsigned char, 16> &getUniqueId() const;
};


#endif //UNTITLED6_CLIENTLOGINSTARTPACKET_H
