//
// Created by Дмитрий Татьянченко on 08.10.2021.
//

#include "truck.h"

// ввод парметров грузовика из файла
void In(truck &t, std::ifstream &in_file_stream) {
    in_file_stream >> t.carrying_capacity; // validation ??
}

// случайная генерация грузовика
void InRnd(truck &t) {
    t.carrying_capacity = rand() % 20000 + 1;
}

// вывод параметров грузовика в поток
void Out(truck &t, std::ofstream &out_file_stream) {
    out_file_stream << " carrying capacity (short tons): " << t.carrying_capacity;
}
