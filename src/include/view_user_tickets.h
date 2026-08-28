#pragma once
#include <string>
#include "Booking_struct.h"
#include "DataStructures/skyport_array.h"
using namespace std;



extern skyPort_array<int> user_tickets;

void getUserTickets(string currentUser);