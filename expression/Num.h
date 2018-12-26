//
// Created by tamir on 07/12/18.
//

#ifndef SEMPROJECT_NUM_H
#define SEMPROJECT_NUM_H
class ShuntingYardExpression;


#define DECIMAL_BASE 10
#include "Expression.h"
#include "../shuntingYard/ShuntingYardExpression.h"

//no death diamond
class Num : public Expression {
private:
    double num;

public:
    //ctor
    Num(double num);
    Num(int num);
    Num(const char* num);

    //getter
    double getNum() const;

    virtual double calculate();

    virtual ~Num() = default;

};


#endif //SEMPROJECT_NUM_H
