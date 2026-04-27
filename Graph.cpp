#include "Graph.h"
#include <algorithm>

City::City(int id, string name, float x, float y) {
    this->id = id;
    this->name = name;
    this->x = x;
    this->y = y;
}

Road::Road(int d, float dist) {
    dest = d;
    distance = dist;
}

void Graph::addCity(string name, float x, float y) {
    int id = cities.size();
    cities.push_back(City(id, name, x, y));
}

float distanceCalc(City a, City b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

void Graph::autoConnect(int a, int b) {
    float dist = distanceCalc(cities[a], cities[b]);
    adjList[a].push_back(Road(b, dist));
    adjList[b].push_back(Road(a, dist));
}

// Dijkstra: O(E log V)
float Graph::dijkstra(int src, int dest) {
    int n = cities.size();
    vector<float> dist(n, 1e9);
    vector<int> parent(n, -1);

    priority_queue<pair<float,int>, vector<pair<float,int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        for (auto &edge : adjList[u]) {
            int v = edge.dest;
            float w = edge.distance;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // Print path
    vector<int> path;
    for (int v = dest; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    cout << "\nPath: ";
    for (int i : path)
        cout << cities[i].name << " -> ";
    cout << "END\n";

    return dist[dest];
}

// Brute Force: O(V!)
float Graph::bruteForce(int src, int dest, vector<bool>& visited) {
    if (src == dest) return 0;

    visited[src] = true;
    float ans = 1e9;

    for (auto &edge : adjList[src]) {
        if (!visited[edge.dest]) {
            ans = min(ans, edge.distance +
                bruteForce(edge.dest, dest, visited));
        }
    }

    visited[src] = false;
    return ans;
}

void Graph::printGraph() {
    cout << "\nGraph:\n";
    for (auto &p : adjList) {
        cout << cities[p.first].name << " -> ";
        for (auto &edge : p.second) {
            cout << cities[edge.dest].name << "(" << edge.distance << ") ";
        }
        cout << endl;
    }
}