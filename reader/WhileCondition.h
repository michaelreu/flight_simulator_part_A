

#ifndef INC_14_12_12_46_WHILECONDITION_H
#define INC_14_12_12_46_WHILECONDITION_H

#include "ConditionParser.h"
#include "ExpressionCommand.h"
#include <vector>


using namespace std;

class WhileCondition : public  ConditionParser{
private:

    vector<ExpressionCommand> vecOfExpressionCommands;
    SymbolTable *symbolTable;
    string condition;

public:

    WhileCondition(vector <ExpressionCommand>, string condition);
    void setSymbolTable(SymbolTable &symbolTable1);
    string getCondition();
    virtual void execute();
};


#endif //INC_14_12_12_46_WHILECONDITION_H

