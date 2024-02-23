//
// Created by Sewerynek on 23.02.2024.
//

#include "SessionPacketHandler.h"
#include "../packet/impl/handshake/ClientHandshakePacket.h"
#include "../packet/impl/status/ClientStatusRequestPacket.h"
#include "../packet/impl/status/ServerStatusResponsePacket.h"
#include "../packet/impl/status/ClientStatusPingPacket.h"
#include "../packet/impl/status/ServerStatusPongPacket.h"
#include "../packet/impl/login/ClientLoginStartPacket.h"
#include "../packet/impl/login/ServerLoginSuccessPacket.h"
#include "../packet/impl/game/ServerJoinGamePacket.h"

SessionPacketHandler::SessionPacketHandler(Session *session) {
    this->session = session;
}

void SessionPacketHandler::handle(int id) {
    cout << "[SessionPacketHandler.cpp] Received packet id: " << id << endl;

    if (id == -1) {
        this->session->setOpen(false);
    }

    switch (this->session->getPacketState()) {
        case HANDSHAKE:
            if (id == 0) {
                ClientHandshakePacket handshaking = ClientHandshakePacket();
                handshaking.read(this->session->getSocket());
                this->session->setPacketState(handshaking.getState());
            }
            break;
        case STATUS:
            if (id == 0) {
                ClientStatusRequestPacket request = ClientStatusRequestPacket();
                request.read(this->session->getSocket());

                ServerStatusResponsePacket packet = ServerStatusResponsePacket();
                this->session->sendPacket(packet, 0x00);
            } else if (id == 1) {
                ClientStatusPingPacket request = ClientStatusPingPacket();
                request.read(this->session->getSocket());

                ServerStatusPongPacket response = ServerStatusPongPacket();
                response.setPayload(request.getPayload());
                this->session->sendPacket(response, 0x01);

                this->session->setOpen(false);
            }
            break;
        case LOGIN:
            if (id == 0) {
                ClientLoginStartPacket loginStart = ClientLoginStartPacket();
                loginStart.read(this->session->getSocket());
                cout << "[SessionPacketHandler.cpp] Player's nickname: " << loginStart.getName() << endl;

                ServerLoginSuccessPacket succcess = ServerLoginSuccessPacket();
                succcess.setNickname(loginStart.getName());
                this->session->sendPacket(succcess, 0x02);

                this->session->setPacketState(GAME);


                ServerJoinGamePacket login = ServerJoinGamePacket();
                this->session->sendPacket(login, 0x26);
            }
            break;
        case GAME:

            break;
    }
}