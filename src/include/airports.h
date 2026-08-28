#pragma once
#include <string>
#include "DataStructures/skyport_array.h"
using namespace std;
struct airport_data {
	string city;
	string name;
	string iata_code;
};
extern skyPort_array<airport_data> airports;
