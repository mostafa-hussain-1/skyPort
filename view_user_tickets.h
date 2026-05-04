#pragma once
#include <string>
#include "Booking.h"
#include "skyPort_array.h"
using namespace std;

struct UserTicketView
{
    Booking ticketData;
    int originalIndex;
};


extern skyPort_array<int> user_tickets;

void getUserTickets(string currentUser);
