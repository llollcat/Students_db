#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-throw-by-value-catch-by-reference"


#include <iostream>

std::string PASSWD;


#include "ERROR_CODES.h"
#include "Data/SessionsContainer.h"
#include "Data/Date.h"
#include "Data/Human.h"
#include "Data/Student.h"
#include "Data/StudentsContainer.h"
#include "Data/MainStudentContainer.h"
#include "generate_student.h"


#define new_pair(str, SC) std::pair<std::string, StudentsContainer *>(str, SC)

#define get_val(out, input_val)   std::cout << out << std::endl;   getline(std::cin, input_val); std::cout << std::endl

#define check(input_val) if ((input_val.find('\n') !=-1) ||(input_val.find('_')!=-1) || (input_val.empty()))  \
{ std::cout << "Встречены запрещённые символы или пустая строка.\n"; continue;}


int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned int>(time(0)));

    std::map<std::string, StudentsContainer *> containers;

    MainStudentContainer mainStudentContainer = MainStudentContainer();

    bool is_need_load = true;
    if (argc > 1) {
        for (int i = 0; i < argc; ++i) {
            if (strcmp(argv[i], "-generate") == 0) {
                is_need_load = false;
                for (int i2 = 0; i2 < std::stoi(argv[i + 1]); ++i2) {
                    mainStudentContainer.NewStudent(generate_student());

                }
                ++i;


            }

        }
    }


    std::string path = "st";


    std::cout << "Введите пароль для шифрования." << std::endl;
    std::getline(std::cin, PASSWD);


    if (is_need_load)
        mainStudentContainer.load(path);


    std::cout << "help для вывода списка команд.\n";
    bool is_need_exit = false;
    while (!is_need_exit) {
        std::string command;
        getline(std::cin, command);

        if (command == "help") {
            std::cout << "Использование:\n"
                         "  Новый список                     newL\n"
                         "  Удалить список                   delL\n"
                         "  Добавить студента                addS\n"
                         "  Удалить студента                 delS\n"
                         "  Отфильтровать список студентов   findS\n"
                         "  Отредактировать запись           editS\n"
                         "  Отсортировать список             sortLbyGrade\n"
                         "  Вывести список                   print\n"
                         "  Завершить программу              quit\n";

        } else if (command == "newL") {
            std::cout << "Введите назвение списка\n";
            getline(std::cin, command);
            check(command)

            // обрезка класса безопасна
            auto *sc = new StudentsContainer(mainStudentContainer); // NOLINT(cppcoreguidelines-slicing)


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
                std::cout << "Ошибка\n";
            }

        } else if (command == "addS") {


            std::string name, faculty, group, re_bo_num;
            bool sex;
            int yoe;

            get_val("ФИО", name);
            check(name)
            get_val("Факультет", faculty);
            check(faculty)
            get_val("Группа", group);
            check(group)
            get_val("Номер зачётной книжки", re_bo_num);
            check(re_bo_num)

            get_val("Год поступления", command);
            check(command)
            if (command.find('.') != -1)
                std::cout << "Не правильный формат ввода даты\n";
            try {
                yoe = std::stoi(command);
            } catch (std::invalid_argument) {
                std::cout << "Не правильный формат ввода даты\n";
                continue;
            }

            get_val("Пол", command);
            if (command == "Муж.") {
                sex = true;
            } else if (command == "Жен.") {
                sex = false;
            } else {
                std::cout << "Не коректный ввод";
                continue;
            }


            get_val("Дата рождения", command);
            check(command)
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
                if (command.find('.') != -1)
                    std::cout << "Не правильный формат ввода номера\n";
                try {
                    session_number = std::stoi(command);
                } catch (std::invalid_argument) {
                    std::cout << "Не правильный формат ввода номера\n";
                    continue;
                }


                std::string subject, grade;

                get_val("Введите название предмета", subject);
                check(subject)
                get_val("Введите оценку", grade);
                check(grade)

                int session_grade;
                if (command.find('.') != -1)
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
            check(command)
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
            check(command)
            get_val("Введите параметр.\n", command);
            check(command)

            if (command == "FIO") {
                get_val("Введите новый параметр.\n", command);
                check(command)
                errorCode = mainStudentContainer.students[num]->setFullName(command);
            } else if (command == "DOB") {
                get_val("Введите новый параметр.\n", command);
                check(command)
                errorCode = mainStudentContainer.students[num]->setDayOfBirth(command);

            } else if (command == "YFE") {
                get_val("Введите новый параметр.\n", command);
                check(command)
                errorCode = mainStudentContainer.students[num]->setYearOfEntering(std::stoi(command));
            } else if (command == "RBN") {
                get_val("Введите новый параметр.\n", command);
                check(command)
                errorCode = mainStudentContainer.students[num]->setRecordBookNumber(command);
            } else if (command == "Sex") {
                bool sex;
                get_val("Введите новый параметр\n", command);
                if (command == "Муж.") {
                    sex = true;
                } else if (command == "Жен.") {
                    sex = false;
                } else {
                    std::cout << "Не коректный ввод";
                    continue;
                }
                errorCode = mainStudentContainer.students[num]->setIsMale(sex);
            } else if (command == "Group") {
                get_val("Введите новый параметр.\n", command);
                check(command)
                errorCode = mainStudentContainer.students[num]->setGroup(command);
            } else if (command == "Faculty") {
                get_val("Введите новый параметр.\n", command);
                check(command)
                errorCode = mainStudentContainer.students[num]->setFaculty(command);


            } else if (command == "Session") {
                get_val("Введите номер сессии\n", command);
                check(command)
                int session_num;
                if (command.find('.') != -1)
                    std::cout << "Не правильный формат ввода\n";
                try {
                    session_num = std::stoi(command);
                } catch (std::invalid_argument) {
                    std::cout << "Не правильный формат ввода \n";
                    continue;
                }
                std::string sub;
                get_val("Введите название предмета\n", sub);
                check(sub)

                get_val("Введите новую оценку\n", command);

                if (command.empty()) {
                    mainStudentContainer.students[num]->sessions.deleteSession(session_num, sub);

                } else {
                    int grade;
                    if (command.find('.') != -1)
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


        } else if(command == "sortLbyGrade"){
            std::cout << "Введите название листа\n";
            getline(std::cin, command);
            if (containers.find(command) == containers.end()) {
                std::cout << "Такого списка нет.\n";
                continue;
            }

            containers.find(command)->second->SortStudentsByGrade();







        } else if (command == "findS") {


            std::cout << "Введите название листа\n";
            getline(std::cin, command);
            if (containers.find(command) == containers.end()) {
                std::cout << "Такого списка нет.\n";
                continue;
            }

            std::string req;
            std::cout << "Введите запрос\n";
            getline(std::cin, req);

            containers.find(command)->second->FindStudents(req);


        } else if (command == "print") {
            std::cout << "Введите название списка\n";
            std::cout << "Для вывода всех студентов введите пустую строку.\n";
            getline(std::cin, command);
            if (command.empty()) {
                std::cout << mainStudentContainer;
            } else {
                auto find = containers.find(command);
                if (find == containers.end()) {
                    std::cout << "Такого списка нет.";
                } else {
                    StudentsContainer sc = *find->second;
                    std::cout << sc;
                }
            }


        } else if (command == "quit") {
            is_need_exit = true;
        } else {
            std::cout << "Команда не найдена.\n";
        }

        std::cout << std::endl;
    }


    mainStudentContainer.save(path);


    return 0;
}