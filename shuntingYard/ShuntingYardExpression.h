

#ifndef INC_14_12_12_46_SHUNTINGYARDEXPRESSION_H
#define INC_14_12_12_46_SHUNTINGYARDEXPRESSION_H

#include <string>

using namespace std;
class ShuntingYardExpression {

public:
    virtual string getNumOrOperationExp()=0;

    virtual ~ShuntingYardExpression() = default;
};



#endif //INC_14_12_12_46_SHUNTINGYARDEXPRESSION_H
