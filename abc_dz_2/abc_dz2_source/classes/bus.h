//
// Created by Дмитрий Татьянченко on 18.10.2021.
//

#ifndef ABC_DZ2_BUS_H
#define ABC_DZ2_BUS_H

#import "vehicle.h"

class Bus : public Vehicle {
public:
    // Default constructor.
    Bus() = default;

    // Parametric constructor.
    Bus(int fuel_tank_capacity, double fuel_consumption, short passenger_capacity);

    // Get string representation of a truck.
    std::string toString();

private:
    short passenger_capacity_;
};


#endif //ABC_DZ2_BUS_H
