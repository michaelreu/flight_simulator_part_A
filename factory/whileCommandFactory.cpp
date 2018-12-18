//
// Created by cs on 12/18/18.
//

#include "whileCommandFactory.h"

Expression* whileCommandFactory::createExpression(vector<string> *dataVector) {
    this->condition = getNextDoubleInVector(dataVector);
    ExpressionCommand* expressionCommand = new ExpressionCommand(new WhileCondition(this->vectorOfComannds, this->condition));
    return expressionCommand;
}
