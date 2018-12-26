//
// Created by cs on 12/18/18.
//

#ifndef INC_14_12_12_46_CONDITIONPARSER_H
#define INC_14_12_12_46_CONDITIONPARSER_H

#define  START_STR 0
#define TRUE 1
#define EQUAL_STR "=="
#define GREATER_EQUAL_STR  ">="
#define LESS_EQUAL_STR "<="
#define NOT_EQUAL_STR "!="
#define GREATER_STR ">"
#define LESS_STR "<"

#include "../commands/Command.h"
#include "../expression/booleanExpressions/Equal.h"
#include "../expression/booleanExpressions/GreaterThen.h"
#include "../expression/booleanExpressions/LessThen.h"

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
    virtual ~ConditionParser();

};


#endif //INC_14_12_12_46_CONDITIONPARSER_H
