//
// Created by Sewerynek on 22.02.2024.
//

#include "ServerLoginSuccessPacket.h"

void ServerLoginSuccessPacket::write(PacketWritter out) {//1.15.2
    out.writeString("4566e69f-c907-48ee-8d71-d7ba5aa00d20");//UUID	String (36)
    out.writeString(this->nickname);//Username	String (16)
}

void ServerLoginSuccessPacket::setUniqueId(const array<unsigned char, 16> &uniqueId) {
    //ServerLoginSuccessPacket::uniqueId = uniqueId;
}

void ServerLoginSuccessPacket::setNickname(const string &nickname) {
    this->nickname = nickname;
}
