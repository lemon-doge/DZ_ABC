#ifndef ABC_DZ5_TEACHER_H
#define ABC_DZ5_TEACHER_H


class Teacher {
private:
    int *answers_; // atomic скорее всего не сработает - но он и не нужен,
    // т.к. не будет доступа к одному и тому же элементу массива из нескольких потоков
    int students_count_;
//    std::mutex mutex_;
public:
    explicit Teacher(int students_count);

    void postAnswer(int student_id, int answer);

    int getMark(int student_id);

    std::string getResultingMarks();
};


#endif //ABC_DZ5_TEACHER_H
