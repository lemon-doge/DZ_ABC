#ifndef __extdata__
#define __extdata__

//------------------------------------------------------------------------------
// extdata.h - Описание внешних данных
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Раздел констант
//------------------------------------------------------------------------------

// Константа, определяющая размер целого числа
extern int const intSize;
// Константа, определяющая размер действительного числа
extern int const floatSize;
// Константа, определяющая размер короткого целого числа
extern int const shortSize;
// Константа, задающая размер для легкового автомобиля
extern int const carSize;
// Константа, задающая размер для автобуса
extern int const busSize;
// Константа, задающая размер для грузовика
extern int const truckSize;
// Константа, задающая размер для обощенной машины
extern int const vehicleSize;
// Константа, определяющая размерность массива фигур
extern int const maxSize;
// Константа, задающая признак легкового автомобиля
extern int const CAR;
// Константа, задающая признак автобуса
extern int const BUS;
// Константа, задающая признак грузовика
extern int const TRUCK;
// Поиск дальности хода машины
extern float getRange(void* vehicle);
// Нахождение среднего значения дальноси в контейнере
extern float getAverageRange(void *c, int len);

//------------------------------------------------------------------------------
// Раздел данных
//------------------------------------------------------------------------------

// Количество элементов в массиве
// external int len;

//------------------------------------------------------------------------------
// Раздел выделяемой памяти
//------------------------------------------------------------------------------

// Массив используемый для хранения данных
//external int cont[];



//------------------------------------------------------------------------------
// Описание используемых функций
//------------------------------------------------------------------------------

// Ввод содержимого контейнера из указанного файла
//void InContainer(void *c, int *len, FILE *ifst);
// Случайный ввод содержимого контейнера
//void InRndContainer(void *c, int *len, int size);
// Вывод содержимого контейнера в файл
//void OutContainer(void *c, int len, FILE *ofst);
// Вычисление суммы периметров всех фигур в контейнере
//double PerimeterSumContainer(void *c, int len);

#endif
