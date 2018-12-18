

#ifndef SEMPROJECT_BINARYEXPRESSION_H
#define SEMPROJECT_BINARYEXPRESSION_H

#include "Expression.h"
#include "Num.h"

class BinaryExpression : public Expression {

private:
    Expression* left;
    Expression* right;


public:
    BinaryExpression(Expression* leftEx, Expression* rightEx);

    virtual double calculate()=0;

    Expression* getLeftExpression();

    Expression* getRightExpression();

};

#endif //SEMPROJECT_BINARYEXPRESSION_H
