//
// Created by Дмитрий Татьянченко on 08.10.2021.
//

#ifndef ABC_DZ1_CONTAINER_H
#define ABC_DZ1_CONTAINER_H

#include "vehicle.h"

struct container {
    enum {max_len = 10010}; // максимальная длина
    int len; // текущая длина
    vehicle cont[max_len];
};

// Инициализация контейнера
void Init(container &c);

// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c);

// Ввод содержимого контейнера из указанного потока
void In(container &c, std::ifstream &in_file_stream);

// Случайный ввод содержимого контейнера
void InRnd(container &c, int size);

// Вывод содержимого контейнера в указанный поток
void Out(container &c, std::ofstream &out_file_stream);

// Вычисление среднего значения дальности хода машины в контейнере
double DistanceAverage(container &c);

// Удаление элементов, для которых значение ф-ции меньше среднего (ф-ция 19) (chad)
void CoolFilter(container &c);

// Удаление элементов, для которых значение ф-ции меньше среднего (ф-ция 19) (virgin)
void OrdinaryFilter(container &c);

#endif //ABC_DZ1_CONTAINER_H
