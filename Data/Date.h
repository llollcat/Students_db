#ifndef UNTITLED_DATE_H
#define UNTITLED_DATE_H


class Student;

// котейнер даты.
class Date final {
private:
    bool is_setted = false;
    int _day{};
    int _month{};
    int _year{};


    [[nodiscard]] static bool is_leap_year(int year) {
        if (year % 400 == 0)
            return true;
        if (year % 100 == 0)
            return false;
        if (year % 4 == 0)
            return true;
        return false;
    }


public:
    friend Student;

    [[nodiscard]] std::string getStringDate() const {
        std::string out;

        for (int i = 0; i < 2 - std::to_string(_day).length(); ++i)
            out += '0';
        out += std::to_string(this->_day);
        out += '.';

        for (int i = 0; i < 2 - std::to_string(this->_month).length(); ++i)
            out += '0';
        out += std::to_string(this->_month);
        out += '.';


        for (int i = 0; i < 4 - std::to_string(this->_year).length(); ++i)
            out += '0';
        out += std::to_string(this->_year);

        return out;
    }


    ERROR_CODES setDate(int day, int month, int year) {
#define set_values this->_day= day;this->_month = month; this->_year = year; this->is_setted = true;return OK;

        if ((year < 0) || (year / 10'000 != 0))
            return YEAR_ERROR;
        if ((month < 1) || (month > 12))
            return MONTH_ERROR;
        switch (month) {
            case 1:
                if ((1 <= day) && (day <= 31)) {
                    set_values
                }
                break;
            case 2:
                if ((1 <= day) && (day <= 28)) {
                    set_values
                }
                if (is_leap_year(year) && (day == 29)) {
                    set_values
                }
                break;
            case 3:
                if ((1 <= day) && (day <= 31)) {
                    set_values
                }

                break;
            case 4:
                if ((1 <= day) && (day <= 30)) {
                    set_values
                }

                break;
            case 5:
                if ((1 <= day) && (day <= 31)) {
                    set_values
                }

                break;
            case 6:
                if ((1 <= day) && (day <= 30)) {
                    set_values
                }
                break;
            case 7:
            case 8:
                if ((1 <= day) && (day <= 31)) {
                    set_values
                }
                break;
            case 9:
                if ((1 <= day) && (day <= 30)) {
                    set_values
                }
                break;
            case 10:
                if ((1 <= day) && (day <= 31)) {
                    set_values
                }
                break;
            case 11:
                if ((1 <= day) && (day <= 30)) {
                    set_values
                }
                break;
            case 12:
                if ((1 <= day) && (day <= 31)) {
                    set_values
                }
                break;


            default:
                break;

        }

        return DAY_ERROR;

    }

    [[nodiscard]] int getDay() const {
        if (!this->is_setted)
            return NOT_SETTED;
        return _day;
    }

    [[nodiscard]] int getMonth() const {
        if (!this->is_setted)
            return NOT_SETTED;
        return _month;
    }

    [[nodiscard]] int getYear() const {
        if (!this->is_setted)
            return NOT_SETTED;
        return _year;
    }


    // контсруктор копирования.
    Date(const Date &date) : _day(date._day), _month(date._month), _year(date._year) {}

    explicit Date() = default;;

    // принимает дату в формате DD.MM.YYYY
    ERROR_CODES setDate(const std::string &date) {
        int temp[3];
        std::fill(std::begin(temp), std::end(temp), -1);

        int counter = 0;
        std::string temp1;

        for (const auto &item : date) {
            if (item == '.') {
                temp[counter] = std::stoi(temp1);
                ++counter;
                temp1.clear();
                continue;
            }
            temp1 += item;
        }
        temp[counter] = std::stoi(temp1);

        for (int i = 0; i < 3; ++i) {
            if (temp[i] == -1) {
                return ERROR_CODES(DAY_ERROR + i);
            }
        }

        return setDate(temp[0], temp[1], temp[2]);


    };

    explicit Date(int day, int month, int year) {
        this->setDate(day, month, year);
    };
};


#endif
