//
// Created by tamir on 07/12/18.
//

#ifndef SEMPROJECT_UNARYEXPRESSION_H
#define SEMPROJECT_UNARYEXPRESSION_H

#include "Expression.h"
#include "Num.h"

class UnaryExpression : public Expression {

private:
    Expression* expression;


public:
    UnaryExpression(Expression* exp);

    virtual double calculate()=0;

    Expression* getExpression();
};

#endif //SEMPROJECT_UNARYEXPRESSION_H
