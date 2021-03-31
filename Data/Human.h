#ifndef UNTITLED_HUMAN_H
#define UNTITLED_HUMAN_H

#include "string"
#include "../ERROR_CODES.h"
#include "Date.h"
#include "../IO/DataKeeper.h"
class Human{

protected:
    Date day_of_birth;
    std::string full_name;
    bool is_male;


public:
    virtual Date getDayOfBirth() const final {
        return Date(this->day_of_birth);
    }
    virtual ERROR_CODES setDayOfBirth(int32_t day, int32_t month, int32_t year) final {
        Date temp_day_of_birth = Date();
        ERROR_CODES error = temp_day_of_birth.setDate(day,month,year);
        if (error==OK) {
            this->day_of_birth = temp_day_of_birth;
        }
        return error;
    }

    virtual std::string getFullName() const final {
        return this->full_name;
    }
    ERROR_CODES setFullName(const std::string &fullName) {
        this->full_name = fullName;
        return OK;
    }

    virtual bool isMale() const final{
        return this->is_male;
    }
    virtual ERROR_CODES setIsMale(bool isMale) final {
        this->is_male = isMale;
        return OK;
    }




private:
    Human(const std::string& full_name, bool is_male) {
        this->setFullName(full_name);
        this->setIsMale(is_male);
    }

public:
    Human(int32_t day, int32_t month, int32_t year, const std::string& full_name, bool is_male): Human(full_name, is_male) {
        this->setDayOfBirth(day, month, year );


    }
    Human(const Date& date, const std::string& full_name, bool is_male): Human(full_name, is_male) {
        this->day_of_birth = Date(date);

    }



};


#endif //UNTITLED_HUMAN_H
