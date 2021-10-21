//
// Created by Дмитрий Татьянченко on 08.10.2021.
//
#include <iostream>
#include "vehicle.h"

// Ввод параметров обобщенной машины из файла
bool In(vehicle &v, std::ifstream &in_file_stream) {
    int k;
    in_file_stream >> k;

    in_file_stream >> v.fuel_tank_capacity >> v.fuel_consumption; // validation ?? consumption != 0

    std::cout << "vehicle input type: " + std::to_string(k) + " ftc: " + std::to_string(v.fuel_tank_capacity) + " fc: " +
            std::to_string(v.fuel_consumption);

    switch (k) {
        case vehicle::TRUCK:
            v.k = vehicle::TRUCK;
            In(v.t, in_file_stream);
            return true;
        case vehicle::BUS:
            v.k = vehicle::BUS;
            In(v.b, in_file_stream);
            return true;
        case vehicle::CAR:
            v.k = vehicle::CAR;
            In(v.c, in_file_stream);
            return true;
        default:
            return false;
    }
}

// Случайный ввод обобщенной машины
bool InRnd(vehicle &v) {
    auto k = rand() % 3 + 1;

    // нормировка ни к чему не обязывает
    v.fuel_tank_capacity = rand() % 10000 + 1;
    v.fuel_consumption = rand() % 1000 + 1;

    switch (k) {
        case vehicle::TRUCK:
            v.k = vehicle::TRUCK;
            InRnd(v.t);
            return true;
        case vehicle::BUS:
            v.k = vehicle::BUS;
            InRnd(v.b);
            return true;
        case vehicle::CAR:
            v.k = vehicle::CAR;
            InRnd(v.c);
            return true;
        default:
            return false;
    }
}

// Вывод параметров текущей машины в поток
void Out(vehicle &v, std::ofstream &out_file_stream) {

    std::string type;
    switch (v.k) {
        case vehicle::TRUCK:
            type = "TRUCK";
            break;
        case vehicle::BUS:
            type = "BUS";
            break;
        case vehicle::CAR:
            type = "CAR";
            break;    // exception ??
    }

    out_file_stream << type << " fuel tank capacity (gallons): " << v.fuel_tank_capacity
                            << " fuel consumption (gallons per mile): " << v.fuel_consumption;


    switch (v.k) {
        case vehicle::TRUCK:
            Out(v.t, out_file_stream);
            break;
        case vehicle::BUS:
            Out(v.b, out_file_stream);
            break;
        case vehicle::CAR:
            Out(v.c, out_file_stream);
            break;
        default:
            out_file_stream << "Incorrect vehicle!" << std::endl;
    }

    out_file_stream << " range (miles): " << Range(v);
}

// Вычисление дальности хода
double Range(vehicle &v) {
    return v.fuel_tank_capacity / v.fuel_consumption;
}
