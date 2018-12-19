
#ifndef INC_14_12_12_46_COMMANDEXPRESSIONFACTORY_H
#define INC_14_12_12_46_COMMANDEXPRESSIONFACTORY_H


#define OPEN_DATA_SERVER_STR "openDataServer"
#define CONNECT_STR "connect"

#include "ExpressionFactory.h"
#include "../reader/ExpressionCommand.h"
#include "../reader/OpenServerCommand.h"
#include "../reader/ConnectCommand.h"
#include "../maps/SymbolTable.h"


#include <vector>

using namespace std;

class CommandExpressionFactory {

private:
    ExpressionFactory expressionNumberCreator;

public:
    CommandExpressionFactory() = default;
    //virtual Expression* createExpression(vector<string> *dataVector)=0;
    virtual Expression* createExpression(vector<string>::iterator it);
    double extractDoubleFromString(string &s);
    //string getNextDoubleInVector(vector<string> *dataVector);
    string getNextDoubleInVector(vector<string>::iterator it);
    Expression* getOpenServerCommand(vector<string>::iterator it);
    Expression* getConnectCommand(vector<string>::iterator it);
};



#endif //INC_14_12_12_46_COMMANDEXPRESSIONFACTORY_H
