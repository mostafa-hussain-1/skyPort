#include "flight_result.h"
#include "booking.h"
#include "user_home_page.h"


namespace skyPort {
	 System::Void flight_result::book_Click(System::Object^ sender, System::EventArgs^ e) {
		
		selected_flight_idx = stoi(marshal_as<string>(this->index->Text));
		if (current_user_name == "null") {
			MessageBox::Show("Please sign in to book a flight.", "Sign In Required", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		if (userForm != nullptr) {

			user_home_page^ main = safe_cast<user_home_page^>(userForm);
			main->search_flights_panel->Visible = false;
			main->fav_view_panel->Visible = false;
			main->data_booking_panal->Controls->Clear();
			main->data_booking_panal->Visible = true;
			main->check_out_panal->Visible = true;


			for (int i = 1; i <= total_travelers; i++)
			{
				booking^ card = gcnew booking(userForm);
				card->setpassengerNumber(i);
				if (i == total_travelers)
					card->show_buttton();
				main->data_booking_panal->Controls->Add(card);

			}
		}
	}
	
}