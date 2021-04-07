#include <iostream>

#include "Includes.h"
#include "cryptopp/modes.h"


























int main() {
    setlocale(LC_ALL,"Russian");


    StudentsManager studentsManager = StudentsManager();

    studentsManager.NewStudent(new Student(2020, "", "", "123", 1,1,2002,"chel", true));
    studentsManager.NewStudent(new Student(2019, "da", "net", "123", 1,1,2002,"chel", true));
    studentsManager.NewStudent(new Student(2020, "da", "net", "123", 1,1,2002,"chel", true));


    //std::cout <<studentsManager.students[0]->getFaculty();



















    std::cout << sizeof (*studentsManager.students[0]);






    return 0;
}
