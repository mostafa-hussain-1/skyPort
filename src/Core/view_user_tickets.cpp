#include <string>
#include "UI/Booking.h"
#include "DataStructures/skyport_array.h"
#include "include/view_user_tickets.h"
#include "UI/view_booked.h"
#include "UI/user_home_page.h"
#include "include/add_flights.h"
using namespace std;

skyPort_array<Booking>tickets;
skyPort_array<int> user_tickets;


void getUserTickets(string currentUser)
{
    user_tickets.clear();

    for (int i = 0; i < tickets.size(); i++)
    {
        if (tickets[i].user_name == currentUser)
        {
            user_tickets.push_back(i);
        }
    }
}

namespace skyPort {
    System::Void view_booked::cancel_button_Click(System::Object^ sender, System::EventArgs^ e) {
        DialogResult result = MessageBox::Show("Are you sure about canceling your ticket reservation?", "warning", MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
        
        if (result == DialogResult::No) return;

        int ticket_indx = stoi(marshal_as<string>(ticket_idx->Text));
        int traveler_indx = stoi(marshal_as<string>(traveler_idx->Text));
        
        int flight_indx = tickets[ticket_indx].flight_index;

        int seat_index = 0;
        for (int i = 0; i < flights[flight_indx].seats.size(); i++) {
            if (tickets[ticket_indx].travelers[traveler_indx].number_seats == flights[flight_indx].seats[i].seat_number) {
                seat_index = i;
            }
        }
        flights[flight_indx].seats[seat_index].is_booked = false;
        if (flight_category == "Economy") flights[flight_indx].seats_in_economy += 1;
        else if (flight_category == "Premium Economy") flights[flight_indx].seats_in_premium_economy += 1;
        else if (flight_category == "Business") flights[flight_indx].seats_in_business += 1;
        else if (flight_category == "First Class") flights[flight_indx].seats_in_first_class += 1;

        if (tickets[ticket_indx].travelers.size() > 1) {

            tickets[ticket_indx].travelers.erase(traveler_indx);
        }
        else {
            tickets.erase(ticket_indx);
        }

        if (userForm != nullptr) {

            user_home_page^ main = safe_cast<user_home_page^>(userForm);
            main->Booked_tickets_button_Click(sender, e);
        }
    }
}