#ifndef UNTITLED_SAVABLE_H
#define UNTITLED_SAVABLE_H


class Savable {

public:
    virtual ERROR_CODES save(std::string filename) = 0;

    virtual ERROR_CODES load(std::string filename, bool is_need_return_error = false) = 0;


};

#endif
