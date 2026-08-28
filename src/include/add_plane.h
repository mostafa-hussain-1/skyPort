#pragma once
#include <string>
#include "DataStructures/skyport_array.h"
using namespace std;

struct plane_data {
    string code;
    string model;
    int rows;
    int nom_of_seats;
	string place;
};

extern skyPort_array<plane_data> planes;
void add_planes(string code, string model, int rows, int nom_of_seats, string place);