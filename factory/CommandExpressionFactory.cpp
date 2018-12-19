
#include "CommandExpressionFactory.h"


Expression* CommandExpressionFactory::createExpression(vector<string>::iterator it) {
    if ((*it) == OPEN_DATA_SERVER_STR) {
        return getOpenServerCommand(it);
    } else if ((*it) == CONNECT_STR) {
        return getConnectCommand(it);
    }
}

Expression* CommandExpressionFactory::getOpenServerCommand(vector<string>::iterator it) {
    // get string from vector
    //string stringPort = getNextDoubleInVector(it);
    //string stringHertz = getNextDoubleInVector(it);
    //string stringPort = (*(++it));
    //string stringHertz = (*(++it));
    // calculate to double
    int port = (int) (expressionNumberCreator.createExpression((*(++it))))->calculate();
    int hertz = (int) (expressionNumberCreator.createExpression((*(++it))))->calculate();
    return new ExpressionCommand(new OpenServerCommand(port, hertz));
}
Expression* CommandExpressionFactory::getConnectCommand(vector<string>::iterator it) {
    string ip = (*(++it));
    int port = (int) (expressionNumberCreator.createExpression((*(++it))))->calculate();
    return new ExpressionCommand(new ConnectCommand(ip,port));

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