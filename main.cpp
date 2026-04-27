#include "OptimizationSystem.h"

void header() {
    cout << "\n=============================================\n";
    cout << " ROUTE & DELIVERY OPTIMIZATION SYSTEM\n";
    cout << "=============================================\n";
}

int main() {
    OptimizationSystem sys;
    int choice;

    do {
        header();

        cout << "\n1. Add City\n2. Connect Cities\n3. Add Delivery\n";
        cout << "4. Add Vehicle\n5. Optimize Deliveries\n";
        cout << "6. Assign Vehicles\n7. TSP\n8. Compare\n9. Show Graph\n0. Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name; float x,y;
            cin >> name >> x >> y;
            sys.addCity(name,x,y);
        }
        else if (choice == 2) sys.connectAll();
        else if (choice == 3) {
            string city; int p; float d;
            cin >> city >> p >> d;
            sys.addDelivery(city,p,d);
        }
        else if (choice == 4) {
            float cap; cin >> cap;
            sys.addVehicle(cap);
        }
        else if (choice == 5) sys.optimizeDeliveries();
        else if (choice == 6) sys.assignVehicles();
        else if (choice == 7) {
            int start; cin >> start;
            sys.tsp(start);
        }
        else if (choice == 8) {
            string s,d; cin >> s >> d;
            sys.compare(s,d);
        }
        else if (choice == 9) {
            sys.graph.printGraph();
        }

    } while(choice != 0);

    return 0;
}