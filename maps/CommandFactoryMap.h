//
// Created by cs on 12/18/18.
//

#ifndef INC_14_12_12_46_COMMANDFACTORYMAP_H
#define INC_14_12_12_46_COMMANDFACTORYMAP_H

#include <string>
#include <map>
#include "../expression/Expression.h"

using namespace std;

class CommandFactoryMap {
private:
    map<string, Expression*> commandsMap;

public:
    CommandFactoryMap () = default;

    const map<string, Expression *> &getCommandsFactoryMap() const;

};


#endif //INC_14_12_12_46_COMMANDFACTORYMAP_H
