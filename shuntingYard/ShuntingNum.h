//
// Created by tamir on 25/12/18.
//

#ifndef INC_14_12_12_46_SHUNTINGNUM_H
#define INC_14_12_12_46_SHUNTINGNUM_H


#include "ShuntingYardExpression.h"

class ShuntingNum : public ShuntingYardExpression {
private:
    double num;
public:
    ShuntingNum(double sHnum);
    virtual string getNumOrOperationExp();
};


#endif //INC_14_12_12_46_SHUNTINGNUM_H
