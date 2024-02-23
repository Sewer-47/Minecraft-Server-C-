//
// Created by Sewerynek on 20.02.2024.
//

#ifndef UNTITLED6_CLIENTHANDSHAKEPACKET_H
#define UNTITLED6_CLIENTHANDSHAKEPACKET_H

#include "../../Packet.h"
#include "string"
#include "../../ProtocolState.h"

class ClientHandshakePacket : public Packet {

private:
    int protocol;
    string address;
    short port;
    ProtocolState state;

public:
    void read(PacketReader in) override;

    int getAProtocol() const;

    const string &getAddress() const;

    short getPort() const;

    ProtocolState getState() const;
};


#endif //UNTITLED6_CLIENTHANDSHAKEPACKET_H
