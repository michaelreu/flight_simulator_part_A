//
// Created by cs on 12/18/18.
//

#include "ifCommandFactory.h"

Expression* ifCommandFactory::createExpression(vector<string> *dataVector) {
    this->condition = getNextDoubleInVector(dataVector);
    ExpressionCommand* expressionCommand = new ExpressionCommand(new IfCondition(this->vectorOfComannds, this->condition));
    return expressionCommand;
}
