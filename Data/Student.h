#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H

#include <utility>
#include "string"
#include "vector"
#include <fstream>
#include "../Savable.h"

class StudentsContainer;

class MainStudentContainer;


class Student final : public Human, public Savable {
protected:


    friend StudentsContainer;
    int _year_of_entering{};
    std::string _faculty;
    std::string _group;
    std::string _record_book_number;
    int _id{};
public:
    SessionsContainer sessions;


    friend StudentsContainer;
    friend MainStudentContainer;

    [[nodiscard]] virtual std::string getYearOfEntering() const final {
        return std::to_string(this->_year_of_entering);
    }

    virtual ERROR_CODES setYearOfEntering(int year_of_entering) final {
        if (year_of_entering < 0)
            return YEAR_ERROR;
        this->_year_of_entering = year_of_entering;
        return OK;
    }

    [[nodiscard]] virtual const std::string &getFaculty() const final {
        return this->_faculty;
    }

    virtual ERROR_CODES setFaculty(const std::string &faculty) final {
        this->Student::_faculty = faculty;
        return OK;
    }

    [[nodiscard]] virtual const std::string &getGroup() const final {
        return this->_group;
    }

    virtual ERROR_CODES setGroup(const std::string &group) final {
        this->Student::_group = group;
        return OK;
    }

    [[nodiscard]] virtual const std::string &getRecordBookNumber() const final {
        return this->_record_book_number;
    }

    virtual ERROR_CODES setRecordBookNumber(const std::string &record_book_number) final {
        this->_record_book_number = record_book_number;
        return OK;
    }


    explicit Student() : Human() {
        this->sessions = SessionsContainer();
    };

    explicit Student(int year_of_entering, std::string faculty, std::string group, std::string record_book_number,
                     int day, int month, int year, const std::string &full_name, bool is_male) :
            Human(day, month, year, full_name, is_male) {
        this->_year_of_entering = year_of_entering;
        this->_faculty = std::move(faculty);
        this->_group = std::move(group);
        this->_record_book_number = std::move(record_book_number);
        this->sessions = SessionsContainer();


    }

    explicit Student(int year_of_entering, std::string faculty, std::string group, std::string record_book_number,
                     const Date &date, const std::string &full_name, bool is_male, SessionsContainer sessionsContainer)
            :
            Human(date, full_name, is_male) {
        this->_year_of_entering = year_of_entering;
        this->_faculty = std::move(faculty);
        this->_group = std::move(group);
        this->_record_book_number = std::move(record_book_number);
        this->sessions = std::move(sessionsContainer);


    }


    ERROR_CODES save(std::string filename) override {

        std::ofstream file(filename);
        if (this->_id == -1) {
            return NOT_SAVED;
        }
        if (!file) {
            // то выводим сообщение об ошибке и выполняем функцию exit()
            std::cerr << "Не возможно открыть файл \"" << filename << "\"" << std::endl;
            exit(FILE_ERROR);
        }


        file << full_name << std::endl << _year_of_entering << std::endl << _faculty << std::endl << _group << std::endl
             << _record_book_number << std::endl;
        file << _id << std::endl << is_male << std::endl;
        file << day_of_birth._day << std::endl << day_of_birth._month << std::endl << day_of_birth._year << std::endl;


        for (const auto &item: sessions.getVectorOfSessions()) {
            file << '_' << std::endl;
            for (const auto &item1: item) {
                file << item1.first << std::endl;
                file << item1.second << std::endl;
            }
        }

        file.close();
        return OK;

    };


    ERROR_CODES load(std::string filename, bool is_need_return_error) override {
        std::ifstream in_file(filename);
        if (!in_file) {
            if (is_need_return_error)
                return FILE_ERROR;
            std::cerr << "Файл \"" << filename << "\" Не может быть найден" << std::endl;
            exit(FILE_ERROR);
        }

        getline(in_file, full_name);
        in_file >> _year_of_entering >> _faculty >> _group >> _record_book_number >> _id;
        in_file >> is_male;

        in_file >> day_of_birth._day >> day_of_birth._month >> day_of_birth._year;


        int counter = 0;
        bool is_set_second = false;
        std::string temp;
        while (in_file) {
            std::string strInput;
            in_file >> strInput;
            if (strInput == "_") {
                ++counter;
                is_set_second = false;
                continue;
            }
            if (!is_set_second) {
                temp = strInput;
                is_set_second = true;
                continue;
            }

            sessions.addSession(counter, temp, std::stoi(strInput));
            is_set_second = false;


        }
        in_file.close();
        return OK;
    };


    friend std::ostream &operator<<(std::ostream &out, Student &student);


};
// добавление возможности вывода через std::cout<<

std::ostream &operator<<(std::ostream &out, Student &student) {
#define sep "; "
    out << "ID в основном списке: " << student._id << sep << "ФИО: " << student.full_name << sep << "Факультет: "
        << student._faculty << sep;
    out << "Группа: " << student._group << sep << "Номер зачётной книжки: " << student._record_book_number << sep;
    out << "Год поступления: " << student._year_of_entering << sep << "Пол: " << student.getIsMale() << sep;
    out << "Дата рождения: " << student.day_of_birth.getStringDate() << sep;

    out << std::endl << "Сессии:" << std::endl;
    bool number_of_session_was_outed = false;
    int counter = 1;
    bool is_worked = false;
    for (const auto &item: student.sessions.getVectorOfSessions()) {
        for (const auto &item1: item) {
            is_worked = true;
            if (!number_of_session_was_outed) {
                out << counter << " семестр:" << std::endl;
                number_of_session_was_outed = true;
            }
            out << "   " << item1.first << ": " << item1.second << std::endl;
        }
        number_of_session_was_outed = false;
        ++counter;
    }
    if (!is_worked) {
        std::cout << "   Нет данных.";

    }
    out << std::endl;

    return out;
}


#endif
