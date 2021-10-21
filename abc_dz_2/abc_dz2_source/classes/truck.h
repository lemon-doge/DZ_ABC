//
// Created by Дмитрий Татьянченко on 18.10.2021.
//

#ifndef ABC_DZ2_TRUCK_H
#define ABC_DZ2_TRUCK_H

#import "vehicle.h"

class Truck : public Vehicle {
public:
    // Default constructor.
    Truck() = default;

    // Parametric constructor.
    Truck(int fuel_tank_capacity, double fuel_consumption, int carrying_capacity);

    // Get string representation of a truck.
    std::string toString();

private:
    int carrying_capacity_;
};

#endif //ABC_DZ2_TRUCK_H
