//
// Created by Дмитрий Татьянченко on 08.10.2021.
//
#include <iostream>
#include "container.h"

// Инициализация контейнера
void Init(container &c) {
    std::cout << "initializing container" << std::endl;
    c.len = 0;
}

// Очистка контейнера от элементов
void Clear(container &c) {
    c.len = 0;
}

// Ввод содержимого контейнера из указанного потока
void In(container &c, std::ifstream &in_file_stream) {
    std::cout << "container in" << std::endl;
    while (!in_file_stream.eof()) {
        if (In(c.cont[c.len], in_file_stream)) {   // check size ??
            c.len++;
        }
    }
}

// Случайный ввод содержимого контейнера
void InRnd(container &c, int size) {
    std::cout << "container in rnd" << std::endl;
    while (c.len < size) {
        if (InRnd(c.cont[c.len])) {    // check size ??
            c.len++;
        }
    }
}

// Вывод содержимого контейнера в указанный поток
void Out(container &c, std::ofstream &out_file_stream) {
    std::cout << "container out" << std::endl;
    out_file_stream << "Container contains " << c.len << " elements." << std::endl;
    for (int i = 0; i < c.len; i++) {
        out_file_stream << i << ": ";
        Out(c.cont[i], out_file_stream);
    }
}

// Вычисление среднего значения дальности хода для всех машин в контейнере
double DistanceAverage(container &c) {
    std::cout << "calculating average" << std::endl;
    double sum = 0.0;
    for (int i = 0; i < c.len; i++) {
        sum += Range(c.cont[i]);
    }
    return sum / c.len;
}

// Фильтрация контейнера (без дополнительной памяти за O(n) с потерей порядка следования)
void CoolFilter(container &c) {
    double average = DistanceAverage(c);
    int head = 0, tail = c.len - 1;
    while (tail > head) {
        if (Range(c.cont[head]) < average) {
            if (Range(c.cont[tail]) >= average) {
                std::swap(c.cont[head], c.cont[tail]);
                head++;
                tail--;
            } else {
                tail--;
            }
        } else {
            head++;
        }
    }
    c.len = head + 1;
}

// Филтрация контейнера вторым массивом
void OrdinaryFilter(container &c) {
    std::cout << "filtering container" << std::endl;
    double average = DistanceAverage(c);
    vehicle arr[c.len];
    int arr_index = 0;
    for (int i = 0; i < c.len; ++i) {
        if (Range(c.cont[i]) > average) {
            arr[arr_index] = c.cont[i];
            arr_index++;
        }
    }
    c.len = arr_index + 1;
    for (int i = 0; i < c.len; ++i) {
        c.cont[i] = arr[i];
    }

}