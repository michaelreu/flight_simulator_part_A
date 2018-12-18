
#ifndef INC_14_12_12_46_OPENSERVERFACTORY_H
#define INC_14_12_12_46_OPENSERVERFACTORY_H

#include "CommandExpressionFactory.h"
#include "ExpressionFactory.h"
#include "../reader/ExpressionCommand.h"
#include "../reader/OpenServerCommand.h"

class openServerFactory : public CommandExpressionFactory {
private:
    int port;
    int hertz;
public:
    openServerFactory();
    virtual Expression* createExpression(vector<string> *dataVector);
};


#endif //INC_14_12_12_46_OPENSERVERFACTORY_H
