//
// Created by cs on 12/18/18.
//

#ifndef INC_14_12_12_46_OPENSERVERFACTORY_H
#define INC_14_12_12_46_OPENSERVERFACTORY_H

#include "CommandExpressionFactory.h"
#include "ExpressionFactory.h"
#include "../reader/ExpressionCommand.h"

#include "../reader/OpenServerCommand.h"

class openServerFactory : public CommandExpressionFactory{
private:
    int port;
    int hertz;
public:
    virtual Expression* createExpression(vector<string> *dataVector);
};


#endif //INC_14_12_12_46_OPENSERVERFACTORY_H
