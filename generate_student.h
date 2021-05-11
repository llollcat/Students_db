//
// Created by tiramisu on 10.05.2021.
//

#ifndef STUDENTS_DB_GENERATE_STUDENT_H
#define STUDENTS_DB_GENERATE_STUDENT_H

#include "Data/Student.h"
#include "random"

Student *generate_student() {

    static auto getRandomNumber = [](int min, int max) {
        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
        return static_cast<int>(rand() * fraction * (max - min + 1) + min);
    };

    int yoe = getRandomNumber(2015, 2020);
    static const std::string names[] = {"Александр", "Алексей", "Анатолий", "Андрей", "Антон", "Аркадий", "Арсений"};
    static const std::string second_names[] = {"Смирнов", "Иванов", "Кузнецов", "Соколов", "Попов", "Лебедев",
                                               "Козлов"};
    static const std::string patronymics[] = {"Александрович", "Алексеевич", "Анатольевич", "Андреевич", "Антонович",
                                              "Аркадьевич"};
    static const std::string faculties[] = {"Физики", "Химии", "Биологии", "Философии", "Информатики"};

    static const std::string groups[] = {"БИБА-01", "БОБА-02", "ТИТА-03", "НЫНЪ-04", "ЪЫЬЪ-05"};
    static int record_book_number = -1;
    ++record_book_number;
    auto *student = new Student(yoe, faculties[getRandomNumber(0, 4)],
                                   groups[getRandomNumber(0, 4)],
                                   std::to_string(record_book_number), getRandomNumber(1, 28), getRandomNumber(1, 12),
                                   getRandomNumber(1995, 2000),
                                   second_names[getRandomNumber(0, 6)] + " " + names[getRandomNumber(0, 6)] + " " +
                                   patronymics[getRandomNumber(0, 5)], getRandomNumber(0, 1));


    static const std::string subjects[] = {"Физика", "Матан", "Физра", "История", "Линал", "Английский"};


    SessionsContainer sessionsContainer = SessionsContainer();
    int end = getRandomNumber(3, 9);
    for (int i = 1; i <= end; ++i) {
        sessionsContainer.addSession(i, subjects[getRandomNumber(0, 5)], getRandomNumber(2, 5));
    }
    student->sessions = sessionsContainer;

    return student;
}


#endif //STUDENTS_DB_GENERATE_STUDENT_H
