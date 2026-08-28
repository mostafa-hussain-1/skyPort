#pragma once
#include <iostream>
#include "DataStructures/skyport_array.h"
#include <string>
#include "add_flights.h"


int partition_price(skyPort_array<pair<int, flight_struct>>& a, int low, int high);
void quickSort_price(skyPort_array<pair<int, flight_struct>>& b, int low, int high);
int partition_flight_duration(skyPort_array<pair<int, flight_struct>>& a, int low, int high);
void quickSort_flight_duration(skyPort_array<pair<int, flight_struct>>& b, int low, int high);
void sort_flights(skyPort_array<pair<int, flight_struct>>& c, string type_sort);