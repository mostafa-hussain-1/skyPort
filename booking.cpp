#include "booking.h"
#include "flight_result.h"
#include "user_home_page.h"
int adult_cnt_value = 1;
int children_cnt_value = 0;
int infants_cnt_value = 0;
int total_travelers = 1;

namespace skyPort {
	System::Void booking::book_button_Click(System::Object^ sender, System::EventArgs^ e) {
		Booking f;
		f.user_name = current_user_name;
		f.flight_index = selected_flight_idx;
		f.category = flight_category;
		f.num_of_travelers = total_travelers;
		Booking::traveler_data t;

		if (userForm != nullptr) {

			user_home_page^ main = safe_cast<user_home_page^>(userForm);
			Control^ parentContainer = this->Parent;

			if (parentContainer != nullptr) {

				int total_price = 0;
				for each (Control ^ c in parentContainer->Controls) {

					booking^ currentPassenger = dynamic_cast<booking^>(c);

					if (currentPassenger != nullptr) {
						if (currentPassenger->first_name_testbox->Text == "First name" || currentPassenger->middle_name_testbox->Text == "Middle name" || currentPassenger->last_name_testbox->Text == "Last name" ||
							currentPassenger->passport_number_textbox->Text == "Passport number" || currentPassenger->gender_combobox->Text == "Select" || currentPassenger->meals_comboBox->Text == "Select") {
							MessageBox::Show("Please fill in all the required fields!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
							return;
						}
						Regex^ passport_pattern = gcnew Regex("^[0-9]+$");
						String^ passport_num = currentPassenger->passport_number_textbox->Text;
						if (!passport_pattern->IsMatch(passport_num)) {
							MessageBox::Show("Please enter a valid passport number!", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
							return;
						}

						string first_name = marshal_as<string>(currentPassenger->first_name_testbox->Text);

						string middle_name = marshal_as<string>(currentPassenger->middle_name_testbox->Text);

						string last_name = marshal_as<string>(currentPassenger->last_name_testbox->Text);

						string passport_number = marshal_as<string>(currentPassenger->passport_number_textbox->Text);

						string gender = marshal_as<string>(currentPassenger->gender_combobox->Text);

						string meal_preference = marshal_as<string>(currentPassenger->meals_comboBox->Text);

						DateTime dateOfBirth = currentPassenger->dateTimePicker1->Value;
						string s = marshal_as<string>(dateOfBirth.ToString("dd/MM/yyyy"));

						t.first_name = first_name;
						t.middle_name = middle_name;
						t.last_name = last_name;
						t.passport_number = passport_number;
						t.date_of_birth = s;
						t.meal_preference = meal_preference;
						if (gender == "male")
							t.male = true;
						else
							t.male = false;
						
						int price;
						
						if (f.category == "Economy") {
							price = flights[f.flight_index].price.economy_price;
							flights[f.flight_index].seats_in_economy--;
						}
						else if (f.category == "Business") {
							price = flights[f.flight_index].price.business_price;
							flights[f.flight_index].seats_in_business--;
						}
						else if (f.category == "Premium Economy") {
							price = flights[f.flight_index].price.premium_economy_price;
							flights[f.flight_index].seats_in_premium_economy--;
						}
						else {
							price = flights[f.flight_index].price.first_class_price;
							flights[f.flight_index].seats_in_first_class--;
						}
						if (adult_cnt_value--) {
							t.price = price;
							total_price += t.price;
							for (int i = 0; i < flights[f.flight_index].seats.size(); i++)
							{
								if (flights[f.flight_index].seats[i].seat_category == f.category && !flights[f.flight_index].seats[i].is_booked) {
									flights[f.flight_index].seats[i].is_booked = true;
									t.number_seats = flights[f.flight_index].seats[i].seat_number;
									break;
								}
							}
						}
						else if (children_cnt_value--) {
							t.price = price * 0.75;
							total_price += t.price;
							for (int i = 0; i < flights[f.flight_index].seats.size(); i++)
							{
								if (flights[f.flight_index].seats[i].seat_category == f.category && !flights[f.flight_index].seats[i].is_booked) {
									flights[f.flight_index].seats[i].is_booked = true;
									t.number_seats = flights[f.flight_index].seats[i].seat_number;
									break;
								}
							}
						}
						else if (infants_cnt_value--) {
							t.price = price * 0.1;
							total_price += t.price;
						}
						f.travelers.push_back(t);
					}
				}
				tickets.push_back(f);
				MessageBox::Show("Booking successful!\nTotal price is " + total_price.ToString() + "$", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				main->data_booking_panal->Visible = false;
			}
		}
	}
}