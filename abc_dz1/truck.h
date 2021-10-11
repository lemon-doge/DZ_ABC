//
// Created by Дмитрий Татьянченко on 08.10.2021.
//

#ifndef ABC_DZ1_TRUCK_H
#define ABC_DZ1_TRUCK_H

#include <fstream>


// груовик
struct truck {
    int carrying_capacity;
};

// Ввод параметров грузовика из файла
void In(truck &t, std::ifstream &in_file_stream);

// Случайный ввод параметров грузовика
void InRnd(truck &t);

// Вывод параметров грузовика в форматируемый поток
void Out(truck &t, std::ofstream &out_file_stream);

#endif //ABC_DZ1_TRUCK_H
