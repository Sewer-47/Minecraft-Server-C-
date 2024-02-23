//
// Created by Sewerynek on 21.02.2024.
//

#include "Server.h"
#include <iostream>
#include <winsock2.h>
#include <memory>
#include "packet/impl/handshake/ClientHandshakePacket.h"
#include "session/Session.h"

std::unique_ptr<Session> session;

DWORD WINAPI ClientThread(LPVOID lpParam) {
    SOCKET clientSocket = reinterpret_cast<SOCKET>(lpParam);

    while (session->isOpen()) {
        int length = session->getPacketReader().readVarInt();
        int id = session->getPacketReader().readVarInt();
        session->channelRead(id);
    }
    closesocket(clientSocket);
    cout << "[Server.cpp] Connection closed" << endl;
    return 0;
}

void handleConnection(SOCKET clientSocket) {
    cout << "[Server.cpp] New connection opened" << endl;
    session = std::make_unique<Session>(clientSocket);

    DWORD threadId;
    HANDLE threadHandle = CreateThread(NULL, 0, ClientThread, reinterpret_cast<LPVOID>(clientSocket), 0, &threadId);
    if (threadHandle == NULL) {
        std::cerr << "Error creating thread: " << GetLastError() << std::endl;
        closesocket(clientSocket);
    } else {
        CloseHandle(threadHandle);
    }
}


void Server::start() {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(25565);

    if (bind(listenSocket, (sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
        std::cerr << "[Server.cpp] Server binding failed:  " << WSAGetLastError() << std::endl;
        closesocket(listenSocket);
        WSACleanup();
        return;
    }

    listen(listenSocket, SOMAXCONN);
    std::cout << "[Server.cpp] Server running on: 25565" << std::endl;

    while (true) {
        SOCKET clientSocket = accept(listenSocket, nullptr, nullptr);
        handleConnection(clientSocket);
    }
}
