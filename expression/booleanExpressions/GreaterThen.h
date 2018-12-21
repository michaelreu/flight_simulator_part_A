//
// Created by tamir on 21/12/18.
//

#ifndef INC_14_12_12_46_GREATERTHEN_H
#define INC_14_12_12_46_GREATERTHEN_H

#include "../BinaryExpression.h"

class GreaterThen : public BinaryExpression  {

public:
    GreaterThen(Expression* leftEx, Expression* rightEx);

    GreaterThen(double leftNum, Expression* rightEx);

    GreaterThen(Expression* leftEx, double rightNum);

    GreaterThen(double leftNum, double rightNum);

    virtual double calculate();
};



#endif //INC_14_12_12_46_GREATERTHEN_H
