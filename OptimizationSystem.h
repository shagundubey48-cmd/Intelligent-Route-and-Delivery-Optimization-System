#ifndef OPTIMIZATION_SYSTEM_H
#define OPTIMIZATION_SYSTEM_H

#include "Graph.h"
#include "Delivery.h"
#include "Vehicle.h"
#include <unordered_map>

class OptimizationSystem {
public:
    Graph graph;
    vector<Delivery> deliveries;
    vector<Vehicle> vehicles;
    unordered_map<string, int> cityMap;

    void addCity(string name, float x, float y);
    void connectAll();

    void addDelivery(string city, int priority, float deadline);
    void addVehicle(float capacity);

    void optimizeDeliveries();
    void assignVehicles();

    void tsp(int start);
    void compare(string src, string dest);
};

#endif