

#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H

#include <utility>
#include "string"
#include "vector"
#include "../IO/AbstactClasses/Savable.h"

class StudentsManager;


class Student final : public Human, public Savable {
protected:


    friend StudentsManager;
    int32_t year_of_entering;
    std::string faculty;
    std::string group;
    std::string record_book_number;
    int32_t id;
    SessionsContainer sessions;
public:
    SessionsContainer &getSessions()  {
        return this->sessions;
    }


    friend StudentsManager;
    [[nodiscard]] virtual std::string getYearOfEntering() const final {
        return std::to_string(this->year_of_entering);
    }

    virtual ERROR_CODES setYearOfEntering(int32_t year_of_entering) final {
        if (year_of_entering < 0)
            return YEAR_ERROR;
        this->year_of_entering = year_of_entering;
        return OK;
    }

    [[nodiscard]] virtual const std::string &getFaculty() const final {
        return this->faculty;
    }

    virtual ERROR_CODES setFaculty(const std::string &faculty) final {
        this->Student::faculty = faculty;
        return OK;
    }

    [[nodiscard]] virtual const std::string &getGroup() const final {
        return this->group;
    }

    virtual ERROR_CODES setGroup(const std::string &group) final {
        this->Student::group = group;
        return OK;
    }

    [[nodiscard]] virtual const std::string &getRecordBookNumber() const final {
        return this->record_book_number;
    }

    virtual ERROR_CODES setRecordBookNumber(const std::string &record_book_number) final {
        this->record_book_number = record_book_number;
        return OK;
    }


    Student() = delete;

    explicit Student(int32_t year_of_entering, std::string faculty, std::string group, std::string record_book_number,
                     int32_t day, int32_t month, int32_t year, const std::string& full_name, bool is_male) :
                     Human(day, month, year,  full_name,is_male) {
        this->year_of_entering = year_of_entering;
        this->faculty = std::move(faculty);
        this->group = std::move(group);
        this->record_book_number = std::move(record_book_number);
        this->sessions = SessionsContainer();


    }

    explicit Student(int32_t year_of_entering, std::string faculty, std::string group, std::string record_book_number,
                     const Date &date, const std::string &full_name, bool is_male) :
            Human(date, full_name, is_male) {
        this->year_of_entering = year_of_entering;
        this->faculty = std::move(faculty);
        this->group = std::move(group);
        this->record_book_number = std::move(record_book_number);
        this->sessions = SessionsContainer();


    }




    virtual  const DataKeeper save(const DataKeeper &data_keeper) {};

    virtual const DataKeeper load(const DataKeeper &data_keeper) {};








};



#endif
