#include <iostream>
#include "Student.h"
int main() {
    std::cout << "Hello, World!" << std::endl;

    Student student = Student(2020,"hi","baso?","1", 1,1,1990,"h", false);

    std::cout << student.getFullName();

    return 0;
}
