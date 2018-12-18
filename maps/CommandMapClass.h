//
// Created by tamir on 17/12/18.
//

#ifndef INC_14_12_12_46_COMMANDMAPCLASS_H
#define INC_14_12_12_46_COMMANDMAPCLASS_H


#include <string>
#include <map>
#include "../expression/Expression.h"

using namespace std;

class CommandMapClass {
private:
    map<string, Expression*> commandsMap;

public:
    CommandMapClass () = default;

    const map<string, Expression*> &getCommandsMap() const;
};


#endif //INC_14_12_12_46_COMMANDMAPCLASS_H
