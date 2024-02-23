//
// Created by Sewerynek on 22.02.2024.
//

#ifndef UNTITLED6_SERVERLOGINSUCCESSPACKET_H
#define UNTITLED6_SERVERLOGINSUCCESSPACKET_H


#include "../../Packet.h"
#include "array"

class ServerLoginSuccessPacket : public Packet {

private:
    array<unsigned char, 16> uniqueId;
    string nickname;

public:
    void write(PacketWritter out) override;

    void setUniqueId(const array<unsigned char, 16> &uniqueId);

    void setNickname(const string &nickname);
};

#endif //UNTITLED6_SERVERLOGINSUCCESSPACKET_H
