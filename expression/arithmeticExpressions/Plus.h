//
// Created by tamir on 07/12/18.
//

#ifndef SEMPROJECT_PLUS_H
#define SEMPROJECT_PLUS_H


#include "../BinaryExpression.h"

class Plus : public BinaryExpression  {

public:
    Plus(Expression* leftEx, Expression* rightEx);

    Plus(double leftNum, Expression* rightEx);

    Plus(Expression* leftEx, double rightNum);

    Plus(double leftNum, double rightNum);

    virtual double calculate();
};


#endif //SEMPROJECT_PLUS_H
