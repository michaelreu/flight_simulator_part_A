
#ifndef INC_14_12_12_46_IFCONDITION_H
#define INC_14_12_12_46_IFCONDITION_H

#include "ConditionParser.h"
#include "../commands/ExpressionCommand.h"
#include <vector>


using namespace std;

class IfCommand : public  ConditionParser {
/*
private:
    vector<Expression*> vecOfExpCommands;
    SymbolTable *symTbl;
    string condition;
*/
public:
    //void addExpressionCommand(ExpressionCommand command);
    //void setSymbolTable(SymbolTable &symbolTable1);
    IfCommand(vector <Expression*> &vecOfExp, string &con, ExpressionFactory* expFac);
    virtual void execute();
    string getCondition();
};


#endif //INC_14_12_12_46_IFCONDITION_H
