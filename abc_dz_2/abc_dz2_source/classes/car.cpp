//
// Created by Дмитрий Татьянченко on 18.10.2021.
//

#include "car.h"

Car::Car(int fuel_tank_capacity, double fuel_consumption, short speed_limit) :
        Vehicle(fuel_tank_capacity, fuel_consumption) {

    this->type_ = (Vehicle::CAR);

    if (speed_limit < 0) {
        throw std::invalid_argument("speed limit < 0");
    }

    this->speed_limit_ = speed_limit;
}

std::string Car::toString() {
    return "Car: " + this->Vehicle::toString() +
           " speed limit: " + std::to_string(this->speed_limit_);
}
