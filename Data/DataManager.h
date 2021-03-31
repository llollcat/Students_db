//
// Created by tiramisu on 30.03.2021.
//

#ifndef UNTITLED_DATAMANAGER_H
#define UNTITLED_DATAMANAGER_H
#include "vector"
#include "../ERROR_CODES.h"

class Student;
class DataManager{
private:
    int32_t student_counter = 0;

    std::vector<Student*> students;

public:
    ERROR_CODES NewStudent(Student *student) {
        student->id = student_counter;
        ++student_counter;
        this->students.push_back(student);
        return OK;
    }
    void FindStudents() {




    }



    ERROR_CODES DeleteStudent() {


    }







};

#endif //UNTITLED_DATAMANAGER_H
