

#ifndef INC_14_12_12_46_CONNECTFACTORY_H
#define INC_14_12_12_46_CONNECTFACTORY_H

#include "CommandExpressionFactory.h"
#include "ExpressionFactory.h"
#include "../reader/ExpressionCommand.h"
#include "../reader/OpenServerCommand.h"
#include "../reader/ConnectCommand.h"


class ConnectFactory : public CommandExpressionFactory{

private:
    string server;
    int port;
public:
    virtual Expression* createExpression(vector<string> *dataVector);

};


#endif //INC_14_12_12_46_OPENSERVERFACTORY_H

