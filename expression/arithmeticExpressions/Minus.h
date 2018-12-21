//
// Created by tamir on 07/12/18.
//

#ifndef SEMPROJECT_MINUS_H
#define SEMPROJECT_MINUS_H


#include "../BinaryExpression.h"

class Minus : public BinaryExpression  {

public:
    Minus(Expression* leftEx, Expression* rightEx);

    Minus(double leftNum, Expression* rightEx);

    Minus(Expression* leftEx, double rightNum);

    Minus(double leftNum, double rightNum);

    virtual double calculate();
};



#endif //SEMPROJECT_MINUS_H
