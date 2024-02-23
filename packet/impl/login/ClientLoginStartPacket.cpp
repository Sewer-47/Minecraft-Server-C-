//
// Created by Sewerynek on 22.02.2024.
//

#include "ClientLoginStartPacket.h"

void ClientLoginStartPacket::read(PacketReader in) {
    this->name = in.readString();
   //this->uniqueId = PacketSerializer::readUUID(in);  it does not exist in version 1.15.2
}

const string &ClientLoginStartPacket::getName() const {
    return this->name;
}

const array<unsigned char, 16> &ClientLoginStartPacket::getUniqueId() const {
    return this->uniqueId;
}
