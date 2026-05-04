#include <iostream>
#include "skyport_array.h"
#include "sign_up_users.h"
#include "hash_function.h"
#include "add_admin.h"
using namespace std;

bool forget_password(bool isadmin, string username, string phone, string newpass, string cnf_newpass) {

	if (!isadmin) {

		for (int i = 0; i < users.size(); i++) {

			if (users[i].user_name == username && users[i].phone == phone) {


				srand(time(0));
				int magic = rand() + 1;
				users[i].magic = magic;
				hashed = hashing(newpass, magic);
				users[i].hashed_password = to_string(hashed);
				return true;

			}
		}
		return false;
	}
	else {

		for (int i = 0; i < admins.size(); i++) {

			if (admins[i].ad_user_name == username && admins[i].ad_phone == phone) {


				srand(time(0));
				int magic = rand() + 1;
				admins[i].ad_magic = magic;
				hashed = hashing(newpass, magic);
				admins[i].ad_hashed_password = to_string(hashed);
				return true;
			}
		}
		return false;
	}
};