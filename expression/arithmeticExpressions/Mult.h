//
// Created by tamir on 07/12/18.
//

#ifndef SEMPROJECT_MULT_H
#define SEMPROJECT_MULT_H


#include "../BinaryExpression.h"

class Mult : public BinaryExpression  {

public:

    Mult(Expression* leftEx, Expression* rightEx);

    Mult(double leftNum, Expression* rightEx);

    Mult(Expression* leftEx, double rightNum);

    Mult(double leftNum, double rightNum);

    virtual double calculate();
};


#endif //SEMPROJECT_MULT_H
