#include <iostream>

#include "Includes.h"
#include "cryptopp/modes.h"
/*    studentsManager.NewStudent(new Student(2019, "Информатика", "БИБА-20-21",
                                           "БОБА06А", 1, 12, 2001, "Клинков Клин Клинычъ", true));
    studentsManager.NewStudent(new Student(2020, "Кулинария", "БОКА-22-33",
                                           "ГБП007Ж", 11, 1, 2002, "Килькова Килька Киличовна", false));

    studentsManager.students[0]->sessions.addSession(9, "Физкультура", 3);*/

int main() {
    setlocale(LC_ALL, "Russian");

    std::string path = "student";


    StudentsContainer mainStudentContainer = StudentsContainer();
    mainStudentContainer.load(path);


    std::cout << "help для вывода списка команд.\n";

    bool is_need_exit = false;
    while (!is_need_exit) {
        std::string command;
        std::cin >> command;

        std::cout << *mainStudentContainer.FindStudents(command);






        is_need_exit = true;
    }






    mainStudentContainer.save(path);























    // std::cout << sizeof (*studentsManager.students[0]);






    return 0;
}
