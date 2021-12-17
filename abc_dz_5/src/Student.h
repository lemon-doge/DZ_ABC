#ifndef ABC_DZ5_STUDENT_H
#define ABC_DZ5_STUDENT_H

#include <thread>
#include "Teacher.h"


class Student {
private:
    int id_;
    int ans_;
    int mark_;
    std::thread thread_;

public:
    Student(int id, int ans);

    void handleAnswer(const Teacher& teacher);

    void join();

    void getMark(const Teacher& teacher);

    int mark();
};


#endif //ABC_DZ5_STUDENT_H
