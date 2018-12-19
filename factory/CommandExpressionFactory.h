
#ifndef INC_14_12_12_46_COMMANDEXPRESSIONFACTORY_H
#define INC_14_12_12_46_COMMANDEXPRESSIONFACTORY_H


#include "ExpressionFactory.h"
#include "../reader/ExpressionCommand.h"
#include "../reader/OpenServerCommand.h"
#define OPEN_DATA_SERVER_STR "openDataServer"
#define CONNECT_STR "connect"

#include <vector>
#include "../maps/SymbolTable.h"

using namespace std;

class CommandExpressionFactory {

private:
    ExpressionFactory expressionNumberCreator;

public:

    //virtual Expression* createExpression(vector<string> *dataVector)=0;
    virtual Expression* createExpression(vector<string>::iterator it);
    double extractDoubleFromString(string &s);
    //string getNextDoubleInVector(vector<string> *dataVector);
    string getNextDoubleInVector(vector<string>::iterator it);
    Expression* getOpenServerCommand(vector<string>::iterator it);

};



#endif //INC_14_12_12_46_COMMANDEXPRESSIONFACTORY_H
