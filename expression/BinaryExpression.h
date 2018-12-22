

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

    virtual ~BinaryExpression() = 0;


};

#endif //SEMPROJECT_BINARYEXPRESSION_H
