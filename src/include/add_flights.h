#pragma once
#include <string>
#include "DataStructures/skyport_array.h"
using namespace std;
using namespace System;
struct flight_struct
{
    string number_flight;
    string plane_code;
    string plane_model;
    string departure_airport;
    string d_iata;
    string arrival_airport;
    string a_iata;
    struct price {
        int economy_price;
        int premium_economy_price;
        int business_price;
        int first_class_price;
    } price;

    string departure_date;
    string time_departure;
    string arrival_date;
    string time_arrival;
	int flight_duration;
    string state = "open to book";

    int total_seats;
    struct seat_struct {
        string seat_number;
        bool is_booked;
        string seat_category;
    };

    skyPort_array<seat_struct> seats;

    int seats_in_economy;
    int seats_in_premium_economy;
    int seats_in_business;
    int seats_in_first_class;
};
extern skyPort_array <flight_struct> flights;
void add_flight(string number_flight, string plane_code, string departure, string arrival, DateTime final_date_departure, DateTime final_date_arrival, double economy_price_value, double business_price_value, double frist_class_price_value, double premium_economy_price_value, int flight_duration);
