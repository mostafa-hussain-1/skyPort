#pragma once
#include <string>
#include "DataStructures/skyport_array.h"
using namespace System;
using namespace std;

void search_by_code(string query);
void searchByModel(string query);
extern skyPort_array<int> plane_search_result;
