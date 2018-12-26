
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

    Expression* exp1 = nullptr;
    Expression* exp2 = nullptr;
    //can be 0 or 1 = false or true
    double result = FALSE;
    if (boolOperator == EQUAL_STR) {
        exp1 = new Equal(expressionFactory->createExpression(left), expressionFactory->createExpression(right));
        result = exp1->calculate();
    } else if (boolOperator == GREATER_EQUAL_STR) {
        exp1 = new Equal(expressionFactory->createExpression(left), expressionFactory->createExpression(right));
        exp2 = new GreaterThen(expressionFactory->createExpression(left), expressionFactory->createExpression(right));
        result = (exp1->calculate() + exp2->calculate());
    } else if (boolOperator == LESS_EQUAL_STR) {
        exp1 = new Equal(expressionFactory->createExpression(left), expressionFactory->createExpression(right));
        exp2 = new LessThen(expressionFactory->createExpression(left), expressionFactory->createExpression(right));
        result = (exp1->calculate() + exp2->calculate());
    } else if (boolOperator == NOT_EQUAL_STR) {
        exp1 = new Equal(expressionFactory->createExpression(left), expressionFactory->createExpression(right));
        result = ((int)(exp1->calculate() + 1) % 2);
    } else if (boolOperator == GREATER_STR) {
        exp1 = new GreaterThen(expressionFactory->createExpression(left), expressionFactory->createExpression(right));
        result = exp1->calculate();
    } else if (boolOperator == LESS_STR) {
        exp1 = new LessThen(expressionFactory->createExpression(left), expressionFactory->createExpression(right));
        result = exp1->calculate();
    }
    if (exp1 != nullptr) {
        delete(exp1);
        exp1 = nullptr;
    }
    if (exp2 != nullptr) {
        delete(exp2);
        exp2 = nullptr;
    }
    return (result == TRUE);
}

ConditionParser::~ConditionParser() {
    for (Expression* expToFree : vecOfExpCommands) {
        if (expToFree !=nullptr) {
            delete(expToFree);
            expToFree = nullptr;
        }
    }
    vecOfExpCommands.clear();
}