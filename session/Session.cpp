//
// Created by Sewerynek on 21.02.2024.
//

#include <sstream>
#include "Session.h"
#include "../packet/impl/status/ServerStatusResponsePacket.h"
#include "SessionPacketHandler.h"

SessionPacketHandler *packetHandler;

Session::Session() {
    throw std::runtime_error("Session can be initialized with empty constructor");
}

Session::Session(SOCKET socket) {
    this->socket = socket;
    this->packetState = ProtocolState::HANDSHAKE;
    this->open = true;

    this->packetReader = PacketReader(this->socket);
    packetHandler = new SessionPacketHandler(this);

}

void Session::sendPacket(Packet &packet, int id) {
    cout << "[Session.cpp] Sending packet id: " << id << endl;

    PacketWritter helpWritter = PacketWritter();
    helpWritter.writeVarInt(id);
    packet.write(helpWritter);
    vector<char> helpBuffer = helpWritter.getBuffer();

    PacketWritter writter = PacketWritter();
    writter.writeVarInt(helpBuffer.size());
    vector<char> buffer = writter.getBuffer();
    buffer.insert(buffer.end(), helpBuffer.begin(), helpBuffer.end());

    send(this->socket, buffer.data(), buffer.size(), 0);//WINSOCK FUNCTION
}

void Session::setPacketState(ProtocolState packetState) {
    cout << "[Session.cpp] Switching protocol to: ";
    if (packetState == ProtocolState::HANDSHAKE) cout << "Handshake" << endl;
    if (packetState == ProtocolState::STATUS) cout << "Status" << endl;
    if (packetState == ProtocolState::LOGIN) cout << "Login" << endl;
    if (packetState == ProtocolState::GAME) cout << "Game" << endl;

    this->packetState = packetState;
}

void Session::channelRead(int id) {
    packetHandler->handle(id);
}

SOCKET Session::getSocket() const {
    return this->socket;
}

const ProtocolState &Session::getPacketState() const {
    return this->packetState;
}

bool Session::isOpen() const {
    return this->open;
}

void Session::setOpen(bool open) {
    this->open = open;
}

const PacketReader Session::getPacketReader() const {
    return this->packetReader;
}
