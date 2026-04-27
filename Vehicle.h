#ifndef VEHICLE_H
#define VEHICLE_H

#include <vector>
#include "Delivery.h"
using namespace std;

class Vehicle {
public:
    int id;
    float capacity;
    vector<Delivery> assigned;

    Vehicle(int id, float cap);
};

#endif