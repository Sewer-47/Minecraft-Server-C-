//
// Created by Sewerynek on 23.02.2024.
//

#include "PacketWritter.h"

vector<char> buffer;

PacketWritter::PacketWritter() {
    buffer = {};
}

vector<char> &PacketWritter::getBuffer() {
    return buffer;
}

void PacketWritter::writeVarInt(int value) {
    do {
        char byte = value & 0x7F;
        value >>= 7;
        if (value != 0) {
            byte |= 0x80;
        }
        buffer.push_back(byte);
    } while (value != 0);
}

void PacketWritter::writeLong(const int64_t value) {
    for (int i = 0; i < 8; ++i) {
        char byte = static_cast<char>((value >> (i * 8)) & 0xFF);
       buffer.push_back(byte);
    }
}

void PacketWritter::writeString(const string& str) {
    writeVarInt(str.length());
    buffer.insert(buffer.end(), str.begin(), str.end());
}

void PacketWritter::writeInt(int value) {
    char bytes[4];
    bytes[0] = static_cast<char>((value >> 24) & 0xFF);
    bytes[1] = static_cast<char>((value >> 16) & 0xFF);
    bytes[2] = static_cast<char>((value >> 8) & 0xFF);
    bytes[3] = static_cast<char>(value & 0xFF);
    buffer.insert(buffer.end(), begin(bytes), end(bytes));
}

void PacketWritter::writeBool(bool value) {
    char byte = value ? 0x01 : 0x00;
    buffer.push_back(byte);
}

void PacketWritter::writeUnsignedByte(unsigned char value) {
    char byte = static_cast<char>(value);
    buffer.push_back(byte);
}

