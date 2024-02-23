//
// Created by Sewerynek on 23.02.2024.
//

#ifndef UNTITLED6_SESSIONPACKETHANDLER_H
#define UNTITLED6_SESSIONPACKETHANDLER_H


#include "../packet/Packet.h"
#include "Session.h"

class SessionPacketHandler {

private:
    Session *session;

public:
    SessionPacketHandler(Session *session);

    void handle(int id);
};


#endif //UNTITLED6_SESSIONPACKETHANDLER_H
