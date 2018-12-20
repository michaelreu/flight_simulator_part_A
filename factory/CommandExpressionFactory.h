
#ifndef INC_14_12_12_46_COMMANDEXPRESSIONFACTORY_H
#define INC_14_12_12_46_COMMANDEXPRESSIONFACTORY_H


#define OPEN_DATA_SERVER_STR "openDataServer"
#define CONNECT_STR "connect"
#define VAR_STR "var"
#define ASSIGN_CHAR "="
#define BIND_STR "bind"

#include "ExpressionFactory.h"
#include "../commands/ExpressionCommand.h"
#include "../commands/OpenServerCommand.h"
#include "../commands/ConnectCommand.h"
#include "../commands/AssignCommand.h"

#include "../maps/SymbolTable.h"


#include <vector>

using namespace std;

class CommandExpressionFactory {

private:
    ExpressionFactory* expressionNumberCreator;
    SymbolTable* symTbl;

public:
    CommandExpressionFactory();
    virtual Expression* createExpression(vector<string>::iterator &it);

    Expression* getOpenServerCommand(vector<string>::iterator &it);
    Expression* getConnectCommand(vector<string>::iterator &it);
    Expression* getDefineVarCommand(vector<string>::iterator &it);
    Expression* getAssignCommand(vector<string>::iterator &it);

    virtual ~CommandExpressionFactory();
};



#endif //INC_14_12_12_46_COMMANDEXPRESSIONFACTORY_H
