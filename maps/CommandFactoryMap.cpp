//
// Created by cs on 12/18/18.
//

#include "CommandFactoryMap.h"

const map<string, Expression *> &CommandFactoryMap::getCommandsFactoryMap() const {
    return commandsMap;
}
