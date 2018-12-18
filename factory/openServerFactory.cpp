//
// Created by cs on 12/18/18.
//

#include "openServerFactory.h"




Expression* openServerFactory::createExpression(vector<string> *dataVector) {
    this->port=(int) getNextDoubleInVector(dataVector);
    this->hertz=(int) getNextDoubleInVector(dataVector);
    return OpenServerCommand(this->port, this->hertz);
}

