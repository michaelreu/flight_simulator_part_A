//
// Created by cs on 12/18/18.
//

#ifndef INC_14_12_12_46_CONDITIONPARSER_H
#define INC_14_12_12_46_CONDITIONPARSER_H

#define  START_OF_STR 0
#define TRUE 1


#include "../commands/Command.h"
#include <string>
#include <vector>
#include "../maps/SymbolTable.h"
#include "../Utils.h"
#include "../factory/ExpressionFactory.h"

using namespace std;

class ConditionParser : public Command {
private:
    vector<Expression*> vecOfExpCommands;
    ExpressionFactory* expressionFactory;
    string condition;
    string boolOperator;
    Utils utils;

    bool isValidCondition();

public:
    ConditionParser(vector <Expression*> &vecOfExp, string &con,ExpressionFactory* expFac);

    vector<Expression*> &getVecOfExpCommands();
    bool checkCondition();
    virtual void execute() = 0;
    ~ConditionParser();

};


#endif //INC_14_12_12_46_CONDITIONPARSER_H
