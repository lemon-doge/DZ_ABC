//
// Created by Дмитрий Татьянченко on 08.10.2021.
//

#include "bus.h"

// ввод парметров легкового атомобиля из файла
void In(bus &b, std::ifstream &in_file_stream) {
    in_file_stream >> b.passenger_capacity;    // validation ??
}

// случайная генерация легкового автомобиля
void InRnd(bus &b) {
    b.passenger_capacity = rand() % 120 + 1;
}

// вывод параметров легкового автомобиля в поток
void Out(bus &b, std::ofstream &out_file_stream) {
    out_file_stream << " passenger capacity: " << b.passenger_capacity;
}
