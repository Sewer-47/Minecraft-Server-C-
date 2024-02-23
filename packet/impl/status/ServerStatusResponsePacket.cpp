//
// Created by Sewerynek on 20.02.2024.
//

#include "ServerStatusResponsePacket.h"

using namespace std;

void ServerStatusResponsePacket::write(PacketWritter out) {
    string json = "{\n"
                  "    \"version\": {\n"
                  "        \"name\": \"1.12.2\",\n"
                  "        \"protocol\": 578\n"
                  "    },\n"
                  "    \"players\": {\n"
                  "        \"max\": 100,\n"
                  "        \"online\": 500,\n"
                  "        \"sample\": [\n"
                  "            {\n"
                  "                \"name\": \"PatyczkiDoUszuw_\",\n"
                  "                \"id\": \"4566e69f-c907-48ee-8d71-d7ba5aa00d20\"\n"
                  "            }\n"
                  "        ]\n"
                  "    },\n"
                  "    \"description\": {\n"
                  "        \"text\": \"§3C++ Learning project\na minecraft server\"\n"
                  "    },\n"
                  "    \"favicon\": \"data:image/png;base64,<data>\",\n"
                  "    \"enforcesSecureChat\": true,\n"
                  "    \"previewsChat\": true\n"
                  "}";
    out.writeString(json);
}


