//
// Created by tamir on 07/12/18.
//

#ifndef SEMPROJECT_NEG_H
#define SEMPROJECT_NEG_H


#include "../UnaryExpression.h"

class Neg : public UnaryExpression  {

public:
    Neg(Expression* exp);

    Neg(double num);

    virtual double calculate();

    //virtual ~Neg() = default;

};

#endif //SEMPROJECT_NEG_H
