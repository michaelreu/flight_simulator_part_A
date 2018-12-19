//
// Created by cs on 12/18/18.
//

#ifndef INC_14_12_12_46_IFCOMMANDFACTORY_H
#define INC_14_12_12_46_IFCOMMANDFACTORY_H

#include "CommandExpressionFactory.h"
#include "ExpressionFactory.h"
#include "../reader/IfCondition.h"
#include "../reader/ExpressionCommand.h"


class ifCommandFactory : public CommandExpressionFactory{
private:
    string condition;
    vector <ExpressionCommand> vectorOfComannds;
public:
    virtual Expression* createExpression(vector<string> *dataVector);
};


#endif //INC_14_12_12_46_IFCOMMANDFACTORY_H
