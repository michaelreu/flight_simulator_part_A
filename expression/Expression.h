

#ifndef SEMPROJECT_EXPRESSION_H
#define SEMPROJECT_EXPRESSION_H
#define TRUE 1
#define FALSE 0

#include <cstdlib>

class Expression {

public:
    virtual double calculate() = 0;
    virtual ~Expression() = default;
};

//class BinaryExpression {
//
//};

#endif //SEMPROJECT_EXPRESSION_H
