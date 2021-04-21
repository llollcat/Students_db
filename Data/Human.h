#ifndef UNTITLED_HUMAN_H
#define UNTITLED_HUMAN_H

#include "string"


class Human {

protected:
    Date day_of_birth;
    std::string full_name;
    bool is_male{};


public:
    virtual Date getDayOfBirth() const final {
        return Date(this->day_of_birth);
    }

    virtual ERROR_CODES setDayOfBirth(int day, int month, int year) final {
        Date temp_day_of_birth = Date();
        ERROR_CODES error = temp_day_of_birth.setDate(day, month, year);
        if (error == OK) {
            this->day_of_birth = temp_day_of_birth;
        }
        return error;
    }
    virtual ERROR_CODES setDayOfBirth(std::string date_str) final {
        Date temp_day_of_birth = Date();
        ERROR_CODES error = temp_day_of_birth.setDate(date_str);
        if (error == OK) {
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

    virtual std::string getIsMale() const final {
        if (this->is_male)
            return "Муж.";
        return "Жен.";
    }

    virtual ERROR_CODES setIsMale(bool isMale) final {
        this->is_male = isMale;
        return OK;
    }


private:
    Human(const std::string &full_name, bool is_male) {
        this->setFullName(full_name);
        this->setIsMale(is_male);
    }

protected:
    Human(){
        this->day_of_birth = Date();
    };


public:


    Human(int day, int month, int year, const std::string &full_name, bool is_male) : Human(full_name,
                                                                                                        is_male) {
        this->setDayOfBirth(day, month, year);


    }

    Human(const Date &date, const std::string &full_name, bool is_male) : Human(full_name, is_male) {
        this->day_of_birth = Date(date);

    }


};


#endif //UNTITLED_HUMAN_H
