#include "Teacher.h"

Teacher::Teacher(int students_count) {
    this->students_count_ = students_count;
    this->answers_ = new int[students_count_] {}; // инициализация на случай нарушения порядка доступа
}

void Teacher::postAnswer(int student_id, int answer) {
    //this->mutex_.lock();
    // интересно убрать блокировку и посмотреть, отработает ли корректно параллельная запись в разные ячейки массива
    // должно работать согласно § 17.6.5.9 стандарта c++ 11 и выше(см. пояснительная записка[1])
    if (student_id < this->students_count_ && student_id >= 0) {
        this->answers_[student_id] = answer;
    }
    //this->mutex_.unlock();
}

int Teacher::getMark(int student_id){
    // параллельный доступ к ячейкам массива - должно работать по ПЗ[1]
    if (student_id < this->students_count_ && student_id >= 0) {
        return (student_id * student_id + this->answers_[student_id] * this->answers_[student_id]) % 10;
    }
    return -1;
}

std::string Teacher::getResultingMarks() {
    std::string indexes, answers, marks;
    for (int i = 0; i < this->students_count_; ++i) {
        int answer = this->answers_[i];
        indexes += std::to_string(i) + ' ';
        answers += std::to_string(answer) + ' ';
        marks += std::to_string((i * i + answer * answer) % 10) + ' ';
    }
    return "id:   " + indexes + "\nans:  " + answers + "\nmark: " + marks;
}
