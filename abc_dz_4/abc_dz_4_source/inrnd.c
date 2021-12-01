//------------------------------------------------------------------------------
// inrnd.c - единица компиляции, вбирающая функции генерации случайных данных
//------------------------------------------------------------------------------

#include <stdlib.h>

#include "extdata.h"

// Случайный ввод параметров легкового автомобиля 
void InRndCar(void *car) {
    short speed_limit = rand()%180 + 1;
    *((short*)car) = speed_limit;
//     printf("    Rectangle %d %d\n", *((int*)r), *((int*)r+1));
}

// Случайный ввод параметров автобуса
void InRndBus(void *bus) {
    short passenger_capacity = rand()%20 + 1;
    *((short*)bus) = passenger_capacity;
//     printf("    Rectangle %d %d\n", *((int*)r), *((int*)r+1));
}

// Случайный ввод параметров грузовика
void InRndTruck(void *truck) {
    int carrying_capapcity = rand()%149 + 1;
    *((short*)truck) = carrying_capapcity;
//     printf("    Rectangle %d %d\n", *((int*)r), *((int*)r+1));
}

// Случайный ввод обобщенной машины
int InRndVehicle(void *vehicle) {
    int fuel_tank_capacity = rand()%200 + 1;
    *((int*)(vehicle+intSize)) = fuel_tank_capacity;
    float fuel_consumption = rand()%10 + (rand() % 10001) / 10000.0;
    *((float*)(vehicle+2*intSize)) = fuel_consumption;

    int key = rand() % 3 + 1;
    switch(key) {
        case 0:
            *((int*)vehicle) = CAR;
            InRndCar(vehicle+2*intSize+floatSize);
//              printf("Shape %d %d %d %d\n",
//                     *((int*)s), *((int*)s+1),
//                     *((int*)s+2), *((int*)s+3));
            return 1;
        case 1:
            *((int*)vehicle) = BUS;
            InRndBus(vehicle+2*intSize+floatSize);
//              printf("Shape %d %d %d %d\n",
//                     *((int*)s), *((int*)s+1),
//                     *((int*)s+2), *((int*)s+3));
            return 1;
        case 2:
            *((int*)vehicle) = TRUCK;
            InRndTruck(vehicle+2*intSize+floatSize);
//              printf("Shape %d %d %d %d\n",
//                     *((int*)s), *((int*)s+1),
//                     *((int*)s+2), *((int*)s+3));
            return 1;
        default:
            return 0;
    }
}

// Случайный ввод содержимого контейнера
void InRndContainer(void *c, int *len, int size) {
    void *tmp = c;
    while(*len < size) {
        if(InRndVehicle(tmp)) {
            tmp = tmp + vehicleSize;
            (*len)++;
        }
    }
}
