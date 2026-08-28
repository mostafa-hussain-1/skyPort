#include "UI/flight_result.h"
#include "UI/booking.h"
#include "UI/user_home_page.h"
#include "include/sign_in.h"
#include "include/add_flights.h"

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
			if (flight_category == "Economy") {
				adult_price = flights[selected_flight_idx].price.economy_price;
			}
			else if (flight_category == "Business") {
				adult_price = flights[selected_flight_idx].price.business_price;
			}
			else if (flight_category == "Premium Economy") {
				adult_price = flights[selected_flight_idx].price.premium_economy_price;
			}
			else {
				adult_price = flights[selected_flight_idx].price.first_class_price;
			}
			main->cnt_adult->Text = "Adult " + "(" + adult_cnt_value.ToString()+")";
			main->cnt_child->Text ="Child " + "(" + children_cnt_value.ToString() + ")";
			main->cnt_infant->Text = "Infant " + "(" + infants_cnt_value.ToString() + ")";
			main->price_adult->Text = (adult_cnt_value*adult_price).ToString() + " $";
			main->price_child->Text = (children_cnt_value * adult_price * 0.75).ToString() + " $";
			main->price_infant->Text = (infants_cnt_value * adult_price * 0.1).ToString() + " $";
			main->total_price->Text = ((adult_cnt_value * adult_price) + (children_cnt_value * adult_price * 0.75) + (infants_cnt_value * adult_price * 0.1)).ToString();
			main->get_discount_button->Visible = true;

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