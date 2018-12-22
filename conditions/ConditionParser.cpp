//
// Created by cs on 12/18/18.
//

#include "ConditionParser.h"
#include "../expression/booleanExpressions/Equal.h"
#include "../expression/booleanExpressions/GreaterThen.h"
#include "../expression/booleanExpressions/LessThen.h"


ConditionParser::ConditionParser(vector<Expression *> &vecOfExp, string &con, ExpressionFactory* exprNumCreator) {
    //this->symTbl=symbolTable;
    this->expressionFactory = exprNumCreator;
    this->vecOfExpCommands = vecOfExp;
    this->condition = con;
    this->boolOperator = utils.getStringOfOperation(con);
}
vector<Expression*>& ConditionParser::getVecOfExpCommands() {
    return this->vecOfExpCommands;
}
bool ConditionParser::isValidCondition() {
    return (!boolOperator.empty());
}

bool ConditionParser::checkCondition() {
    if (!isValidCondition()) {
        return false;
    }
    string left = condition.substr(0,condition.find(boolOperator));
    string right = condition.substr(condition.find(boolOperator)+boolOperator.size(),condition.size());

    Expression* exp1;
    Expression* exp2;
    //can be 0 or 1 = false or true
    double result = 0;
    if (boolOperator=="==") {
        exp1 = new Equal(expressionFactory->createExpression(left), expressionFactory->createExpression(right));
        result = exp1->calculate();
    } else if (boolOperator==">=") {
        exp1 = new Equal(expressionFactory->createExpression(left), expressionFactory->createExpression(right));
        exp2 = new GreaterThen(expressionFactory->createExpression(left), expressionFactory->createExpression(right));
        result = (exp1->calculate() + exp2->calculate());
    } else if (boolOperator=="<=") {
        exp1 = new Equal(expressionFactory->createExpression(left), expressionFactory->createExpression(right));
        exp2 = new LessThen(expressionFactory->createExpression(left), expressionFactory->createExpression(right));
        result = (exp1->calculate() + exp2->calculate());
    } else if (boolOperator=="!=") {
        exp1 = new Equal(expressionFactory->createExpression(left), expressionFactory->createExpression(right));
        result = ((int)(exp1->calculate() + 1) % 2);
    } else if (boolOperator==">") {
        exp1 = new GreaterThen(expressionFactory->createExpression(left), expressionFactory->createExpression(right));
        result = exp1->calculate();
    } else if (boolOperator=="<") {
        exp1 = new LessThen(expressionFactory->createExpression(left), expressionFactory->createExpression(right));
        result = exp1->calculate();
    }
    return (result == 1);
}