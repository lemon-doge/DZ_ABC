//
// Created by Дмитрий Татьянченко on 18.10.2021.
//

#ifndef ABC_DZ2_CAR_H
#define ABC_DZ2_CAR_H

#import "vehicle.h"

class Car : public Vehicle {
public:
    // Default constructor.
    Car() = default;

    // Parametric constructor.
    Car(int fuel_tank_capacity, double fuel_consumption, short speed_limit);

    // Get string representation of a truck.
    std::string toString();

private:
    int speed_limit_;
};

#endif //ABC_DZ2_CAR_H
