//
// Created by tamir on 21/12/18.
//

#ifndef INC_14_12_12_46_LESSTHEN_H
#define INC_14_12_12_46_LESSTHEN_H


#include "../BinaryExpression.h"

class LessThen : public BinaryExpression  {

public:
    LessThen(Expression* leftEx, Expression* rightEx);

    LessThen(double leftNum, Expression* rightEx);

    LessThen(Expression* leftEx, double rightNum);

    LessThen(double leftNum, double rightNum);

    virtual double calculate();

    virtual ~LessThen() = default;

};

#endif //INC_14_12_12_46_LESSTHEN_H
