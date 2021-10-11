//
// Created by Дмитрий Татьянченко on 08.10.2021.
//

#ifndef ABC_DZ1_BUS_H
#define ABC_DZ1_BUS_H

#include <fstream>

// пассажирский автобус
struct bus {
    short passenger_capacity;
};

// Ввод параметров грузовика из файла
void In(bus &b, std::ifstream &in_file_stream);

// Случайный ввод параметров грузовика
void InRnd(bus &b);

// Вывод параметров грузовика в форматируемый поток
void Out(bus &b, std::ofstream &out_file_stream);

#endif //ABC_DZ1_BUS_H
