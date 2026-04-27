#ifndef DELIVERY_H
#define DELIVERY_H

class Delivery {
public:
    int location;
    int priority;
    float deadline;

    Delivery(int loc, int p, float d);
};

#endif