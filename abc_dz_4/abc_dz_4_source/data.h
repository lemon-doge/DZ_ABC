#ifndef __data__
#define __data__
#include <stdio.h>
//------------------------------------------------------------------------------
// data.h - Описание данных бестиповой программы
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Раздел констант
//------------------------------------------------------------------------------

// Константа, определяющая размер целого числа
int const intSize = sizeof(int);
// Константа, определяющая размер действительного числа
int const floatSize = sizeof(float);
// Константа, определяющая размер короткого целого числа
int const shortSize = sizeof(short int);
// Константа, задающая размер для легкового автомобиля
int const carSize = sizeof(int) + sizeof(double) + sizeof(short int);
// Константа, задающая размер для автобуса
int const busSize = sizeof(int) + sizeof(double) + sizeof(short int);
// Константа, задающая размер для грузовика
int const truckSize = sizeof(int) + sizeof(double) + sizeof(int);
// Константа, задающая размер для обощенной машины
int const vehicleSize = truckSize;
// Константа, определяющая размерность массива фигур
int const maxSize = 10000 * vehicleSize;
// Константа, задающая признак легкового автомобиля
int const CAR = 0;
// Константа, задающая признак автобуса
int const BUS = 1;
// Константа, задающая признак грузовика
int const TRUCK = 2;

//------------------------------------------------------------------------------
// Описание используемых функций
//------------------------------------------------------------------------------

// Ввод содержимого контейнера из указанного файла
void InContainer(void *c, int *len, FILE *ifst);
// Случайный ввод содержимого контейнера
void InRndContainer(void *c, int *len, int size);
// Вывод содержимого контейнера в файл
void OutContainer(void *c, int len, FILE *ofst);
// Поиск дальности хода машины
extern float getRange(void* vehicle);
// Нахождение среднего значения дальноси в контейнере
extern float getAverageRange(void *c, int len);



#endif
