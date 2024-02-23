cmake_minimum_required(VERSION 3.22)
project(untitled6)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled6 main.cpp packet/Packet.cpp packet/Packet.h packet/impl/handshake/ClientHandshakePacket.cpp packet/impl/handshake/ClientHandshakePacket.h packet/impl/status/ServerStatusResponsePacket.cpp packet/impl/status/ServerStatusResponsePacket.h packet/impl/status/ClientStatusRequestPacket.cpp packet/impl/status/ClientStatusRequestPacket.h Server.cpp Server.h session/Session.cpp session/Session.h packet/ProtocolState.h packet/impl/status/ClientStatusPingPacket.cpp packet/impl/status/ClientStatusPingPacket.h packet/impl/status/ServerStatusPongPacket.cpp packet/impl/status/ServerStatusPongPacket.h packet/impl/login/ClientLoginStartPacket.cpp packet/impl/login/ClientLoginStartPacket.h packet/impl/login/ServerLoginSuccessPacket.cpp packet/impl/login/ServerLoginSuccessPacket.h packet/impl/game/ServerJoinGamePacket.cpp packet/impl/game/ServerJoinGamePacket.h session/SessionPacketHandler.cpp session/SessionPacketHandler.h packet/buffer/PacketReader.cpp packet/buffer/PacketReader.h packet/buffer/PacketWritter.cpp packet/buffer/PacketWritter.h)
target_link_libraries(untitled6 ws2_32)