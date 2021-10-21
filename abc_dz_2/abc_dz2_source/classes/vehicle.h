//
// Created by Дмитрий Татьянченко on 12.10.2021.
//

#ifndef ABC_DZ2_VEHICLE_H
#define ABC_DZ2_VEHICLE_H

#include <stdexcept>
#include <string>

class Vehicle{
public:
    // Types of trucks.
    enum type {CAR = 0 , BUS = 1, TRUCK = 2};

    // Default constructor.
    Vehicle() = default;

    // Parametric constructor.
    Vehicle(int fuel_tank_capacity, double fuel_consumption);

    // Range computation.
    double Range() const;

    // Get string representation of generalized vehicle.
    std::string toString() const;

    int type() const;
private:
    int fuel_tank_capacity_;
    double fuel_consumption_;

protected:
    int type_ = -1;
};

#endif //ABC_DZ2_VEHICLE_H
