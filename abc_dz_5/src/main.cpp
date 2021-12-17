#include <iostream>
#include <vector>
#include "Student.h"
#include "Teacher.h"
#include "Student.cpp"
#include "Teacher.cpp"

int main() {
    int students_count;
    std::cout << "Enter number of students: ";
    std::cin >> students_count;
    std::srand(std::time(nullptr));

    Teacher teacher = Teacher(students_count);
    std::vector<Student> students = std::vector<Student>();

    for (int i = 0; i < students_count; ++i) {
        students.emplace_back(i, std::rand()%11); // чо могу
    }

    for (int i = 0; i < students_count; ++i) {
       students[i].handleAnswer(teacher);
    }

    for (int i = 0; i < students_count; ++i) {
        students[i].join();
    }

    for (int i = 0; i < students_count; ++i) {
        students[i].getMark(teacher);
    }

    std::cout << teacher.getResultingMarks() << std::endl;
    std::cout << "Marks gotten from students: \n";
    for (int i = 0; i < students_count; ++i) {
        std::cout << students[i].mark() << ' ';
    }

    return 0;
}
