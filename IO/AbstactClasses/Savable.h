//
// Created by tiramisu on 30.03.2021.
//

#ifndef UNTITLED_SAVABLE_H
#define UNTITLED_SAVABLE_H

#include "../DataKeeper.h"

class Savable {

public:
    virtual const DataKeeper save(const DataKeeper &data_keeper) = 0;

    virtual const DataKeeper load>>(const DataKeeper &data_keeper) = 0;


};


#endif //UNTITLED_SAVABLE_H
