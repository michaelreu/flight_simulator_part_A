//
// Created by tamir on 07/12/18.
//

#ifndef SEMPROJECT_DIV_H
#define SEMPROJECT_DIV_H


#include "../BinaryExpression.h"

class Div : public BinaryExpression  {

public:
    Div(Expression* leftEx, Expression* rightEx);

    Div(double leftNum, Expression* rightEx);

    Div(Expression* leftEx, double rightNum);

    Div(double leftNum, double rightNum);

    virtual double calculate();

    //virtual ~Div() = default;

};


#endif //SEMPROJECT_DIV_H
