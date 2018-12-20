
#include "CommandExpressionFactory.h"
#include "../commands/vars/DefineVarCommand.h"

CommandExpressionFactory::CommandExpressionFactory() {
    this->symTbl = new SymbolTable();
    this->expressionNumberCreator = new ExpressionFactory(symTbl);

}

Expression* CommandExpressionFactory::createExpression(vector<string>::iterator &it) {
    if (symTbl->isVarInMap(*it)) {
        (++it);
    }
    if ((*it) == OPEN_DATA_SERVER_STR) {
        return getOpenServerCommand(it);
    } else if ((*it) == CONNECT_STR) {
        return getConnectCommand(it);
    } else if ((*it) == VAR_STR) {
        return getDefineVarCommand(it);
    } else if ((*it) == ASSIGN_CHAR) {
        return  getAssignCommand(it);
    }
}

Expression* CommandExpressionFactory::getOpenServerCommand(vector<string>::iterator &it) {
    //int port = (int) (expressionNumberCreator->createExpression((*(++it))))->calculate();
    //int hertz = (int) (expressionNumberCreator->createExpression((*(++it))))->calculate();
    int port = (int) (expressionNumberCreator->createExpression(((++it))))->calculate();
    int hertz = (int) (expressionNumberCreator->createExpression(((++it))))->calculate();
    return new ExpressionCommand(new OpenServerCommand(port, hertz));
}

Expression* CommandExpressionFactory::getConnectCommand(vector<string>::iterator &it) {
    string ip = (*(++it));
    //int port = (int) (expressionNumberCreator->createExpression((*(++it))))->calculate();
    int port = (int) (expressionNumberCreator->createExpression(((++it))))->calculate();
    return new ExpressionCommand(new ConnectCommand(ip,port));
}

Expression* CommandExpressionFactory::getDefineVarCommand(vector<string>::iterator &it) {
    string var = (*(++it));
    return new ExpressionCommand(new DefineVarCommand(symTbl, var));
}

Expression* CommandExpressionFactory::getAssignCommand(vector<string>::iterator &it) {
    string var = (*(--it)++);
    (++it);
    if ((*it)==BIND_STR) {
        string destinationPath = (*(++it));
        return new ExpressionCommand(new AssignCommand(symTbl, var, destinationPath));
    } else {
        //double value = (expressionNumberCreator->createExpression((*(it))))->calculate();
        double value = (expressionNumberCreator->createExpression((it)))->calculate();
        return new ExpressionCommand(new AssignCommand(symTbl, var , value));
    }
}


CommandExpressionFactory::~CommandExpressionFactory() {
    delete this->expressionNumberCreator;
    delete this->symTbl;
}
