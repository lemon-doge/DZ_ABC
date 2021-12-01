//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию, 
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <stdlib.h> // для функций rand() и srand()
#include <time.h>   // для функции time()
#include <string.h>

#include "data.h"
// #include "input.c"
// #include "inrnd.c"
// #include "perimeter.c"
// #include "output.c"

// фильтрация контейнера
// принимает старый контейнер
// пустой новый контейнер, в который помещаются подходящие машины
// возвращает кол-во машин в отфильтрованном контейнере
int FilterContainer(void *old_cont, void *new_cont, int old_len) {
    double average = getAverageRange(old_cont, old_len);
    void *tmp = old_cont;
    int new_len = 0;
    for(int i = 0; i < old_len; i++) {
        if(getRange(tmp) >= average){
           memcpy(new_cont + new_len*vehicleSize, tmp, vehicleSize);
           new_len++;
           }
        tmp = tmp + vehicleSize;
    }
    return new_len;
}

void errMessage1() {
    printf("incorrect command line!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n");
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    // Массив используемый для хранения данных
    //unsigned int cont[maxSize / intSize];
    //int cont[maxSize / intSize];
    unsigned char cont[maxSize];
    // Количество элементов в массиве
    int len = 0;

    printf("intSize = %d\n", intSize);
    printf("floatSize = %d\n", floatSize);
    printf("shortSize = %d\n", shortSize);
    printf("carSize = %d\n", carSize);
    printf("busSize = %d\n", busSize);
    printf("truckSize = %d\n", truckSize);
    printf("vehicleSize = %d\n", vehicleSize);
    printf("maxSize = %d\n", maxSize);
    printf("CAR = %d\n", CAR);
    printf("BUS = %d\n", BUS);
    printf("TRUCK = %d\n", TRUCK);
    printf("Size of container = %d\n", sizeof(cont));


    if(argc != 5) {
        errMessage1();
        return 1;
    }

    printf("Start\n");
    //InitContainer(&cont);

    if(!strcmp(argv[1], "-f")) {
        FILE* ifst = fopen(argv[2], "r");
        InContainer(cont, &len, ifst);
    }
    else if(!strcmp(argv[1], "-n")) {
        int size = atoi(argv[2]);
        if((size < 1) || (size > 10000)) { 
            printf("incorrect numer of vehicles = %d. Set 0 < number <= 10000\n",
                   size);
            return 3;
        }
        // системные часы в качестве инициализатора
        srand((unsigned int)(time(0)));
        // Заполнение контейнера генератором случайных чисел
        InRndContainer(cont, &len, size);
    }
    else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    fprintf(stdout, "Filled container:\n");
    OutContainer(cont, len, stdout);
    FILE* ofst1 = fopen(argv[3], "w");
    fprintf(ofst1, "Filled container:\n");
    OutContainer(cont, len, ofst1);
    fclose(ofst1);

    // The 2nd part of the task
    FILE* ofst2 = fopen(argv[4], "w");
    clock_t start = clock();

    unsigned char new_cont[maxSize];
    int new_len = FilterContainer(cont, new_cont, len);
    // массивы объявлены статически => память чистить не надо


    clock_t end = clock();
    double calcTime = ((double)(end - start)) / (CLOCKS_PER_SEC + 1.0);

    fprintf(ofst2, "Container filtered. Filtration time = %g\n", calcTime);
    OutContainer(new_cont, new_len, ofst2);    
    fclose(ofst2);

    fprintf(stdout, "Container filtered. Filtration time = %g\n", calcTime);
    //ClearContainer(&c);
    printf("Stop\n");
    return 0;
}
