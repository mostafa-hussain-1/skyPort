#include <string>
#include "Booking.h"
#include "skyPort_array.h"
#include "view_user_tickets.h"
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