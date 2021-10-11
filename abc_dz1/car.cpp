//
// Created by Дмитрий Татьянченко on 08.10.2021.
//

#include "car.h"

// ввод парметров легкового атомобиля из файла
void In(car &c, std::ifstream &in_file_stream) {
    in_file_stream >> c.speed_limit;    // validation ??
}

// случайная генерация легкового автомобиля
void InRnd(car &c) {
    c.speed_limit = rand() % 20000 + 1;
}

// вывод параметров легкового автомобиля в поток
void Out(car &c, std::ofstream &out_file_stream) {
    out_file_stream << " speed limit (mph): " << c.speed_limit;
}
