
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
    } else if ((*it)==IF_STR) {
        return getIfCommand(it);
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

vector<Expression*> CommandExpressionFactory::getCommandsVecOfCondition(vector<string>::iterator &it) {
    vector<Expression*> commandsList;
    while (*(++it) != RIGHT_CURLY_PARENTHESIS_STR) {
        commandsList.push_back(createExpression(it));
    }
    return commandsList;

}

Expression* CommandExpressionFactory::getIfCommand(vector<string>::iterator &it) {
    string condition = *(++it);
    vector<Expression*> commandsList = getCommandsVecOfCondition(it);

}

Expression* CommandExpressionFactory::getWhileCommand(vector<string>::iterator &it) {
    string condition = *(++it);
    vector<Expression*> commandsList = getCommandsVecOfCondition(it);;

}

CommandExpressionFactory::~CommandExpressionFactory() {
    delete this->expressionNumberCreator;
    delete this->symTbl;
}
