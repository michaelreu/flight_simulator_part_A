
#ifndef INC_14_12_12_46_GREATERTHEN_H
#define INC_14_12_12_46_GREATERTHEN_H

#include "../BinaryExpression.h"

class GreaterThen : public BinaryExpression  {

public:
    GreaterThen(Expression* leftEx, Expression* rightEx);

    virtual double calculate();
    virtual ~GreaterThen() = default;

};



#endif //INC_14_12_12_46_GREATERTHEN_H
