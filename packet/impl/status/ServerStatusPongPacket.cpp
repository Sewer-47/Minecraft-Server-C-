//
// Created by Sewerynek on 21.02.2024.
//

#include "ServerStatusPongPacket.h"

void ServerStatusPongPacket::write(PacketWritter out) {
    out.writeLong(this->payload);
}

void ServerStatusPongPacket::setPayload(long payload) {
    this->payload = payload;
}
