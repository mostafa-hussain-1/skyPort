#include <string>
#include "include/hash_function.h"
#include "DataStructures/skyport_array.h"
#include "include/sign_up_users.h"
#include "include/add_admin.h"
using namespace std;
bool is_admin = false;


bool is_signed_in = false;
string current_user_name = "null";
string first_name = "null";

bool sign_in_user(string user_name, string password) {

	for (int i = 0; i < users.size(); i++) {

		if (users[i].user_name == user_name) {
			string hash_password = "*";
			hash_password = to_string(hashing(password, users[i].magic));
			if (users[i].hashed_password == hash_password) {

				int spacePos = users[i].name.find(' ');
				if (spacePos != -1) {
					first_name = users[i].name.substr(0, spacePos);
				}
				else {
					first_name = users[i].name;
				}

				current_user_name = user_name; 
				is_signed_in = true;
				return true;
			}
			break;
		}
	}
	return false;

} // funct



bool sign_in_admin(string admin_user_name, string password) {

	for (int i = 0; i < admins.size(); i++) {

		if (admins[i].ad_user_name == admin_user_name) {
			string hash_password = "*";
			hash_password = to_string(hashing(password, admins[i].ad_magic));
			if (admins[i].ad_hashed_password == hash_password) {
				int spacePos = admins[i].ad_name.find(' ');

				if (spacePos != -1) {
					first_name = admins[i].ad_name.substr(0, spacePos);
				}
				else {
					first_name = admins[i].ad_name;
				}
				current_user_name = admin_user_name;
				is_signed_in = true;
				return true;
			}
			break;
		}
	} // for loop

	return false;

} // funct
