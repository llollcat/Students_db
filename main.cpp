#include <iostream>

#include "Includes.h"
#include "cryptopp/modes.h"
#include "map"
# include <locale>
# include <codecvt>

#define new_pair(str, SC) std::pair<std::string, StudentsContainer *>(str, SC)
std::map<std::string, StudentsContainer *> containers;

#define get_val(out, input_val)             std::cout << out << std::endl;             getline(std::cin, input_val); std::cout << std::endl;

#define check(input_val) if ((input_val.find("\n") !=-1) ||(input_val.find("_")!=-1) || (input_val.empty())) { std::cout << "Встречены запрещённые символы или пустая строка.\n"; continue;}


int main() {
    setlocale(LC_ALL, "Russian");

    std::string path = "student";


    MainStudentContainer mainStudentContainer = MainStudentContainer();
    mainStudentContainer.load(path);


/*    mainStudentContainer.NewStudent(new Student(2019, "Информатика", "БИБА-20-21",
                                           "БОБА06А", 1, 12, 2001, "Клинков Клин Клинычъ", true));
    mainStudentContainer.NewStudent(new Student(2020, "Кулинария", "БОКА-22-33",
                                           "ГБП007Ж", 11, 1, 2002, "Килькова Килька Киличовна", false));

    mainStudentContainer.students[0]->sessions.addSession(9, "Физкультура", 3);*/





    std::cout << "help для вывода списка команд.\n";
    bool is_need_exit = false;
    while (!is_need_exit) {
        std::string command;
        getline(std::cin, command);

        if (command == "help") {
            std::cout << "Использование:\n"
                         "  Новый список       newL\n"
                         "  Удалить список                   delL\n"
                         "  Добавить студента                addS\n"
                         "  Удалить студента                 delS\n"
                         "  Отфильтровать список студентов   findS\n"
                         "  Вывести список                   print\n"
                         "  Завершить программу              quit\n";

        } else if (command == "newL") {
            std::cout << "Введите назвение списка\n";
            getline(std::cin, command);
            check(command);


            StudentsContainer *sc = new StudentsContainer(mainStudentContainer);


            if (containers.find(command) == containers.end()) {
                containers.insert(new_pair(command, sc));
                std::cout << "Созданно\n";
            } else
                std::cout << "Уже существует\n";


        } else if (command == "delL") {
            std::cout << "Введите назвение списка\n";
            getline(std::cin, command);

            if (containers.find(command) == containers.end()) {
                std::cout << "Такого списка не существует\n";
            } else {
                containers.erase(command);
                std::cout << "Удалено\n";
            }

        } else if (command == "delS") {
            std::cout << "Введите номер студента из основного списка.\n";
            getline(std::cin, command);
            if (mainStudentContainer.DeleteStudent(std::stoi(command)) == OK) {
                std::cout << "Удалено\n";
            } else {
                std::cout << "Ошибка/n";
            }

        } else if (command == "addS") {


            std::string name, faculty, group, re_bo_num;
            bool sex;
            int yoe;

            get_val("ФИО", name);
            check(name);
            get_val("Факультет", faculty);
            check(faculty);
            get_val("Группа", group);
            check(group);
            get_val("Номер зачётной книжки", re_bo_num);
            check(re_bo_num);

            get_val("Год поступления", command);
            check(command);
            if (command.find(".") != -1)
                std::cout << "Не правильный формат ввода даты\n";
            try {
                yoe = std::stoi(command);
            } catch (std::invalid_argument) {
                std::cout << "Не правильный формат ввода даты\n";
                continue;
            }

            bool is_error = true;
            get_val("Пол", command);
            if (command == "Муж.") {
                sex = true;
                is_error = false;
            } else if (command == "Жен.") {
                sex = false;
                is_error = false;
            } else {
                std::cout << "Не коректный ввод";
                continue;
            }


            get_val("Дата рождения", command);
            check(command);
            Date date = Date();
            if (date.setDate(command) != OK) {
                std::cout << "Не правильный формат ввода даты\n";
                continue;
            }
            SessionsContainer sessionsContainer = SessionsContainer();

            std::cout << "Для остановки добавления введите пустую строчку" << std::endl;
            for (;;) {
                get_val("Введите номер сессии", command);

                if (command.empty())
                    break;
                int session_number;
                if (command.find(".") != -1)
                    std::cout << "Не правильный формат ввода номера\n";
                try {
                    session_number = std::stoi(command);
                } catch (std::invalid_argument) {
                    std::cout << "Не правильный формат ввода номера\n";
                    continue;
                }


                std::string subject, grade;

                get_val("Введите название предмета", subject);
                check(subject);
                get_val("Введите оценку", grade);
                check(grade);

                int session_grade;
                if (command.find(".") != -1)
                    std::cout << "Не правильный формат ввода номера\n";
                try {
                    session_grade = std::stoi(grade);
                } catch (std::invalid_argument) {
                    std::cout << "Не правильный формат ввода номера\n";
                    continue;
                }

                sessionsContainer.addSession(session_number, subject, session_grade);


            }


            mainStudentContainer.NewStudent(
                    new Student(yoe, faculty, group, re_bo_num, date, name, sex, sessionsContainer));
            std::cout << "Добавлено\n";


        } else if (command == "editS") {
            ERROR_CODES errorCode = OK;
            get_val("Введите номер студента из основного списка.\n", command);
            check(command);
            int num;
            try {
                num = std::stoi(command);
            } catch (std::invalid_argument) {
                std::cout << "Не правильный формат ввода \n";
                continue;
            }
            if (mainStudentContainer.students.size() <= num) {
                std::cout << "Такого студента нет.\n";
                continue;
            }
            check(command);
            get_val("Введите параметр.\n", command);
            check(command);

            if (command == "FIO") {
                get_val("Введите новый параметр.\n", command);
                check(command);
                errorCode = mainStudentContainer.students[num]->setFullName(command);
            } else if (command == "DOB") {
                get_val("Введите новый параметр.\n", command);
                check(command);
                errorCode = mainStudentContainer.students[num]->setDayOfBirth(command);

            } else if (command == "YFE") {
                get_val("Введите новый параметр.\n", command);
                check(command);
                errorCode = mainStudentContainer.students[num]->setYearOfEntering(std::stoi(command));
            } else if (command == "RBN") {
                get_val("Введите новый параметр.\n", command);
                check(command);
                errorCode = mainStudentContainer.students[num]->setRecordBookNumber(command);
            } else if (command == "Sex") {
                bool sex;
                bool is_error = true;
                get_val("Введите новый параметр\n", command);
                if (command == "Муж.") {
                    sex = true;
                    is_error = false;
                } else if (command == "Жен.") {
                    sex = false;
                    is_error = false;
                } else {
                    std::cout << "Не коректный ввод";
                    continue;
                }
                errorCode = mainStudentContainer.students[num]->setIsMale(sex);
            } else if (command == "Group") {
                get_val("Введите новый параметр.\n", command);
                check(command);
                errorCode = mainStudentContainer.students[num]->setGroup(command);
            } else if (command == "Faculty") {
                get_val("Введите новый параметр.\n", command);
                check(command);
                errorCode = mainStudentContainer.students[num]->setFaculty(command);


            } else if (command == "Session") {
                get_val("Введите номер сессии\n", command);
                check(command);
                int session_num;
                if (command.find(".") != -1)
                    std::cout << "Не правильный формат ввода\n";
                try {
                    session_num = std::stoi(command);
                } catch (std::invalid_argument) {
                    std::cout << "Не правильный формат ввода \n";
                    continue;
                }
                std::string sub;
                get_val("Введите название предмета\n", sub);
                check(sub);

                get_val("Введите новую оценку\n", command);

                if (command.empty()) {
                    mainStudentContainer.students[num]->sessions.deleteSession(session_num, sub);

                } else {
                    int grade;
                    if (command.find(".") != -1)
                        std::cout << "Не правильный формат ввода\n";
                    try {
                        grade = std::stoi(command);
                    } catch (std::invalid_argument) {
                        std::cout << "Не правильный формат ввода \n";
                        continue;
                    }

                    errorCode = mainStudentContainer.students[num]->sessions.editSession(session_num, sub, grade);


                }


            } else
                std::cout << "Параметр не найден.\n";

            if (errorCode != OK) {
                std::cout << "Ошибка ввода\n";
                continue;
            }

            std::cout << "Выполнено\n";



        } else if (command == "findS") {


            std::cout << "Введите название листа\n";
            getline(std::cin, command
            );

            std::string req;
            std::cout << "Введите запрос\n";
            getline(std::cin, req
            );

            containers.
                            find(command)
                    ->second->
                            FindStudents(req);


        } else if (command == "print") {
            std::cout << "Введите название списка\n";
            std::cout << "Для вывода всех студентов введите пустую строку.\n";
            getline(std::cin, command
            );
            if (command.

                    empty()

                    ) {
                std::cout <<
                          mainStudentContainer;
            } else {
                auto find = containers.find(command);
                if (find == containers.

                        end()

                        ) {
                    std::cout << "Такого списка нет.";
                } else {
                    StudentsContainer sc = *find->second;
                    std::cout <<
                              sc;
                }
            }


        } else if (command == "quit") {
            is_need_exit = true;
        } else {
            std::cout << "Команда не найдена.\n";
        }

        std::cout <<
                  std::endl;




/*
        "      Ф.И.О. студента.            FIO     = str;\n"
        "      Число, месяц, год рождения. DOB     = DD.MM.YYYY;\n"
        "      Год поступления в институт. YFE     = YYYY;\n"
        "      Факультет, кафедра.         Faculty = str;\n"
        "      Группа.                     Group   = str;\n"
        "      Номер зачетной книжки.      RBN     = str;\n"
        "      Пол                         Sex     = Муж. ИЛИ Жен.;"*/


    }


    mainStudentContainer.
            save(path);


    return 0;
}
