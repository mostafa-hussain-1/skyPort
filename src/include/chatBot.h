#pragma once
#include <string>
#include "DataStructures/skyport_array.h"
using namespace std;

struct messageStruct {
    string user_name;
    string message;
    bool replied;
    bool if_admin;
};


void show_chats();

void open_chat(string user_name);

extern skyPort_array<messageStruct> messages_array;

extern skyPort_array<messageStruct> chat_messages;

extern skyPort_array<messageStruct> chats;