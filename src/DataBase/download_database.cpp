#include<string>
#include<fstream>
#include"include/sign_up_users.h"
#include"include/add_admin.h"
#include"include/add_plane.h"
#include"include/add_flights.h"
#include"include/fav_flights.h"
#include"include/chatBot.h"
#include"include/database.h"
#include"include/Booking_struct.h"
using namespace std;

void download_database() {
    download_users();
    download_admins();
	download_planes();
    download_flights();
	download_favorite_flights();
    download_tickets();
    download_messages();
}

void download_users() {
    ofstream download_users;
    download_users.open("database\\users.txt", ios::out | ios::trunc);
    for (int i = 0; i < users.size(); i++) {
        download_users << users[i].name << ';' << users[i].user_name << ';' << users[i].hashed_password << ';' << users[i].magic << ';' << users[i].phone << endl;
    }
    download_users.close();
}


void download_admins() {
    ofstream download_admins;
    download_admins.open("database\\admins.txt", ios::out | ios::trunc);
    for (int i = 0; i < admins.size(); i++) {
        download_admins << admins[i].ad_name << ';' << admins[i].ad_user_name << ';' << admins[i].ad_hashed_password << ';' << admins[i].ad_magic << ';' << admins[i].ad_phone << endl;
    }
    download_admins.close();
}


void download_planes() {
    ofstream download_planes;
    download_planes.open("database\\planes.txt", ios::out | ios::trunc);
    for (int i = 0; i < planes.size(); i++) {
        download_planes << planes[i].code << ';' << planes[i].model << ';' << planes[i].rows << ';' << planes[i].nom_of_seats << ';' << planes[i].place << endl;
        
    }
	download_planes.close();
}


void download_flights() {
    ofstream download_flights;
    download_flights.open("database\\flights.txt", ios::out | ios::trunc);
    for (int i = 0; i < flights.size(); i++) {
        download_flights << flights[i].number_flight << ';' << flights[i].plane_code << ';' << flights[i].plane_model << ';'

            << flights[i].departure_airport << ';' << flights[i].d_iata << ';' << flights[i].arrival_airport << ';' << flights[i].a_iata << ';'

            << flights[i].price.economy_price << ';' << flights[i].price.premium_economy_price << ';' << flights[i].price.business_price << ';' << flights[i].price.first_class_price << ';'

            << flights[i].departure_date << ';' << flights[i].time_departure << ';' << flights[i].arrival_date << ';' << flights[i].time_arrival << ';' << flights[i].flight_duration << ';' << flights[i].state << ';' << flights[i].total_seats << ';';
            
            for (int j = 0; j < flights[i].seats.size(); j++) {
                download_flights << flights[i].seats[j].seat_number << ';' << (flights[i].seats[j].is_booked ? 1 : 0) << ';' << flights[i].seats[j].seat_category << ';';
			}

            download_flights << flights[i].seats_in_economy << ';' << flights[i].seats_in_premium_economy << ';' << flights[i].seats_in_business << ';' << flights[i].seats_in_first_class << endl;
    }
    download_flights.close();
}

void download_favorite_flights() {
    ofstream download_favorite_flights;
    download_favorite_flights.open("database\\favorite_flights.txt", ios::out | ios::trunc);
    for (int i = 0; i < favoriteFlights.size(); i++) {
        download_favorite_flights << favoriteFlights[i].username << ';' << favoriteFlights[i].flightNumber << ';' << favoriteFlights[i].idx << endl;
    }
    download_favorite_flights.close();
}


void download_tickets() {
    ofstream download_tickets;
    download_tickets.open("database\\books.txt", ios::out | ios::trunc);
    for (int i = 0; i < tickets.size(); i++) {
        download_tickets << tickets[i].user_name << ';' << tickets[i].flight_index << ';' << tickets[i].category << ';' << tickets[i].num_of_travelers << ';';
        for (int j = 0; j < tickets[i].travelers.size(); j++) {
            download_tickets << tickets[i].travelers[j].first_name << ';' << tickets[i].travelers[j].middle_name << ';' << tickets[i].travelers[j].last_name << ';' << tickets[i].travelers[j].date_of_birth << ';' << tickets[i].travelers[j].meal_preference << ';' << tickets[i].travelers[j].price << ';' << (tickets[i].travelers[j].male ? 1 : 0) << ';' << tickets[i].travelers[j].passport_number << ';' << tickets[i].travelers[j].number_seats << ';';
        }
        download_tickets << endl;
    }
    download_tickets.close();
}

void download_messages() {
    ofstream download_messages;
    download_messages.open("database\\messages.txt", ios::out | ios::trunc);

    for (int i = 0; i < messages_array.size(); i++) {
        download_messages << messages_array[i].user_name << ';' << messages_array[i].message << ';' << (messages_array[i].replied ? 1 : 0) << ';' << (messages_array[i].if_admin ? 1 : 0) << endl;
    }
    download_messages.close();
}