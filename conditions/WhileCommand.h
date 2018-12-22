

#ifndef INC_14_12_12_46_WHILECONDITION_H
#define INC_14_12_12_46_WHILECONDITION_H

#include "ConditionParser.h"
#include "../commands/ExpressionCommand.h"
#include <vector>


using namespace std;

class WhileCommand : public  ConditionParser{

public:
    WhileCommand(vector <Expression*> &vecOfExp, string &con, ExpressionFactory* expFac);
    virtual void execute();
    virtual ~WhileCommand() = default;

};


#endif //INC_14_12_12_46_WHILECONDITION_H

