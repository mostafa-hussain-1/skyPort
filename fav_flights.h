#pragma once
#include <string>
#include "skyport_array.h"
#include "add_flights.h"

struct FavoriteFlight
{
    string username;
    string flightNumber;
    int idx;
};

extern skyPort_array<FavoriteFlight> favoriteFlights;
extern skyPort_array<int> user_favourite;

void saveToFavorite(string currentUser, int index);
void deleteFromFavorite(string currentUser, int index);
void getUserFavorites(string currentUser);
