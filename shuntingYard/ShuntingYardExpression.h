
#ifndef INC_14_12_12_46_SHUNTINGYARDEXPRESSION_H
#define INC_14_12_12_46_SHUNTINGYARDEXPRESSION_H

#include <string>
/*
 * this class is the class of the stack template for the shunting yard algorithm
 */
using namespace std;
class ShuntingYardExpression {

public:
    virtual string getNumOrOperationExp() = 0;

    ~ShuntingYardExpression() = default;
};



#endif //INC_14_12_12_46_SHUNTINGYARDEXPRESSION_H
