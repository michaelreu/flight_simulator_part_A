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
class Num : public Expression, public ShuntingYardExpression {
private:
    double num;

public:
    //ctor
    Num(double num);
    Num(int num);
    Num(const char* num);

    //getter
    double getNum() const;

    void setNum(double num);

    virtual double calculate();

    virtual string getNumOrOperationExp();

    virtual ~Num() = default;

};


#endif //SEMPROJECT_NUM_H
