//
// Created by cs on 12/18/18.
//

#ifndef INC_14_12_12_46_IFCONDITION_H
#define INC_14_12_12_46_IFCONDITION_H

#include "ConditionParser.h"
#include <vector>
#include "ExpressionCommand.h"

using namespace std;

class IfCondition : public  ConditionParser{
private:
    vector<ExpressionCommand> vecOfExpressionCommands;
    SymbolTable *symbolTable;
    string condition;
public:
    void addExpressionCommand(ExpressionCommand command);
    void setSymbolTable(SymbolTable &symbolTable1);
    IfCondition(vector <ExpressionCommand> vecOfExpressionCommands, string condition);
    virtual void execute();
    string getCondition();
};


#endif //INC_14_12_12_46_IFCONDITION_H
