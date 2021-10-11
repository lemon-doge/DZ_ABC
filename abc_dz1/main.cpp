#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include  <time.h>

#include <iostream>

#include "container.h"

#define HELP_MESSAGE    "How to use the program: <executable_name> [OPTIONS]...\n"                                \
                        "\n"                                                                                      \
                        "OPTIONS:\n"                                                                              \
                        " -i - input file path\n"                                                                 \
                        " -o - output file path"                                                                  \
                        "if the output file does not exist - program will create one\n"                           \
                        " -r [number of elements in [1,10000]] - generate random input according to task specifications\n"     \
                        "\n"                                                                                      \
                        "\n"                                                                                      \
                        "POSSIBLE USE CASES:"                                                                     \
                        "<executable_name> -h"                                                                    \
                        "<executable_name> -i <input_file_path> -o <output_file_stream-path>"                            \
                        "<executable_name> -r <number_of_elements_in_container> -o <output_file_stream-path>"            \
                        "\n"                                                                                      \
                        "\n"                                                                                      \
                        "INPUT FILE SPECIFICATIONS:\n"                                                            \
                        "Input file starts with number of elements (int_32)\n"                                    \
                        "Elements consist of fields:\n"                                                     \
                        "\t `element_type`: 0 - CAR, 1 - BUS, 2 - TRUCK\n"                         \
                        "\t `element_description`:\n"                                                             \
                        "\t `common fields`: fuel_tank_capacity(int32_t) fuel_consumption(double) != 0 !!!"\
                        "\t\t CAR: speed_limit(short)\n"              \
                        "\t\t\t  example: `0 123 22 33` -> car(fuel_tank_capacity = 123, fuel_consumption = 22, speed_limit = 33)\n"            \
                        "\t\t BUS: passenger_capacity(short)\n"              \
                        "\t\t\t  example: `1 123 22 33` -> bus(fuel_tank_capacity = 123, fuel_consumption = 22, passenger_capacity = 33)\n"            \
                         "\t\t TRUCK: carrying_capacity(int)\n"              \
                        "\t\t\t  example: `2 123 22 33` -> truck(fuel_tank_capacity = 123, fuel_consumption = 22, carrying_capacity = 33 )\n"            \
                        "See examples at /tests/example.txt"                                                                                   \

#define ARGC_INVALID_EXCEPTION "Incorrect program input\n" \
                                "Try 'program -h' for details."

#define INPUT_FLAG_INVALID_EXCEPTION    "Input flag was not specified\n" \
                                        "Try 'program -h' for details."

#define INPUT_FILE_DOES_NOT_EXIST_EXCEPTION "Input file does not exist\n"

#define OUTPUT_FLAG_INVALID_EXCEPTION   "Output flag was not specified\n" \
                                         "Try 'program -h' for details."

#define RANDOM_INPUT_FLAG_INVALID_EXCEPTION "Random random_size was not specified\n" \
                                        "Try 'program -h' for details."

#define FLAGS_COMPATABILITY_EXCEPTION "Incompatible flags found together\n" \
                                        "Try 'program -h' for details."

// Возможные флаги программы.
enum PROGRAM_FLAGS {
    HELP = 0,
    INPUT = 1,
    OUTPUT = 2,
    RANDOM = 3
};

const char *program_flags[] = {"-h", "-i", "-o", "-r"};
const int input_flags_count = 4;
int flags_positions[input_flags_count] = {};
int random_size;
std::ifstream input_file_stream;
std::ofstream output_file_stream;

// Валидация флага.
// Возвращает индекс флага в program_flags, если он валиден, иначе: -1
int get_flag(const char *input) {
    for (int i = 0; i < input_flags_count; ++i) {
        if (!strcmp(input, program_flags[i])) {
            return i;
        }
    }
    return -1;
}

// Проверка валидности поставленных флагов.
bool check_flags() {
    return (((!flags_positions[HELP] && flags_positions[INPUT] &&
              flags_positions[OUTPUT] && !flags_positions[RANDOM]) ||
             (flags_positions[HELP] && !flags_positions[INPUT] &&
              !flags_positions[OUTPUT] && !flags_positions[RANDOM]) ||
             (!flags_positions[HELP] && !flags_positions[INPUT] &&
              flags_positions[OUTPUT] && flags_positions[RANDOM])));
}

// Для каждого найденного валидного флага запоминает его позицию в argv
// Проверяет флаги на совместимость
void parse_flags(int argc, char *argv[]) {
    std::cout << "parsing flags" << std::endl;
    if (argc > 5 || argc < 2) {
        std::cout << ARGC_INVALID_EXCEPTION;
        exit(1);
    } else if (argc == 2) {
        if (!strcmp(argv[1], "-h")) {
            printf(HELP_MESSAGE);
            exit(0);
        } else {
            std::cout << ARGC_INVALID_EXCEPTION;
            exit(1);
        }
    } else if (argc > 2) {
        for (int i = 1; i < argc; ++i) {
            int flag = get_flag(argv[i]);
            if (flag != -1) {
                flags_positions[flag] = i;
            }
        }
    }

    if (!check_flags()) {
        std::cout << ARGC_INVALID_EXCEPTION;
        exit(1);
    }
    std::cout << "flags parsed" << std::endl;

}


// Получить указатель на входной файл.
void get_input_file(int argc, char *argv[]) {
    std::cout << "getting input file" << std::endl;
    if (flags_positions[INPUT] + 1 < argc) {
        if (access(argv[flags_positions[INPUT] + 1], F_OK) != -1)
            return input_file_stream.open(argv[flags_positions[INPUT] + 1]);
        else {
            printf(INPUT_FILE_DOES_NOT_EXIST_EXCEPTION);
            exit(1);
        }
    } else {
        std::cout << INPUT_FLAG_INVALID_EXCEPTION;
        exit(1);
    }

}

// Получить указатель на выходной файл.
void get_output_file(int argc, char *argv[]) {
    std::cout << "getting output file" << std::endl;
    if (flags_positions[OUTPUT] + 1 < argc) {
        return output_file_stream.open(argv[flags_positions[OUTPUT] + 1], std::ofstream::out);
    } else {
        std::cout << OUTPUT_FLAG_INVALID_EXCEPTION;
        exit(1);
    }
}

// Получить размер случайной генерации.
int get_random_size(int argc, char *argv[]) {
    std::cout << "getting random size" << std::endl;
    if (flags_positions[RANDOM] + 1 < argc) {
        return std::stoi(argv[flags_positions[RANDOM] + 1]);
    } else {
        std::cout << RANDOM_INPUT_FLAG_INVALID_EXCEPTION;
        exit(1);
    }
}


int main(int argc, char *argv[]) {
    time_t start, stop;

    start = clock();


    // Парсим флаги + валидируем их
    parse_flags(argc, argv);


    std::cout << "Start" << std::endl;
    container _container;
    Init(_container);

    // Открыть выходной файл.
    get_output_file(argc, argv);

    // Инициализируем случайное заполнение.
    if (flags_positions[RANDOM]) {
        random_size = get_random_size(argc, argv);
        if ((random_size < 1) || (random_size > 10000)) {
            std::cout << "Invalid random_size = "
                      << random_size
                      << ". Set 0 < random_size <= 10000\n";
            return 3;
        }
        srand(static_cast<unsigned int>(time(nullptr)));
        // Заполнение контейнера генератором случайных чисел
        InRnd(_container, random_size);

    }
        // Инициализируем заполнение из файла.
    else if (flags_positions[INPUT]) {
        // Открыть входной файл.
        get_input_file(argc, argv);
        In(_container, input_file_stream);
        input_file_stream.close();
    }

    // Вывод содержимого контейнера в файл
    output_file_stream << "Filled container:\n";
    Out(_container, output_file_stream);

    // Вторая часть задания
    output_file_stream << "\n\n=======================\n\n";
    output_file_stream << "Filtration results:\n";

    std::cout << "Filtering container\n";

    OrdinaryFilter(_container);

    Out(_container, output_file_stream);

    Clear(_container);

    stop = clock();
    std::cout << "Elapsed: " + std::to_string(difftime(stop, start) / CLOCKS_PER_SEC) + " seconds." << std::endl;

    output_file_stream << "\n\n=======================\n\n";
    output_file_stream << "Finished in " + std::to_string(difftime(stop, start) / CLOCKS_PER_SEC) + " seconds.";

    output_file_stream.close();
    std::cout << "Stop." << std::endl;
    return 0;
}
