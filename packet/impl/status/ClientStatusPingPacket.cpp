//
// Created by Sewerynek on 21.02.2024.
//

#include "ClientStatusPingPacket.h"

void ClientStatusPingPacket::read(PacketReader in) {
    this->payload = in.readLong();
}

long ClientStatusPingPacket::getPayload() const {
    return this->payload;
}
