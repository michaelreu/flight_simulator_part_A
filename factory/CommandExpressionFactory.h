
#ifndef INC_14_12_12_46_COMMANDEXPRESSIONFACTORY_H
#define INC_14_12_12_46_COMMANDEXPRESSIONFACTORY_H

#define ERR_MSG "Error: \""
#define NOT_INIT_ERR "\" is not initialized"

#define OPEN_DATA_SERVER_STR "openDataServer"
#define CONNECT_STR "connect"
#define VAR_STR "var"
#define ASSIGN_CHAR "="
#define BIND_STR "bind"
#define IF_STR "if"
#define WHILE_STR "while"
#define PRINT_STR "print"
#define RIGHT_CURLY_PARENTHESIS_STR "}"
#define SLEEP_STR "sleep"

#include "ExpressionFactory.h"
#include "../commands/ExpressionCommand.h"
#include "../commands/OpenServerCommand.h"
#include "../commands/ConnectCommand.h"
#include "../commands/AssignCommand.h"
#include "../commands/SleepCommand.h"
#include "../commands/vars/DefineVarCommand.h"
#include "../conditions/IfCommand.h"
#include "../conditions/WhileCommand.h"
#include "../commands/PrintCommand.h"
#include <map>
#include "../maps/SymbolTable.h"


#include <vector>



using namespace std;

class CommandExpressionFactory {
typedef Expression* (CommandExpressionFactory::*create)(vector<string>::iterator &it);

private:
    ExpressionFactory* expressionNumberCreator;
    SymbolTable* symTbl;
    map<string, create> mapCreate;

public:
    CommandExpressionFactory();
    virtual Expression* createExpression(vector<string>::iterator &it);
    void initMap();
    Expression* getOpenServerCommand(vector<string>::iterator &it);
    Expression* getConnectCommand(vector<string>::iterator &it);
    Expression* getDefineVarCommand(vector<string>::iterator &it);
    Expression* getAssignCommand(vector<string>::iterator &it);
    vector<Expression*> getCommandsVecOfCondition(vector<string>::iterator &it);
    Expression* getIfCommand(vector<string>::iterator &it);
    Expression* getWhileCommand(vector<string>::iterator &it);
    Expression* getPrintCommand(vector<string>::iterator &it);
    Expression* getSleepCommand(vector<string>::iterator &it);
    virtual ~CommandExpressionFactory();
};



#endif //INC_14_12_12_46_COMMANDEXPRESSIONFACTORY_H
