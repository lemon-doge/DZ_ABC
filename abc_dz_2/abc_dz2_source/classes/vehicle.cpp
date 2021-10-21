//
// Created by Дмитрий Татьянченко on 12.10.2021.
//
#pragma once

#include "vehicle.h"

Vehicle::Vehicle(int fuel_tank_capacity, double fuel_consumption) {
    if(fuel_consumption <= 0){
        throw std::invalid_argument("fuel consumption <= 0");
    }

    if(fuel_tank_capacity < 0){
        throw std::invalid_argument("fuel tank capacity < 0");
    }

    this->fuel_tank_capacity_ = fuel_tank_capacity;
    this->fuel_consumption_ = fuel_consumption;
}

double Vehicle::Range() const{
    return this->fuel_tank_capacity_ / this->fuel_consumption_;
}

std::string Vehicle::toString() const{
    return " fuel tank capacity (gallons): " + std::to_string(this->fuel_tank_capacity_) +
            " fuel consumption (gallons per mile): " +std::to_string(this->fuel_consumption_);
}

int Vehicle::type() const{
    return this->type_;
}
