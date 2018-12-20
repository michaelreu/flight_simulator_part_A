//
// Created by cs on 12/18/18.
//

#ifndef INC_14_12_12_46_CONDITIONPARSER_H
#define INC_14_12_12_46_CONDITIONPARSER_H


#include "../commands/Command.h"
#include <string>
#include <vector>
#include "../maps/SymbolTable.h"

using namespace std;

class ConditionParser : public Command {
private:
    vector<Expression*> vecOfExpCommands;
    SymbolTable *symTbl;
    string condition;

public:
    ConditionParser(vector <Expression*> &vecOfExp, string &con, SymbolTable* &symbolTable);
    vector<Expression*> &getVecOfExpCommands();
    bool checkCondition();
    virtual void execute() = 0;

};


#endif //INC_14_12_12_46_CONDITIONPARSER_H
