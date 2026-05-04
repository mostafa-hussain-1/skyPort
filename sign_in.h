#pragma once
#include "add_admin.h"
#include "sign_up_users.h"
#include "hash_function.h"
#include "skyport_array.h"
using namespace std;
extern bool is_admin;
extern string current_user_name;
extern string first_name;

extern bool is_signed_in;

bool sign_in_user(string user_name, string password);

bool sign_in_admin(string admin_name, string password);