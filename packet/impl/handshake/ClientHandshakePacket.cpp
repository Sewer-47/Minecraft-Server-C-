//
// Created by Sewerynek on 20.02.2024.
//
#include "ClientHandshakePacket.h"

void ClientHandshakePacket::read(PacketReader in) {
    this->protocol = in.readVarInt();
    this->address = in.readString();
    this->port = in.readUnsignedShort();

    int stateId = in.readVarInt();
    this->state = (stateId == 1) ? ProtocolState::STATUS : ProtocolState::LOGIN;
}

int ClientHandshakePacket::getAProtocol() const {
    return this->protocol;
}

const string &ClientHandshakePacket::getAddress() const {
    return this->address;
}

short ClientHandshakePacket::getPort() const {
    return this->port;
}

ProtocolState ClientHandshakePacket::getState() const {
    return this->state;
}