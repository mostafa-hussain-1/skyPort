#pragma once
#include <msclr/marshal_cppstd.h>
#include <string>
#include "skyport_array.h"
using namespace System;
using namespace std;
struct admin {
    string ad_name;
    string ad_user_name;
    string ad_hashed_password;
    int ad_magic;
    string ad_phone;
};

extern skyPort_array<admin> admins;
extern bool new_admin;
extern string ad_pass_word;
extern long long ad_hashed;
long  long n;

void add_new_admin(String^ ad_name, String^ ad_user_name, String^ ad_password, String^ ad_phone);