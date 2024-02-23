//
// Created by Sewerynek on 20.02.2024.
//

#ifndef UNTITLED6_PACKET_H
#define UNTITLED6_PACKET_H

#include <winsock2.h>
#include <iostream>
#include <vector>
#include "buffer/PacketReader.h"
#include "buffer/PacketWritter.h"

using namespace std;

class Packet {
public:
    virtual void read(PacketReader in);

    virtual void write(PacketWritter out);
};
#endif //UNTITLED6_PACKET_H
