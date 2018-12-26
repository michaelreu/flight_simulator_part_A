//
// Created by cs on 12/13/18.
//

#ifndef PROJECTPART1_COMMAND_H
#define PROJECTPART1_COMMAND_H

#include "../expression/Expression.h"
#include "../maps/SymbolTable.h"
#include <chrono>
#include <thread>
#define SLEEP_TIME 300

class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};


#endif //PROJECTPART1_COMMAND_H
