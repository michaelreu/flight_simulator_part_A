

#ifndef INC_14_12_12_46_OPERATORS_H
#define INC_14_12_12_46_OPERATORS_H
#include "ShuntingYardExpression.h"
#include "../expression/Expression.h"

class Operators : public ShuntingYardExpression {
private:
    char operation;
public:
    Operators(const char op);
    virtual string getNumOrOperationExp();
};
#endif //INC_14_12_12_46_OPERATORS_H
