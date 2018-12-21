//
// Created by cs on 12/18/18.
//

#include "ConditionParser.h"
#include "../expression/booleanExpressions/Equal.h"


ConditionParser::ConditionParser(vector<Expression *> &vecOfExp, string &con, ExpressionFactory* exprNumCreator) {
    //this->symTbl=symbolTable;
    this->expressionFactory = exprNumCreator;
    this->vecOfExpCommands = vecOfExp;
    this->condition = con;
    this->boolOperator = utils.findBoolExpression(con);
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
    if (boolOperator=="==") {
        return new Equal(expressionFactory->createExpression(left), expressionFactory->createExpression(right));
    }
}