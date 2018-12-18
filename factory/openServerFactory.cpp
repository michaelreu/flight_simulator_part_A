//
// Created by cs on 12/18/18.
//

#include "openServerFactory.h"


Expression* openServerFactory::createExpression(vector<string> *dataVector) {
    // get string from vector
    string stringPort = getNextDoubleInVector(dataVector);
    string stringHertz = getNextDoubleInVector(dataVector);
    // calculate to double
    this->port = (int)extractDoubleFromString(stringPort);
    this->hertz = (int)extractDoubleFromString(stringHertz);

    ExpressionCommand* expressionCommand = new ExpressionCommand(new OpenServerCommand(this->port, this->hertz));
    return expressionCommand;
}

