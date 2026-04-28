#include "OptimizationSystem.h"
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int main() {
    OptimizationSystem sys;
    int choice;

    do {
        setColor(11);
cout << "\n========================================\n";
cout << " ROUTE & DELIVERY OPTIMIZATION SYSTEM\n";
cout << "========================================\n";

setColor(14);
cout << "\n1. Add City\n2. Connect Cities\n3. Add Delivery\n";
cout << "4. Add Vehicle\n5. Optimize Deliveries\n";
cout << "6. Assign Vehicles\n7. TSP\n8. Compare\n";
cout << "9. Show Graph\n10. Search City\n";
cout << "11. Save Cities\n12. Load Cities\n0. Exit\n";

setColor(7);
cout << "\nEnter choice: ";
cin >> choice;
        if (choice == 1) {
            string name; float x,y;
            cout << "\nEnter City Name: ";
            cin >> name;
            cout << "Enter X Coordinate: ";
            cin >> x;
            cout << "Enter Y Coordinate: ";
            cin >> y;
            sys.addCity(name,x,y);
        }
        else if (choice == 2) sys.connectAll();
        else if (choice == 3) {
            string city; int p; float d;
            cout << "\nEnter City Name: ";
            cin >> city;
            cout << "Enter Priority: ";
            cin >> p;
            cout << "Enter Deadline: ";
            cin >> d;
            sys.addDelivery(city,p,d);
        }
        else if (choice == 4) {
            float cap;
            cout << "\nEnter Vehicle Capacity: ";
            cin >> cap;
            sys.addVehicle(cap);
        }
        else if (choice == 5) sys.optimizeDeliveries();
        else if (choice == 6) sys.assignVehicles();
        else if (choice == 7) {
            int start;
            cout << "\nEnter Starting City ID: ";
            cin >> start;
            sys.tsp(start);
        }
        else if (choice == 8) {
            string s,d; 
            cout << "\nEnter Source City: ";
            cin >> s;
            cout << "Enter Destination City: ";
            cin >> d;

            sys.compare(s,d);
        }
        else if (choice == 9) {
            sys.graph.printGraph();
        }
        else if(choice == 10) {
    string name;
    cout << "Enter city name: ";
    cin >> name;
    sys.searchCity(name);
}
else if(choice == 11) sys.saveCities();
else if(choice == 12) sys.loadCities();
        

    } while(choice != 0);

    return 0;
}