#include <iostream>
#include <msclr/marshal_cppstd.h>
#include "UI/sign_up_users_form.h"
#include "include/sign_up_users.h"
#include "include/database.h"
#include "include/hash_function.h"
using namespace std;
using namespace System;
using namespace System::Windows::Forms;

skyPort_array<user> users;
bool new_user = true;
string pass_word;
long long hashed;

void sign_up_user(String^ name, String^ user_name, String^ password, String^ phone) {
	msclr::interop::marshal_context context;
	user user_data;
	user_data.name = context.marshal_as<string>(name);
	user_data.user_name = context.marshal_as<string>(user_name);
	pass_word = context.marshal_as<string>(password);
	user_data.phone = context.marshal_as<string>(phone);

	new_user = true;
	for (int i = 0; i <= users.size(); i++)
	{
		if (user_data.user_name == users[i].user_name || user_data.phone == users[i].phone)
		{
			new_user = false;
			break;
		}
	}
	if (new_user == true)
	{
		user_data.magic = magic();
		hashed = hashing(pass_word, user_data.magic);
		user_data.hashed_password = to_string(hashed);

		users.push_back(user_data);
	}
}

