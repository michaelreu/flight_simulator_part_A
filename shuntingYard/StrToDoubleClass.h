#ifndef SEMPROJECT_SHUNTINGYARD_H
#define SEMPROJECT_SHUNTINGYARD_H
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


#include <string>
#include <queue>
#include <stack>
#include "../Utils.h"
#include "../expression/Expression.h"
#include "../expression/Num.h"
#include "../expression/Plus.h"
#include "../expression/Minus.h"
#include "../expression/Mult.h"
#include "../expression/Div.h"


using namespace std;

class StrToDoubleClass {
private:
    string strOfExpression;
    bool numBeforeMe;
    //bool negative;
    stack<ShuntingYardExpression*> mainStack;
    stack<char> operationsStack;
    Utils utils;


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
    Expression* stackToExpression();

public:
    //ctor
    StrToDoubleClass(const string &strOfExpression);


    virtual double calculate();
};


#endif //SEMPROJECT_SHUNTINGYARD_H
