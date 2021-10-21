//
// Created by Дмитрий Татьянченко on 18.10.2021.
//

#include "truck.h"

Truck::Truck(int fuel_tank_capacity, double fuel_consumption, int carrying_capacity) :
        Vehicle(fuel_tank_capacity, fuel_consumption) {

    this->type_ = (Vehicle::TRUCK);

    if (carrying_capacity < 0) {
        throw std::invalid_argument("carrying capacity < 0");
    }

    this->carrying_capacity_ = carrying_capacity;
}

std::string Truck::toString() {
    return "Truck: " + this->Vehicle::toString() +
           " carrying capacity: " + std::to_string(this->carrying_capacity_);
}


