

#ifndef INC_14_12_12_46_WHILECONDITION_H
#define INC_14_12_12_46_WHILECONDITION_H

#include "ConditionParser.h"
#include "../commands/ExpressionCommand.h"
#include <vector>


using namespace std;

class WhileCommand : public  ConditionParser{
private:
    vector<Expression*> vecOfExpCommands;
    SymbolTable *symTbl;
    string condition;

public:
    WhileCommand(vector <Expression*> &vecOfExp, string &con, SymbolTable* &symbolTable);
    string getCondition();
    virtual void execute();
};


#endif //INC_14_12_12_46_WHILECONDITION_H

