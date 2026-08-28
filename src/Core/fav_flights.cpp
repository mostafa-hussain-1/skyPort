#include <string>
#include "DataStructures/skyport_array.h"
#include "include/add_flights.h"
#include <algorithm>
using namespace std;

struct FavoriteFlight
{
    string username;
    string flightNumber;
    int idx;
};

skyPort_array<FavoriteFlight> favoriteFlights;
skyPort_array<int> user_favourite;


void saveToFavorite(string currentUser, int index)
{
    FavoriteFlight fav;
    fav.username = currentUser;

    fav.flightNumber = flights[index].number_flight;
    fav.idx = index;
    
    favoriteFlights.push_back(fav);
}

void deleteFromFavorite(string currentUser, int index)
{
    string flightNumber = flights[index].number_flight;
    

    for (int i = 0; i < favoriteFlights.size(); i++)
    {
        if (favoriteFlights[i].username == currentUser &&
            favoriteFlights[i].flightNumber == flightNumber)
        {
            favoriteFlights.erase(i);
            return;
        }
    }
}

void getUserFavorites(string currentUser)
{
    user_favourite.clear();
    for (int i = 0; i < favoriteFlights.size(); i++)
    {
        if (favoriteFlights[i].username == currentUser)
        {
            user_favourite.push_back(favoriteFlights[i].idx);
        }
    }
    sort(user_favourite.begin(), user_favourite.end());
}