

#include "ConnectFactory.h"



Expression* ConnectFactory::createExpression(vector<string> *dataVector) {
    this->server = getNextDoubleInVector(dataVector);
    string stringPort = getNextDoubleInVector(dataVector);
    this->port = (int)extractDoubleFromString(stringPort);
    ExpressionCommand* expressionCommand = new ExpressionCommand(new ConnectCommand(this->server, this->port));
    return expressionCommand;
}

