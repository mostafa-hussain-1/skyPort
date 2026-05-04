#include <ctime>
#include <msclr/marshal_cppstd.h>
#include "database.h"
#include "add_admin.h"
#include "admin_home_page.h"
#include "hash_function.h"
using namespace std;
using namespace msclr::interop;
skyPort_array <admin> admins;
bool new_admin = true;
string ad_pass_word;
long long ad_hashed;

void add_new_admin(String^ ad_name, String^ ad_user_name, String^ ad_password, String^ ad_phone) {

    admin admin_data;
    admin_data.ad_name = marshal_as<string>(ad_name);
    admin_data.ad_user_name = marshal_as<string>(ad_user_name);
    ad_pass_word = marshal_as<string>(ad_password);
    admin_data.ad_phone = marshal_as<string>(ad_phone);

    new_admin = true;
    for (int i = 0; i < admins.size(); i++) {

        if (admins[i].ad_user_name == admin_data.ad_user_name) {
            new_admin = false;
            break;
        }
    }
    if (new_admin == true)
    {
        srand(time(0));
        int magic = rand() + 1;
        admin_data.ad_magic = magic;
        ad_hashed = hashing(ad_pass_word, magic);
        admin_data.ad_hashed_password = to_string(ad_hashed);

        admins.push_back(admin_data);
    }
}