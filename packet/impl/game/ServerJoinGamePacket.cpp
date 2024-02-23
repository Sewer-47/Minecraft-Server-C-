//
// Created by Sewerynek on 22.02.2024.
//

#include "ServerJoinGamePacket.h"

void ServerJoinGamePacket::write(PacketWritter out) {
    out.writeInt(2);//Entity ID	Int
    out.writeUnsignedByte(1);//Gamemode	Unsigned Byte
    out.writeInt(0);//Dimension	Int Enum
    out.writeLong(10);//Hashed seed	Long
    out.writeUnsignedByte(10);//Max Players	Unsigned Byte
    out.writeString("minecraft:default");//Level Type	String Enum (16)
    out.writeVarInt(9);//View Distance	VarInt
    out.writeBool(false);//Reduced Debug Info	Boolean
    out.writeBool(true);//Enable respawn screen	Boolean
}
