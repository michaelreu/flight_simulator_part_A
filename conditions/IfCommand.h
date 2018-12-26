
#ifndef INC_14_12_12_46_IFCONDITION_H
#define INC_14_12_12_46_IFCONDITION_H

#include "ConditionParser.h"


using namespace std;

class IfCommand : public  ConditionParser {

public:
    IfCommand(vector <Expression*> &vecOfExp, string &con, ExpressionFactory* expFac);
    virtual void execute();
};


#endif //INC_14_12_12_46_IFCONDITION_H
