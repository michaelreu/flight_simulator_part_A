#ifndef INC_14_12_12_46_EQUAL_H
#define INC_14_12_12_46_EQUAL_H


#include "../BinaryExpression.h"

class Equal : public BinaryExpression  {

public:
    Equal(Expression* leftEx, Expression* rightEx);

    virtual double calculate();

    virtual ~Equal() = default;

};


#endif //INC_14_12_12_46_EQUAL_H
