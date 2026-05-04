#include "chat_list.h"
#include "admin_home_page.h" 
string user_sender;
namespace skyPort {
    
    System::Void chat_list::message_label_Click(System::Object^ sender, System::EventArgs^ e) {

        if (adminForm != nullptr) {
            user_sender = marshal_as <string>(user_name_label->Text);
            admin_home_page^ main = safe_cast<admin_home_page^>(adminForm);

            main->messages_Load(marshal_as<string>(this->user_name_label->Text));
            main->txtMessage->Visible = true;
        }
    }
}