#include<iostream>
#include<string>
#include <sstream>
#include<fstream>
#include"include/sign_up_users.h"
#include"include/add_admin.h"
#include"include/add_plane.h"
#include"include/airports.h"
#include"include/add_flights.h"
#include"include/fav_flights.h"
#include"include/database.h"
#include"include/chatBot.h"
#include"include/Booking_struct.h"
using namespace std;
skyPort_array<airport_data> airports;
//upload database

void upload_database() {
    upload_users();
    upload_admins();
    upload_planes();
	upload_airports();
    upload_flights();
	upload_favorite_flights();
    upload_tickets();
    upload_messages();
}

void upload_users() {
    ifstream upload_users;
    upload_users.open("database\\users.txt");
    string line;
    int pos = 0, data = 0;
    string mycut;
    while (getline(upload_users, line)) {
        pos = 0, data = 0;
        user user_data;
        while (pos != -1) {
            pos = line.find(';');
            mycut = line.substr(0, pos);
            if (data == 0) {
                user_data.name = mycut;
            }
            else if (data == 1) {
                user_data.user_name = mycut;
            }
            else if (data == 2) {
                user_data.hashed_password = (mycut);
            }
            else if (data == 3) {
                user_data.magic = stoi(mycut);
            }
            else if (data == 4) {
                user_data.phone = mycut;
			}
            line = line.substr(pos + 1);
            data++;
        }
		users.push_back(user_data);
    }
    upload_users.close();
}


void upload_admins() {
    ifstream upload_admins;
    upload_admins.open("database\\admins.txt");

    if (!upload_admins.is_open()) return;
    string line;
    int pos = 0, data = 0;
    string mycut;
    while (getline(upload_admins, line)) {
        pos = 0, data = 0;
		admin admin_data;
        while (pos != -1) {
            pos = line.find(';');
            mycut = line.substr(0, pos);
            if (data == 0) {
                admin_data.ad_name = mycut;
            }
            else if (data == 1) {
                admin_data.ad_user_name = mycut;
            }
            else if (data == 2) {
                admin_data.ad_hashed_password = mycut;
            }
            else if (data == 3) {
                admin_data.ad_magic = stoi(mycut);
            }
            else if (data == 4) {
                admin_data.ad_phone = mycut;
            }
            line = line.substr(pos + 1);
            data++;
        }
        admins.push_back(admin_data);
    }
    upload_admins.close();
}


//upload planes
void upload_planes() {
    ifstream upload_planes;
    upload_planes.open("database\\planes.txt");

    if (!upload_planes.is_open()) return;
    string line;
    int pos = 0, data = 0;
    string mycut;
    while (getline(upload_planes, line)) {
        pos = 0, data = 0;
        plane_data plane_data;
        while (pos != -1) {
            pos = line.find(';');
            mycut = line.substr(0, pos);
            if (data == 0) {
                plane_data.code = mycut;
            }
            else if (data == 1) {
                plane_data.model = mycut;
            }
            else if (data == 2) {
                plane_data.rows = stoi(mycut);
            }
            else if (data == 3) {
                plane_data.nom_of_seats = stoi(mycut);
            }
            else if (data == 4) {
                plane_data.place = mycut;
            }
            line = line.substr(pos + 1);
            data++;
        }
        planes.push_back(plane_data);
    }
    upload_planes.close();
}


void upload_airports() {
    ifstream upload_airports;
    upload_airports.open("database\\airports.txt");

    if (!upload_airports.is_open()) return;
    string line;
    int pos = 0, data = 0;
    string mycut;
    while (getline(upload_airports, line)) {
        pos = 0, data = 0;
        airport_data airport_data;
        while (pos != -1) {
            pos = line.find(';');
            mycut = line.substr(0, pos);
            if (data == 0) {
                airport_data.city = mycut;
            }
            else if (data == 1) {
                airport_data.name = mycut;
            }
            else if (data == 2) {
                airport_data.iata_code = mycut;
            }
            line = line.substr(pos + 1);
            data++;
        }
        cout << mycut << endl;
        airports.push_back(airport_data);
    }
    upload_airports.close();
}


void upload_flights() {
    ifstream upload_flights;
    upload_flights.open("database\\flights.txt");
    string line;
    if (!upload_flights.is_open()) return;

    while (getline(upload_flights, line)) {

        stringstream ss(line);
        string temp;
        flight_struct flight_data;

        
        getline(ss, flight_data.number_flight, ';');
        getline(ss, flight_data.plane_code, ';');
        getline(ss, flight_data.plane_model, ';');
        getline(ss, flight_data.departure_airport, ';');
        getline(ss, flight_data.d_iata, ';');
        getline(ss, flight_data.arrival_airport, ';');
        getline(ss, flight_data.a_iata, ';');

        getline(ss, temp, ';'); flight_data.price.economy_price = stoi(temp);
        getline(ss, temp, ';'); flight_data.price.premium_economy_price = stoi(temp);
        getline(ss, temp, ';'); flight_data.price.business_price = stoi(temp);
        getline(ss, temp, ';'); flight_data.price.first_class_price = stoi(temp);

        getline(ss, flight_data.departure_date, ';');
        getline(ss, flight_data.time_departure, ';');
        getline(ss, flight_data.arrival_date, ';');
        getline(ss, flight_data.time_arrival, ';');
		getline(ss, temp, ';'); flight_data.flight_duration = stoi(temp);
        getline(ss, flight_data.state, ';');

        getline(ss, temp, ';'); flight_data.total_seats = stoi(temp);


        for (int i = 0; i < flight_data.total_seats; i++) {
            flight_struct::seat_struct s;
            getline(ss, s.seat_number, ';');
            getline(ss, temp, ';'); s.is_booked = (temp == "1");
            getline(ss, s.seat_category, ';');
            flight_data.seats.push_back(s);
        }


        getline(ss, temp, ';'); flight_data.seats_in_economy = stoi(temp);
        getline(ss, temp, ';'); flight_data.seats_in_premium_economy = stoi(temp);
        getline(ss, temp, ';'); flight_data.seats_in_business = stoi(temp);
        getline(ss, temp, ';'); flight_data.seats_in_first_class = stoi(temp);

        flights.push_back(flight_data);
    }
    upload_flights.close();
}


void upload_favorite_flights() {
    ifstream upload_favorite_flights;
    upload_favorite_flights.open("database\\favorite_flights.txt");
    string line;
    if (!upload_favorite_flights.is_open()) return;
    while (getline(upload_favorite_flights, line)) {
        stringstream ss(line);
        string temp;
        FavoriteFlight fav_data;
        getline(ss, fav_data.username, ';');
        getline(ss, fav_data.flightNumber, ';');
		getline(ss, temp, ';'); fav_data.idx = stoi(temp);
        favoriteFlights.push_back(fav_data);
    }
    upload_favorite_flights.close();
}

void upload_tickets() {
    ifstream upload_tickets;
    upload_tickets.open("database\\books.txt");
    string line;
    if (!upload_tickets.is_open()) return;

    while (getline(upload_tickets, line)) {

        stringstream ss(line);
        string temp;
        Booking ticket_data;


        getline(ss, ticket_data.user_name, ';');
        getline(ss, temp, ';'); ticket_data.flight_index = stoi(temp);
        getline(ss, ticket_data.category, ';');
        getline(ss, temp, ';'); ticket_data.num_of_travelers = stoi(temp);


        for (int i = 0; i < ticket_data.num_of_travelers; i++) {
            Booking::traveler_data s;
            getline(ss, s.first_name, ';');
            getline(ss, s.middle_name, ';');
            getline(ss, s.last_name, ';');
            getline(ss, s.date_of_birth, ';');
            getline(ss, s.meal_preference, ';');
            getline(ss, temp, ';'); s.price = stoi(temp);
            getline(ss, temp, ';'); s.male = (temp == "1");
            getline(ss, s.passport_number, ';');
            getline(ss, s.number_seats, ';');

            ticket_data.travelers.push_back(s);
        }

        tickets.push_back(ticket_data);
    }
    upload_tickets.close();
}

void upload_messages() {
    ifstream upload_messages;
    upload_messages.open("database\\messages.txt");
    string line;
    if (!upload_messages.is_open()) return;
    while (getline(upload_messages, line)) {
        stringstream ss(line);
        string temp;
        messageStruct message;
        getline(ss, message.user_name, ';');
        getline(ss, message.message, ';');
        getline(ss, temp, ';'); message.replied = stoi(temp);
        getline(ss, temp, ';'); message.if_admin = stoi(temp);
        messages_array.push_back(message);
    }
    upload_messages.close();
}