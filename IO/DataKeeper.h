//
// Created by tiramisu on 30.03.2021.
//

#ifndef UNTITLED_DATAKEEPER_H
#define UNTITLED_DATAKEEPER_H
#include "AbstactClasses/Savable.h"
class DataKeeper {


public:
    template<typename Savable_Object>
    ERROR_CODES SaveObj(const Savable_Object &obj) {
        return OK;
    }
    template<typename Savable_Object>
    ERROR_CODES LoadObj( Savable_Object &obj) {
        return OK;
    }


};


#endif //UNTITLED_DATAKEEPER_H
