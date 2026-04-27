#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cmath>
using namespace std;

class City {
public:
    int id;
    string name;
    float x, y;

    City(int id, string name, float x, float y);
};

class Road {
public:
    int dest;
    float distance;

    Road(int d, float dist);
};

class Graph {
public:
    vector<City> cities;
    unordered_map<int, vector<Road>> adjList;

    void addCity(string name, float x, float y);
    void autoConnect(int a, int b);

    float dijkstra(int src, int dest);
    float bruteForce(int src, int dest, vector<bool>& visited);

    void printGraph();
};

#endif