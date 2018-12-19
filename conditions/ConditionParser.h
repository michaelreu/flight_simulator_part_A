//
// Created by cs on 12/18/18.
//

#ifndef INC_14_12_12_46_CONDITIONPARSER_H
#define INC_14_12_12_46_CONDITIONPARSER_H


#include "../commands/Command.h"
#include <string>
#include "../maps/SymbolTable.h"

using namespace std;

class ConditionParser : public Command {

public:
    bool checkCondition(string condition, SymbolTable *symbolTable);
    virtual void execute() = 0;

};


#endif //INC_14_12_12_46_CONDITIONPARSER_H
