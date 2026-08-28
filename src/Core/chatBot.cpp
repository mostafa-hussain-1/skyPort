#include <iostream>
#include <string>
#include "DataStructures/skyport_array.h"
#include "include/chatbot.h"
using namespace std;

skyPort_array<messageStruct> messages_array;

skyPort_array<messageStruct> chat_messages;

skyPort_array<messageStruct> chats;
void show_chats() {
    chats.clear();
    for (int i = messages_array.size() - 1; i >= 0; i--) {

        bool exist = false;

        for (int j = 0; j < chats.size(); j++) {
            if (messages_array[i].user_name == chats[j].user_name) {
                exist = true;
                break;
            }
        }

        if (!messages_array[i].replied && !exist) {
            messageStruct chat;
            chat.user_name = messages_array[i].user_name;
            chat.message = messages_array[i].message;
            chats.push_back(chat);
        }
    }
}

void open_chat(string user_name) {

	chat_messages.clear();
    for (int i = 0; i < messages_array.size(); i++) {

        if (user_name == messages_array[i].user_name) {

            chat_messages.push_back(messages_array[i]);
        }
    }
}