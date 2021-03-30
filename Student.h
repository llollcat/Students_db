

#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H

#include "string"
#include "Human.h"
#include "vector"
class Student final : public Human {
protected:
    int32_t year_of_entering;
    std::string faculty;
    std::string group;
    std::string record_book_number;


public:
    std::vector<std::vector<std::string>> sessions;


    virtual int32_t getYearOfEntering() const final{
        return this->year_of_entering;
    }

    virtual ERROR_CODES setYearOfEntering(int32_t year_of_entering) final{
        this->year_of_entering = year_of_entering;
        return OK;
    }

    virtual const std::string &getFaculty() const final{
        return this->faculty;
    }

    virtual ERROR_CODES setFaculty(const std::string &faculty) final{
        this->Student::faculty = faculty;
        return OK;
    }

    virtual const std::string &getGroup() const final{
        return this->group;
    }

    virtual ERROR_CODES setGroup(const std::string &group) final{
        this->Student::group = group;
        return OK;
    }

    virtual const std::string &getRecordBookNumber() const final{
        return this->record_book_number;
    }

    virtual ERROR_CODES setRecordBookNumber(const std::string &record_book_number) final{
        this->record_book_number = record_book_number;
        return OK;
    }


    Student() = delete;

    explicit Student(int32_t year_of_entering, std::string faculty, std::string group, std::string record_book_number,
                     int32_t day, int32_t month, int32_t year, std::string full_name, bool is_male) :Human(day, month, year, std::move(full_name), is_male) {
        this->year_of_entering = year_of_entering;
        this->faculty = faculty;
        this->group = group;
        this->record_book_number = record_book_number;

    }

    explicit Student(int32_t year_of_entering, std::string faculty, std::string group, std::string record_book_number, const Date &date, const std::string &full_name, bool is_male) :
            Human(date, full_name, is_male) {
        this->year_of_entering = year_of_entering;
        this->faculty = faculty;
        this->group = group;
        this->record_book_number = record_book_number;


    }


};


#endif
