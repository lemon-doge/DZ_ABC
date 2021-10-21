//
// Created by Дмитрий Татьянченко on 18.10.2021.
//

#include "bus.h"

Bus::Bus(int fuel_tank_capacity, double fuel_consumption, short passenger_capacity) :
        Vehicle(fuel_tank_capacity, fuel_consumption) {

    this->type_ = (Vehicle::BUS);

    if (passenger_capacity < 0) {
        throw std::invalid_argument("speed limit < 0");
    }

    this->passenger_capacity_ = passenger_capacity;
}

std::string Bus::toString() {
    return "Bus: " + this->Vehicle::toString() +
           " passenger capacity: " + std::to_string(this->passenger_capacity_);
}
