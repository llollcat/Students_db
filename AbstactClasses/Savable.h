//
// Created by tiramisu on 30.03.2021.
//

#ifndef UNTITLED_SAVABLE_H
#define UNTITLED_SAVABLE_H

#include "vector"


class Savable {

public:
    virtual ERROR_CODES save(std::string filename) = 0;

   virtual ERROR_CODES load(std::string filename, bool is_need_return_error = false) = 0;


};


#endif //UNTITLED_SAVABLE_H
