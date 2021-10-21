//
// Created by Дмитрий Татьянченко on 08.10.2021.
//

#ifndef ABC_DZ1_VEHICLE_H
#define ABC_DZ1_VEHICLE_H

#include <fstream>

#include "truck.h"
#include "car.h"
#include "bus.h"


struct vehicle {
    // значения ключей для каждого типа машин
    enum key {CAR, BUS, TRUCK};
    key k;

    int fuel_tank_capacity;
    double fuel_consumption;

    // используемые альтернативы
    union {
        bus b;
        car c;
        truck t;
    };
};

// Ввод обобщенной машины
bool In(vehicle &v, std::ifstream &in_file_stream);

// Случайный ввод обобщенной машины
bool InRnd(vehicle &v);

// Вывод обобщенной машины
void Out(vehicle &v, std::ofstream &out_file_stream);

// Вычисление дальности хода
double Range(vehicle &v);

#endif //ABC_DZ1_VEHICLE_H
