
#include "CommandExpressionFactory.h"


double CommandExpressionFactory::extractDoubleFromString(string &s) {
    return (expressionNumberCreator.createExpression(s))->calculate();

}

string CommandExpressionFactory::getNextDoubleInVector(vector<string> *dataVector) {
    dataVector->erase((dataVector)->begin());
    return *(dataVector)->begin();
}