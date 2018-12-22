//
// Created by tamir on 21/12/18.
//

#ifndef INC_14_12_12_46_EQUAL_H
#define INC_14_12_12_46_EQUAL_H


#include "../BinaryExpression.h"

class Equal : public BinaryExpression  {

public:
    Equal(Expression* leftEx, Expression* rightEx);

    Equal(double leftNum, Expression* rightEx);

    Equal(Expression* leftEx, double rightNum);

    Equal(double leftNum, double rightNum);

    virtual double calculate();

    virtual ~Equal() = default;

};


#endif //INC_14_12_12_46_EQUAL_H
