//
// Created by Sewerynek on 23.02.2024.
//

#include "PacketReader.h"


PacketReader::PacketReader() {
    //throw exception
}

PacketReader::PacketReader(SOCKET socket) {
    this->socket = socket;
}

int PacketReader::readVarInt() const {
    int result = 0;
    int shift = 0;
    char byte;
    do {
        int bytesReceived = recv(this->socket, &byte, sizeof(byte), 0);
        if (bytesReceived == SOCKET_ERROR || bytesReceived == 0) {
            cerr << "Error receiving data: " << WSAGetLastError() << endl;
            return -1;
        }
        result |= (byte & 0x7F) << shift;
        shift += 7;
        if (shift > 35) {
            cerr << "Error incorrect varint format" << endl;
            return -1;
        }
    } while ((byte & 0x80) != 0);
    return result;
}


string PacketReader::readString() {
    int len = this->readVarInt();
    if (len > SHRT_MAX) {
        throw invalid_argument("Cannot receive string longer than SHRT_MAX");
    }

    vector<char> buffer(len);
    int bytesReceived = recv(this->socket, buffer.data(), len, 0);
    if (bytesReceived == SOCKET_ERROR || bytesReceived == 0) {
        cerr << "Error receiving data: " << WSAGetLastError() << endl;
        throw runtime_error("Error receiving data");
    }

    return string(buffer.begin(), buffer.begin() + bytesReceived);
}

unsigned short PacketReader::readUnsignedShort() {
    unsigned short value;
    int bytesReceived = recv(this->socket, reinterpret_cast<char*>(&value), sizeof(value), 0);
    if (bytesReceived != sizeof(value)) {
        cerr << "Error receiving data: " << WSAGetLastError() << endl;
        throw runtime_error("Error receiving data");
    }
    return ntohs(value);
}

long long PacketReader::readLong() {
    long long value;
    int bytesReceived = recv(this->socket, reinterpret_cast<char*>(&value), sizeof(value), 0);
    if (bytesReceived != sizeof(value)) {
        cerr << "Error receiving data: " << WSAGetLastError() << endl;
        throw runtime_error("Error receiving data");
    }
    return value;
}