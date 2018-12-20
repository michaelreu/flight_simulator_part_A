//
// Created by tamir on 18/12/18.
//

#ifndef INC_14_12_12_46_EXPRESSIONFACTORY_H
#define INC_14_12_12_46_EXPRESSIONFACTORY_H
#define INVALID_EXPRESSION_STRING "Error: string of expression has invalid char"
#define DOUBLE_STRING_ERROR "Error: unspecified numbers or operations"

#define PLUS_CHAR '+'
#define MINUS_CHAR '-'
#define MULT_CHAR '*'
#define DIV_CHAR '/'
#define PARENTHESES_OPEN_CHAR '('
#define PARENTHESES_CLOSE_CHAR ')'
#define ZERO_CHAR '0'
#define SPACE_CHAR ' '
#include <stack>
#include "../expression/Expression.h"
#include "../expression/Num.h"
#include "../expression/Plus.h"
#include "../expression/Minus.h"
#include "../expression/Mult.h"
#include "../expression/Div.h"
#include "../expression/Num.h"
#include "../shuntingYard/Operators.h"
#include "../shuntingYard/ShuntingYardExpression.h"
#include "../Utils.h"
#include "../maps/SymbolTable.h"


using namespace std;

class ExpressionFactory{
private:
    Utils utils;
    SymbolTable* symbolTable;
    stack<ShuntingYardExpression*> mainStack;
    stack<char> operationsStack;
    string expressionStr;
    bool numBeforeMe;
    //bool negative;

    //private function
    stack<ShuntingYardExpression*> &getMainStack();
    stack<char> &getOperationsStack();
    // getters
    const string &getStrOfExpression() const;
    //checks
    bool operationsPrecedence(const char c);
    //operation of algorithm
    void addRestOfOperatorsToDigitsStack();
    void popOperatorsInParenthesesToMainStack();
    void popOperatorFromStackToMainStack();
    void insertByOrderToStack();

    Expression* generateExpressionOfStack();
public:
    ExpressionFactory()= default;
    ExpressionFactory(const SymbolTable* &symbolTable);
    virtual Expression* createExpression(const string &strToExp);
};

#endif //INC_14_12_12_46_EXPRESSIONFACTORY_H
