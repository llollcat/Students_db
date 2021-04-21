//
// Created by tiramisu on 30.03.2021.
//

#ifndef UNTITLED_STUDENTSCONTAINER_H
#define UNTITLED_STUDENTSCONTAINER_H

#include "vector"

class Student;

class StudentsContainer {
protected:


    std::vector<Student *> expression_analyzer(std::string expression, const std::vector<Student *> &students_vector) {
        bool is_not = false;
        if (expression.substr(0, 1) == "!") {
            is_not = true;
        }
        expression = expression.substr(1, expression.size());

        int start = 0, end = 0;
        std::vector<Student *> *out = new std::vector<Student *>;
        while (expression[start] == ' ')
            ++start;



#define find_start_and_end_value(len) { bool is_met_equal_char = false; \
            start += len-1;\
            while ((start < expression.length()) && ((expression[start+1] == ' ') || (!is_met_equal_char))) {\
                if (expression[start+1]=='=') {\
                    is_met_equal_char = true;\
                }\
                ++start; }                                                  \
            ++start;                                                                \
            end =expression.size()-1; \
            while (expression[end] == ' ') --end; }


#define do_iteration_and_return(condition)   {              for (const auto &item : students_vector) { \
            if ((is_not) &&(!(condition))&& (item->id !=-1))    {                                                                            \
                        out->push_back(item);                                                                               \
                            }                                                                           \
            \
            else if ((!is_not)&&(condition)&& (item->id !=-1)) \
                out->push_back(item); \
        } \
        return *out;}


        if (expression.length() > 3) {
            if (expression.substr(start, 3) == "FIO") {
                find_start_and_end_value(3);
                do_iteration_and_return(item->full_name == expression.substr(start, end - start + 1));


            }
            if (expression.substr(start, 3) == "DOB") {
                find_start_and_end_value(3);
                do_iteration_and_return(
                        item->day_of_birth.getStringDate() == (expression.substr(start, end - start + 1)));

            }
            if (expression.substr(start, 3) == "YFE") {
                find_start_and_end_value(3);
                do_iteration_and_return(
                        std::to_string(item->year_of_entering) == (expression.substr(start, end - start + 1)));


            }
            if (expression.substr(start, 3) == "RBN") {
                find_start_and_end_value(3);
                do_iteration_and_return(item->record_book_number == (expression.substr(start, end - start + 1)));

            }
            if (expression.substr(start, 3) == "Sex") {
                find_start_and_end_value(3);
                do_iteration_and_return(expression.substr(start, end - start + 1) == item->getIsMale())


            }
        }
        if ((expression.length() > 4) && (expression.substr(start, 4) == "SNum")) {
            find_start_and_end_value(4);
            int snum;
            try {
                snum = std::stoi(expression.substr(start, end - start + 1));
            } catch (std::invalid_argument) {
                std::cout << "Не правильный формат ввода \n";
                return *out;
            }
            std::cout << "Введите название предмета\n";
            std::string subj;
            std::cin >> subj;

            std::cout << "Введите оценку\n";
            std::string temp;
            std::cin >> temp;
            int grade;
            try {
                grade = std::stoi(temp);
            } catch (std::invalid_argument) {
                std::cout << "Не правильный формат ввода \n";
                return *out;
            }

            do_iteration_and_return(item->sessions.getVectorOfSessions()[snum - 1].find(subj)->second == grade);


        }
        if ((expression.length() > 5) && (expression.substr(start, 5) == "Group")) {
            find_start_and_end_value(5);
            do_iteration_and_return(item->group == (expression.substr(start, end - start + 1)))

        }
        if ((expression.length() > 7) && (expression.substr(start, 7) == "Faculty")) {
            find_start_and_end_value(7);
            do_iteration_and_return(item->faculty == (expression.substr(start, end - start + 1)))
        } else {
            std::cout << "Ошибка запроса\n";
            return students_vector;
        }
    }


public:
    std::vector<Student *> students;


    virtual void *FindStudents(const std::string &request) {


        this->students = this->expression_analyzer(request, this->students);
    }


    // copy constructor
    StudentsContainer(const StudentsContainer &sc) {

        students = sc.students;

    }


    friend std::ostream &operator<<(std::ostream &out, StudentsContainer &studentsManager);

    StudentsContainer() = default;


private:
    int getStudentId(const Student &student) {
        return student.id;
    }


};


std::ostream &operator<<(std::ostream &out, StudentsContainer &studentsManager) {

    for (auto &item: studentsManager.students) {
        if (studentsManager.getStudentId(*item) != -1)
            out << *item;
    }

    return out;
}


#endif //UNTITLED_STUDENTSCONTAINER_H
