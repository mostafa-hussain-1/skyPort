#include <string>
#include "include/add_plane.h"
#include "UI/admin_home_page.h"
using namespace std;

bool plane_update = false;
int plane_idx;


skyPort_array<plane_data> planes;

void add_planes(string code, string model, int rows, int nom_of_seats, string place) {
	
	plane_data p;

	p.code = code;
	p.model = model;
	p.rows = rows;
	p.nom_of_seats = nom_of_seats;
	p.place = place;

	if (plane_update) {
		planes[plane_idx] = p;
	}
	else {
		planes.push_back(p);
	}
}