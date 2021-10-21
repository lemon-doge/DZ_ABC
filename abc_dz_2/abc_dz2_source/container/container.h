//
// Created by Дмитрий Татьянченко on 12.10.2021.
//

#ifndef ABC_DZ2_CONTAINER_H
#define ABC_DZ2_CONTAINER_H

#include <vector>
#include "../classes/vehicle.h"

class Container{
public:
    // Default constructor.
    Container() = default;

    // Append vehicle to the container.
    void append(Vehicle vehicle);

    // Get string representation of the container.
    std::string toString();

    // Get average range of the vehicle in the container.
    double averageRange();

    // Filter container.
    void filter();

    size_t size();

    void clear();
private:
    std::vector<Vehicle> container_ = {};
};

#endif //ABC_DZ2_CONTAINER_H
