
#include "CommandExpressionFactory.h"


Expression* CommandExpressionFactory::createExpression(vector<string>::iterator it) {
    if ((*it) == OPEN_DATA_SERVER_STR) {
        return getOpenServerCommand(it);
    } else if ((*it) == CONNECT_STR) {

    }

}

Expression* CommandExpressionFactory::getOpenServerCommand(vector<string>::iterator it) {
    // get string from vector
    string stringPort = getNextDoubleInVector(it);
    string stringHertz = getNextDoubleInVector(it);
    stringPort = (*(++it));
    stringHertz = (*(++it));

    // calculate to double
    int port = (int) (expressionNumberCreator.createExpression(stringPort))->calculate();
    int hertz = (int) extractDoubleFromString(stringHertz);
    return new ExpressionCommand(new OpenServerCommand(port, hertz));
}

double CommandExpressionFactory::extractDoubleFromString(string &s) {
    return (expressionNumberCreator.createExpression(s))->calculate();

}
/*
string CommandExpressionFactory::getNextDoubleInVector(vector<string> *dataVector) {
    dataVector->erase((dataVector)->begin());
    return *(dataVector)->begin();
}
*/
string CommandExpressionFactory::getNextDoubleInVector(vector<string>::iterator it) {

}