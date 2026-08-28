#include <iostream>
#include "DataStructures/skyport_array.h"
#include "include/sign_up_users.h"
#include "include/hash_function.h"
#include "include/add_admin.h"
using namespace std;

bool forget_password(bool isadmin, string username, string phone, string newpass, string cnf_newpass) {

	if (!isadmin) {

		for (int i = 0; i < users.size(); i++) {

			if (users[i].user_name == username && users[i].phone == phone) {

				users[i].magic = magic();
				hashed = hashing(newpass, users[i].magic);
				users[i].hashed_password = to_string(hashed);
				return true;

			}
		}
		return false;
	}
	else {

		for (int i = 0; i < admins.size(); i++) {

			if (admins[i].ad_user_name == username && admins[i].ad_phone == phone) {

				admins[i].ad_magic = magic();
				hashed = hashing(newpass, admins[i].ad_magic);
				admins[i].ad_hashed_password = to_string(hashed);
				return true;
			}
		}
		return false;
	}
};