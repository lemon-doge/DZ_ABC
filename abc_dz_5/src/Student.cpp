#include <thread>
#include <future>
#include "Student.h"

void Student::handleAnswer(const Teacher &teacher) {
    // созадем поток прямо здесь
    this->thread_ = std::thread(&Teacher::postAnswer, teacher, this->id_, this->ans_);
}

Student::Student(int id, int ans) {
    if (id < 0) {
        throw std::invalid_argument("Incorrect student id.");
    }
    this->id_ = id;
    this->ans_ = ans;
    this->mark_ = 0;
}

void Student::getMark(const Teacher &teacher) {
    // используем механику promise-future, чтобы асинхронно запустить вызов функции getMark и обновить поле mark_
    std::future<int> future = std::async(std::launch::async, &Teacher::getMark, teacher, this->id_);
    this->mark_ = future.get();
}

void Student::join() {
    this->thread_.join();
}

int Student::mark() {
    return this->mark_;
}
