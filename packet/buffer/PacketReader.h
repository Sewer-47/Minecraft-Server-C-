//
// Created by Sewerynek on 23.02.2024.
//

#ifndef UNTITLED6_PACKETREADER_H
#define UNTITLED6_PACKETREADER_H


#include <winsock.h>
#include <vector>
#include <iostream>
#include <array>
#include <iomanip>
#include <cstring>

using namespace std;

class PacketReader {
private:
    SOCKET socket;

public:
    PacketReader();

    PacketReader(SOCKET socket);

    int readVarInt() const;

    string readString();

    unsigned short readUnsignedShort();

    long long readLong();
};


#endif //UNTITLED6_PACKETREADER_H
