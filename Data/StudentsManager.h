//
// Created by tiramisu on 30.03.2021.
//

#ifndef UNTITLED_STUDENTSMANAGER_H
#define UNTITLED_STUDENTSMANAGER_H

#include "vector"

class Student;

class StudentsManager {
private:
    int32_t student_counter = 0;


    typedef std::vector<Student *> &vector_in_dynamic_memory;

    vector_in_dynamic_memory
    expression_analyzer(std::string expression, const std::vector<Student *> &students_vector) {
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
            end =start; \
            while ((end < expression.size()-1)&& expression[end+1] !=' ') ++end; }


        #define do_iteration_and_return(condition)   {              for (const auto &item : students_vector) { \
            if (condition) \
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
        if ((expression.length() > 5) && (expression.substr(start, 5) == "Group")) {
            find_start_and_end_value(5);
            do_iteration_and_return(item->group == (expression.substr(start, end - start + 1)));

        }
        if ((expression.length() > 7) && (expression.substr(start, 7) == "Faculty")) {
            find_start_and_end_value(5);
            do_iteration_and_return(item->faculty == (expression.substr(start, end - start + 1)))
        }

        return *out;
    }


public:
    std::vector<Student *> students;

    ERROR_CODES NewStudent(Student *student) {
        student->id = student_counter;
        ++student_counter;
        this->students.push_back(student);
        return OK;
    }


    typedef std::vector<int32_t> students_ids;


    vector_in_dynamic_memory FindStudents(const std::string &request) {
        /* Использование
         * 1) Ф.И.О. студента. -          FIO     = str;
         * 2) Число, месяц, год рождения. DOB     = DD.MM.YYYY;
         * 3) Год поступления в институт. YFE     = YYYY;
         * 4) Факультет, кафедра.         Faculty = str;
         * 5) Группа.                     Group   = str;
         * 6) Номер зачетной книжки.      RBN     = str;
         * 7) Пол                         Sex     = Male || Female;*/




        return this->expression_analyzer(request, this->students);


    }


    ERROR_CODES DeleteStudent(std::vector<Student *> &vector) {
        bool is_find = false;

        auto iter_in_students = this->students.begin();
        for (const auto &iter_in_vector : vector) {
            while (iter_in_students != this->students.end()) {
                if (*iter_in_students == iter_in_vector) {
                    this->students.erase(iter_in_students);
                    is_find = true;
                    break;
                } else
                    ++iter_in_students;

            }

            if (!is_find)
                return NOTHING_FIND;
            return OK;

        }


    };













    ~StudentsManager() {
        for (const auto &item : this->students) {
            delete item;
        }


    }

};

#endif //UNTITLED_STUDENTSMANAGER_H
