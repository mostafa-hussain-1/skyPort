#include <string>
#include <msclr/marshal_cppstd.h>
#include "include/airports.h"
#include "UI/admin_home_page.h"
#include "include/add_flights.h"
#include "include/add_plane.h"
using namespace msclr::interop;
using namespace std;

bool flight_update = false;
int selected_flight_idx;
string flight_category = "Economy";

skyPort_array <flight_struct> flights;

void add_flight(string number_flight, string plane_code, string departure, string arrival, DateTime final_date_departure, DateTime final_date_arrival, double economy_price_value, double business_price_value, double frist_class_price_value, double premium_economy_price_value, int flight_duration) {

	flight_struct f;
	f.number_flight = number_flight;
	f.plane_code = plane_code;
	f.departure_airport = departure;
	f.arrival_airport = arrival;
	f.price.economy_price = economy_price_value;
	f.price.business_price = business_price_value;
	f.price.first_class_price = frist_class_price_value;
	f.price.premium_economy_price = premium_economy_price_value;
	f.departure_date = marshal_as<string>(final_date_departure.ToString("ddd,dd/MMM/yyyy"));
	f.time_departure = marshal_as<string>(final_date_departure.ToString("hh:mm tt"));
	f.arrival_date = marshal_as<string>(final_date_arrival.ToString("ddd,dd/MMM/yyyy"));
	f.time_arrival = marshal_as<string>(final_date_arrival.ToString("hh:mm tt"));
	f.flight_duration = flight_duration;
	

	for (int i = 0; i < planes.size(); i++)
	{
		if (plane_code == planes[i].code) {
			f.plane_model = planes[i].model;
			f.total_seats = planes[i].rows * planes[i].nom_of_seats;
			f.seats_in_economy = planes[i].rows * planes[i].nom_of_seats * 0.1;
			f.seats_in_premium_economy = planes[i].rows * planes[i].nom_of_seats * 0.15;
			f.seats_in_business = planes[i].rows * planes[i].nom_of_seats * 0.25;
			f.seats_in_first_class = planes[i].rows * planes[i].nom_of_seats * 0.5;


			planes[i].place = arrival;

			// Generate seat numbers based on the number of rows and seats in the plane
			int assigned_seats = 0;
			for (int j = 1; j <= planes[i].rows; j++)
			{
				string seat;
				string chair_letter = "a";
				string chair_nom;
				for (int k = 0; k < planes[i].nom_of_seats; k++, assigned_seats++)
				{
					flight_struct::seat_struct new_seat;
					chair_nom = to_string(j);
					seat = chair_letter;
					seat = seat.append(chair_nom);

					new_seat.seat_number = seat;
					new_seat.is_booked = false;
					if (assigned_seats < f.total_seats *0.5) {
						new_seat.seat_category = "First Class";
					}
					else if (assigned_seats < f.total_seats * 0.75) {
						new_seat.seat_category = "Business";
					}
					else if (assigned_seats < f.total_seats * 0.9) {
						new_seat.seat_category = "Premium Economy";
					}
					else {
						new_seat.seat_category = "Economy";
					}
					f.seats.push_back(new_seat);
					chair_letter[0] += 1;
				}
			}
		}
	}
	for (int i = 0; i < airports.size(); i++)
	{
		if (departure == airports[i].name) {
			f.d_iata = airports[i].iata_code;
		}
		if (arrival == airports[i].name) {
			f.a_iata = airports[i].iata_code;
		}
	}

	
	if (flight_update) {
		flights[selected_flight_idx] = f;
	}
	else flights.push_back(f);
}

