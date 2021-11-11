import random
import sys
import time
from enum import Enum

from container import *
from vehicle.bus import *
from vehicle.car import *
from vehicle.truck import *


class Type(Enum):
    CAR = 0
    BUS = 1
    TRUCK = 2


if __name__ == '__main__':
    if len(sys.argv) != 5:
        print("incorrect command line!\n"
              "  Waited:\n"
              "     main -f infile outfile01 outfile02\n"
              "  Or:\n"
              "     main -n number outfile01 outfile02\n")
        exit(1)

    start = time.perf_counter()

    # Cоздание контейнера.
    print('==> Start')
    container = Container()

    if sys.argv[1] == "-f":
        print("input from file")
        # Чтение из тестового файла.
        inputFileName = sys.argv[2]
        print("input file name: " + inputFileName)
        outputFileName = sys.argv[3]
        print("output file name 1: " + outputFileName)
        outputFileName_2 = sys.argv[4]
        print("output file name 2: " + outputFileName_2)

        # Чтение исходного файла, содержащего данные, разделенные пробелами и переводами строки.
        # Формирование контейнера налету.
        # В случае введения некорректных данных, завершается с ошибкой.
        input_file = open(inputFileName)
        for line in input_file:
            data = line.strip().split(' ')
            if int(data[0]) == Type.BUS.value:
                container.append(Bus(int(data[1]), float(data[2]), int(data[3])))
            elif int(data[0]) == Type.CAR.value:
                container.append(Car(int(data[1]), float(data[2]), float(data[3])))
            elif int(data[0]) == Type.TRUCK.value:
                container.append(Bus(int(data[1]), float(data[2]), int(data[3])))
            else:
                raise ValueError("incorrect vehicle type, line: " + line)

        input_file.close()

    elif sys.argv[1] == "-n":
        print("random generation")
        random_number = int(sys.argv[2])
        print("random number: " + str(random_number))
        outputFileName = sys.argv[3]
        print("output file name 1: " + outputFileName)
        outputFileName_2 = sys.argv[4]
        print("output file name 2: " + outputFileName_2)

        # Рандомная генерация контейнера.
        for i in range(random_number):
            vehicle_type = random.randint(0, 2)
            fuel_tank_capacity = random.randint(0, 10000)
            fuel_consumption = random.randint(1, 100) + random.random()
            if int(vehicle_type == Type.BUS.value):
                passenger_capacity = random.randint(0, 144)
                container.append(Bus(fuel_tank_capacity, fuel_consumption, passenger_capacity))
            elif int(vehicle_type == Type.CAR.value):
                speed_limit = random.randint(0, 250) + random.random()
                container.append(Car(fuel_tank_capacity, fuel_consumption, speed_limit))
            elif int(vehicle_type == Type.TRUCK.value):
                carrying_capacity = random.randint(0, 122)
                container.append(Truck(fuel_tank_capacity, fuel_consumption, carrying_capacity))
    else:
        print("Incorrect command line!")
        exit()
        pass

    # Вывод до выполнения функции.
    output_file = open(outputFileName, 'w')

    for vehicle in container:
        output_file.write(vehicle.to_string() + "\n")

    output_file.close()

    average = container.average_range()
    container.filter(lambda x: x.get_range() > average)

    # Вывод после выполнения функции.
    output_file = open(outputFileName_2, 'w')

    for vehicle in container:
        output_file.write(vehicle.to_string() + "\n")

    output_file.close()

    end = time.perf_counter()
    print(f"Time spent: {end - start:0.4f} seconds")
    print('==> Finish')
pass
