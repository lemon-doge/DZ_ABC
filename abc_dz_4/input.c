//------------------------------------------------------------------------------
// input.c - единица компиляции, вбирающая в себя все функции ввода данных
//------------------------------------------------------------------------------

#include "extdata.h"
#include <stdio.h>

// Ввод параметров легкового атомобиля из файла
// fuel tank capacity (int), fuel consumption (float), speed limit (short)
void InCar(void *car, FILE *ifst) {
    fscanf(ifst, "%d %f %d", (int*)car, (float*)(car+intSize), (short*)(car+intSize+floatSize));
    //printf("    Rectangle %d %d\n", *((int*)r), *((int*)r+1));
}

// Ввод параметров автобуса из файла
// fuel tank capacity (int), fuel consumption (float), passenger capacity (short)
void InBus(void *bus, FILE *ifst) {
    fscanf(ifst, "%d %f %d", (int*)bus, (float*)(bus+intSize), (short*)(bus+intSize+floatSize));
    //printf("    Rectangle %d %d\n", *((int*)r), *((int*)r+1));
}

// Ввод параметров грузовика из файла
// fuel tank capacity (int), fuel consumption (float), carrying capacity (int)
void InTruck(void *truck, FILE *ifst) {
    fscanf(ifst, "%d %f %d", (int*)truck, (float*)(truck+intSize), (int*)(truck+intSize+floatSize));
    //printf("    Rectangle %d %d\n", *((int*)r), *((int*)r+1));
}

// Ввод параметров обобщенного транспортного средства из файла
int InVehicle(void *vehicle, FILE *ifst) {
    int key;
    fscanf(ifst, "%d", &key);
    switch(key) {
        case 0:
            *((int*)vehicle) = CAR;
            InCar(vehicle+intSize, ifst);
            return 1;
        case 1:
            *((int*)vehicle) = BUS;
            InBus(vehicle+intSize, ifst);
            return 1;
        case 2:
            *((int*)vehicle) = TRUCK;
            InTruck(vehicle+intSize, ifst);
            return 1;
        default:
            return 0;
    }
}

// Ввод содержимого контейнера из указанного файла
void InContainer(void *c, int *len, FILE *ifst) {
    void *tmp = c;
    while(!feof(ifst)) {
        if(InVehicle(tmp, ifst)) {
            tmp = tmp + vehicleSize;
            (*len)++;
        }
    }
    (*len)--;
}
