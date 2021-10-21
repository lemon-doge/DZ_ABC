//
// Created by Дмитрий Татьянченко on 08.10.2021.
//

#ifndef ABC_DZ1_CAR_H
#define ABC_DZ1_CAR_H

#include <fstream>

// легковой автомобиль
struct car {
    short speed_limit;
};

// Ввод параметров грузовика из файла
void In(car &c, std::ifstream &in_file_stream);

// Случайный ввод параметров грузовика
void InRnd(car &c);

// Вывод параметров грузовика в форматируемый поток
void Out(car &c, std::ofstream &out_file_stream);

#endif //ABC_DZ1_CAR_H
