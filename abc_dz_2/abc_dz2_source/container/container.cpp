//
// Created by Дмитрий Татьянченко on 12.10.2021.
//
#include <algorithm>
#include <vector>
#include "container.h"
#include "../classes/truck.h"
#include "../classes/car.h"
#include "../classes/bus.h"

void Container::append(Vehicle vehicle) {
    this->container_.push_back(vehicle);
}

double Container::averageRange() {
    double average = 0;
    for (Vehicle &item: this->container_) {
        average += item.Range();
    }
    // Processing empty container.
    return this->container_.empty() ? 0 : average / this->container_.size();
}

void Container::filter() {
    double average = this->averageRange();
    this->container_.erase(std::remove_if(this->container_.begin(), this->container_.end(),
                                    [average](Vehicle v) { return v.Range() < average; }), this->container_.end());
}


std::string Container::toString() {
    std::string result = "Contents: \n";
    for (auto item: container_) {
        switch (item.type()) {
            case Vehicle::TRUCK:
                result += ((Truck *) (&item))->toString() + '\n';
                break;
            case Vehicle::BUS:
                result += ((Bus *) (&item))->toString() + '\n';
                break;
            case Vehicle::CAR:
                result += ((Car *) (&item))->toString() + '\n';
                break;
            default:
                result += item.toString() + '\n';
                break;
        }
    }
    return result;
}

void Container::clear() {
    container_.clear();
}

size_t Container::size() {
    return container_.size();
}
