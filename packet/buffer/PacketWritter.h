//
// Created by Sewerynek on 23.02.2024.
//

#ifndef UNTITLED6_PACKETWRITTER_H
#define UNTITLED6_PACKETWRITTER_H

#include <winsock.h>
#include <vector>
#include <iostream>
#include <array>
#include <iomanip>
#include <cstring>

using namespace std;

class PacketWritter {

public:
    PacketWritter();

    vector<char> &getBuffer();

    void writeVarInt(int value);

    void writeLong(int64_t value);

    void writeString(const std::string& str);

    void writeInt(int value);

    void writeBool(bool value);

    void writeUnsignedByte(unsigned char value);

};

#endif //UNTITLED6_PACKETWRITTER_H
