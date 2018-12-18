//
// Created by cs on 12/18/18.
//

#ifndef INC_14_12_12_46_WHILECOMMANDFACTORY_H
#define INC_14_12_12_46_WHILECOMMANDFACTORY_H

#include "CommandExpressionFactory.h"
#include "ExpressionFactory.h"
#include "../reader/ExpressionCommand.h"
#include "../reader/WhileCondition.h"

class whileCommandFactory : public CommandExpressionFactory {

private:
    string condition;
    vector <ExpressionCommand> vectorOfComannds;

public:
    virtual Expression* createExpression(vector<string> *dataVector);
};


#endif //INC_14_12_12_46_WHILECOMMANDFACTORY_H

