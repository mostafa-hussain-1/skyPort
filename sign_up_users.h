#pragma once
#include <msclr/marshal_cppstd.h>
#include <string>
#include "skyport_array.h"
using namespace System;
using namespace std;
struct user {
	string name;
	string user_name;
	string hashed_password;
	int magic;
	string phone;
};
extern skyPort_array <user> users;
extern bool new_user;
extern string pass_word;
extern long long hashed;
void sign_up_user(String^ name, String^ user_name, String^ password, String^ phone);