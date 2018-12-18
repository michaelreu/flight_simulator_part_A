//
// Created by tamir on 14/12/18.
//

#ifndef INC_14_12_12_46_OPERATORS_H
#define INC_14_12_12_46_OPERATORS_H


//#include "Expression.h"
#include "ShuntingYardExpression.h"
#include "../expression/Expression.h"

class Operators : public ShuntingYardExpression {
private:
    char operation;
public:
    Operators(const char op);
    char getOperation() const;

    virtual string getNumOrOperationExp() {
        string s;
        s+=operation;
        return s;
    }
};


#endif //INC_14_12_12_46_OPERATORS_H
