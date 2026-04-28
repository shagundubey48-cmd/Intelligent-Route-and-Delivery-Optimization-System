#include <iostream>

#include "OptimizationSystem.h"
#include <algorithm>
#include <iomanip>
#include <ctime>
using namespace std;

void line() {
    cout << "\n----------------------------------------\n";
}
void OptimizationSystem::addCity(string name, float x, float y) {
    if(cityMap.count(name)) {
        cout << "City already exists!\n";
        return;
    }

    graph.addCity(name, x, y);
    cityMap[name] = graph.cities.size() - 1;

    cout << "City added successfully!\n";
}
void OptimizationSystem::connectAll() {
    int n = graph.cities.size();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            graph.autoConnect(i, j);
}

void OptimizationSystem::addDelivery(string city, int priority, float deadline) {
    if(cityMap.find(city) == cityMap.end()) {
        cout << "City not found!\n";
        return;
    }

    deliveries.push_back(Delivery(cityMap[city], priority, deadline));
    cout << "Delivery added!\n";
}

void OptimizationSystem::searchCity(string name) {
    if(cityMap.count(name))
        cout << "City found! ID: " << cityMap[name] << endl;
    else
        cout << "City not found!\n";
}
void OptimizationSystem::addVehicle(float capacity) {
    vehicles.push_back(Vehicle(vehicles.size(), capacity));
}

void OptimizationSystem::optimizeDeliveries() {
    sort(deliveries.begin(), deliveries.end(), [](Delivery a, Delivery b) {
        if (a.priority == b.priority)
            return a.deadline < b.deadline;
        return a.priority > b.priority;
    });

    line();
cout << "Optimized Deliveries:\n";
line();

for (auto &d : deliveries) {
    cout << graph.cities[d.location].name
         << " | Priority: " << d.priority
         << " | Deadline: " << d.deadline << endl;
}
}

void OptimizationSystem::assignVehicles() {
    for (auto &d : deliveries) {
        int best = 0;
        for (int i = 1; i < vehicles.size(); i++) {
            if (vehicles[i].assigned.size() <
                vehicles[best].assigned.size())
                best = i;
        }
        vehicles[best].assigned.push_back(d);
    }
}

void OptimizationSystem::tsp(int start) {
    vector<bool> visited(graph.cities.size(), false);
    int current = start;
    float total = 0;

    visited[current] = true;

    cout << "\nTSP: " << graph.cities[current].name;

    for (int i = 1; i < graph.cities.size(); i++) {
        float minDist = 1e9;
        int next = -1;

        for (auto &edge : graph.adjList[current]) {
            if (!visited[edge.dest] && edge.distance < minDist) {
                minDist = edge.distance;
                next = edge.dest;
            }
        }

        if (next == -1) break;

        visited[next] = true;
        total += minDist;
        current = next;

        cout << " -> " << graph.cities[current].name;
    }

    cout << "\nTotal: " << total << endl;
}
#include <fstream>

void OptimizationSystem::saveCities() {
    ofstream file("cities.txt");

    for(auto &c : graph.cities) {
        file << c.name << " " << c.x << " " << c.y << endl;
    }

    cout << "Cities saved to file!\n";
}

void OptimizationSystem::loadCities() {
    ifstream file("cities.txt");

    string name;
    float x, y;

    while(file >> name >> x >> y) {
        addCity(name, x, y);
    }

    cout << "Cities loaded from file!\n";
}

void OptimizationSystem::compare(string src, string dest) {
    int s = cityMap[src], d = cityMap[dest];

    clock_t start, end;

    start = clock();
    float d1 = graph.dijkstra(s, d);
    end = clock();
    double t1 = double(end - start) / CLOCKS_PER_SEC;

    vector<bool> visited(graph.cities.size(), false);

    start = clock();
    float d2 = graph.bruteForce(s, d, visited);
    end = clock();
    double t2 = double(end - start) / CLOCKS_PER_SEC;

    cout << "\nComparison:\n";
    cout << "Dijkstra: " << d1 << " Time: " << t1 << endl;
    cout << "Brute: " << d2 << " Time: " << t2 << endl;
}