#include<iostream>
#include <string>
#include<ctime>
#include"skyPort_array.h"
#include "add_flights.h"
#include<ctime>

string current_sort_criteria = "none";

int partition_price(skyPort_array<pair<int, flight_struct>>& a, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);

    swap(a[randomIndex], a[high]);
    int pivot = a[high].second.price.economy_price;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j].second.price.economy_price < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort_price(skyPort_array<pair<int, flight_struct>>& b, int low, int high) {
    if (low < high) {
        int pi = partition_price(b, low, high);

        quickSort_price(b, low, pi - 1); // الشمال
        quickSort_price(b, pi + 1, high); // اليمين
    }
}
int partition_flight_duration(skyPort_array<pair<int, flight_struct>>& a, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);

    swap(a[randomIndex], a[high]);
    int pivot = a[high].second.flight_duration;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j].second.flight_duration < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort_flight_duration(skyPort_array<pair<int, flight_struct>>& b, int low, int high) {
    if (low < high) {
        int pi = partition_flight_duration(b, low, high);

        quickSort_flight_duration(b, low, pi - 1); // الشمال
        quickSort_flight_duration(b, pi + 1, high); // اليمين
    }
}

void sort_flights(skyPort_array<pair<int, flight_struct>>& c, string type_sort) {
    srand(time(0));
    if (type_sort == "price") {
        // sort by price
        quickSort_price(c, 0, c.size() - 1);
    }
    else if (type_sort == "flight_duration") {
        // sort by flight_duration
        quickSort_flight_duration(c, 0, c.size() - 1);
    }

}