
#include "CommandExpressionFactory.h"






double CommandExpressionFactory::extractDoubleFromString(string &s) {

    return (expressionNumberCreator.createExpression(s))->calculate();
    //StrToDoubleClass strToDouble = StrToDoubleClass(s);

    //return strToDouble.calculate();
}

double CommandExpressionFactory::getNextDoubleInVector1(vector<string> *dataVector) {
    dataVector->erase((dataVector)->begin());
    auto it = (dataVector)->begin();
    double d = extractDoubleFromString(*it);
    return d;
}