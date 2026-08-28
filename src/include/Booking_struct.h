#pragma once
#include <iostream>
#include <string>
#include "DataStructures/skyport_array.h"
using namespace std;
struct Booking
{
	string user_name;
	int flight_index;
	string category;
	int num_of_travelers;
	struct traveler_data {
		string first_name;
		string middle_name;
		string last_name;
		string date_of_birth;
		string meal_preference;
		int price;
		bool male;
		string passport_number;
		string number_seats;
	};
	skyPort_array<traveler_data> travelers;

};
extern skyPort_array<Booking>tickets;