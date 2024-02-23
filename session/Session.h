//
// Created by Sewerynek on 21.02.2024.
//

#ifndef UNTITLED6_SESSION_H
#define UNTITLED6_SESSION_H

#include "../packet/Packet.h"
#include "../packet/ProtocolState.h"

class Session {

private:
    SOCKET socket;
    ProtocolState packetState;
    PacketReader packetReader;
    bool open;

public:
    Session();

    Session(SOCKET socket);

    void sendPacket(Packet &packet, int id);

    void channelRead(int id);

    SOCKET getSocket() const;

    const PacketReader getPacketReader() const;

    const ProtocolState &getPacketState() const;

    void setPacketState(ProtocolState packetState);

    bool isOpen() const;

    void setOpen(bool open);
};


#endif //UNTITLED6_SESSION_H
