#ifndef UNTITLED_DATE_H
#define UNTITLED_DATE_H


#include "../ERROR_CODES.h"

class Date final {
private:
    bool is_setted = false;
    int32_t day{};
    int32_t month{};
    int32_t year{};


    bool is_leap_year(int32_t year) const {
        if (year % 400 == 0)
            return true;
        if (year % 100 == 0)
            return false;
        if (year % 4 == 0)
            return true;
    }



public:

    ERROR_CODES setDate(int32_t day, int32_t month, int32_t year) {
    #define set_values this->day=day;this->month = month;this->year = year; this->is_setted = true;return OK;

        if (year<0)
            return YEAR_ERROR;
        if ((month<1)||(month>12))
            return MONTH_ERROR;
        switch (month) {
            case 1:
                if ((1<=day) && (day<=31)) {
                    set_values
                }
                break;
            case 2:
                if ((1<=day) && (day<=28)) {
                    set_values
                }
                if (is_leap_year(year) && (day==29)) {
                    set_values
                }
                break;
            case 3:
                if ((1<=day) && (day<=31)) {
                    set_values
                }

                break;
            case 4:
                if ((1<=day) && (day<=30)) {
                    set_values
                }

                break;
            case 5:
                if ((1<=day) && (day<=31)) {
                    set_values
                }

                break;
            case 6:
                if ((1<=day) && (day<=30)) {
                    set_values
                }
                break;
            case 7:
                if ((1<=day) && (day<=31)) {
                    set_values
                }
                break;
            case 8:
                if ((1<=day) && (day<=31)) {
                    set_values
                }
                break;
            case 9:
                if ((1<=day) && (day<=30)) {
                    set_values
                }
                break;
            case 10:
                if ((1<=day) && (day<=31)) {
                    set_values
                }
                break;
            case 11:
                if ((1<=day) && (day<=30)) {
                    set_values
                }
                break;
            case 12:
                if ((1<=day) && (day<=31)) {
                    set_values
                }
                break;


            default:
                break;

        }

        return DAY_ERROR;

    }

    int32_t getDay() const {
        if (!this->is_setted)
            return NOT_SETTED;
        return day;
    }

    int32_t getMonth() const {
        if (!this->is_setted)
            return NOT_SETTED;
        return month;
    }

    int32_t getYear() const {
        if (!this->is_setted)
            return NOT_SETTED;
        return year;
    }



    // copy constructor
    Date(const Date &date): day(date.day), month(date.month), year(date.year) {}

    explicit Date(){};

    explicit Date(int32_t day, int32_t month, int32_t year){
        this->setDate(day,month,year);
    };
};


#endif
