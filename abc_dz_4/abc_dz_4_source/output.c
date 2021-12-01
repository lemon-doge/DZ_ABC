//------------------------------------------------------------------------------
// output.c - единица компиляции, вбирающая в себя все функции вывода данных
//------------------------------------------------------------------------------

#include "extdata.h"
#include <stdio.h>

// Вывод параметров легкового автомобиля
void OutCar(void *car, FILE *ofst) {
    fprintf(ofst, "CAR: fuel tank capacity = %d, fuel consumption = %f, speed limit = %d\n",
            *((int*)car), *((float*)(car+intSize)),*((short*)(car+intSize+floatSize)));
}

// Вывод параметров автобуса
void OutBus(void *bus, FILE *ofst) {
    fprintf(ofst, "BUS: fuel tank capacity = %d, fuel consumption = %f, passenger capacity = %d\n",
            *((int*)bus), *((float*)(bus+intSize)), *((short*)(bus+intSize+floatSize)));
}

// Вывод параметров грузовика
void OutTruck(void *truck, FILE *ofst) {
    fprintf(ofst, "TRUCK: fuel tank capacity = %d, fuel consumption = %f, carrying capacity = %d\n",
            *((int*)truck), *((float*)(truck+intSize)),*((int*)(truck+intSize+floatSize)));
}

// Вывод параметров текущей машины в поток
void OutVehicle(void *vehicle, FILE *ofst) {
    int key = *((int*)vehicle);
    if(key ==CAR){
        OutCar(vehicle+intSize, ofst);
    } else if(key == BUS){
        OutBus(vehicle+intSize, ofst);
    } else if(key == TRUCK){
        OutTruck(vehicle+intSize, ofst);
    }else{
        fprintf(ofst, "Incorrect figure!\n");
    }
}

// Вывод содержимого контейнера в файл
void OutContainer(void *c, int len, FILE *ofst) {
    void *tmp = c;
    fprintf(ofst, "Container contains %d elements.\n", len);
    for(int i = 0; i < len; i++) {
        fprintf(ofst, "%d: ", i);
        OutVehicle(tmp, ofst);
        tmp = tmp + vehicleSize;
    }
}
