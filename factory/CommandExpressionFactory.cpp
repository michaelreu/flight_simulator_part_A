
#include "CommandExpressionFactory.h"
#include "../commands/vars/DefineVarCommand.h"
#include "../conditions/IfCommand.h"
#include "../conditions/WhileCommand.h"

CommandExpressionFactory::CommandExpressionFactory() {
    this->symTbl = new SymbolTable();
    this->expressionNumberCreator = new ExpressionFactory(symTbl);
    initMap();
}

void CommandExpressionFactory::initMap(){
    mapCreate[OPEN_DATA_SERVER_STR] = &CommandExpressionFactory::getOpenServerCommand;
    mapCreate[CONNECT_STR] = &CommandExpressionFactory::getConnectCommand;
    mapCreate[VAR_STR] = &CommandExpressionFactory::getDefineVarCommand;
    mapCreate[ASSIGN_CHAR] = &CommandExpressionFactory::getAssignCommand;
    mapCreate[IF_STR] = &CommandExpressionFactory::getIfCommand;
    mapCreate[WHILE_STR] = &CommandExpressionFactory::getWhileCommand;
    mapCreate[PRINT_STR] = &CommandExpressionFactory::getPrintCommand;
    mapCreate[SLEEP_STR] = &CommandExpressionFactory::getSleepCommand;
}

Expression* CommandExpressionFactory::createExpression(vector<string>::iterator &it) {
    if (symTbl->isVarInMap(*it)) {
        (++it);
    }
    // find the command on map
    if (this->mapCreate.count((*it)) == 1) {
        create func = this->mapCreate[(*it)];
        // create the requested command
        return (this->*func)(it);
    }else{
        throw ERR_MSG + (*it) + NOT_INIT_ERR;
    }
}

Expression* CommandExpressionFactory::getOpenServerCommand(vector<string>::iterator &it) {
    int port = (int) (expressionNumberCreator->createExpression(((++it))))->calculate();
    int hertz = (int) (expressionNumberCreator->createExpression(((++it))))->calculate();
    return new ExpressionCommand(new OpenServerCommand(port, hertz));
}

Expression* CommandExpressionFactory::getConnectCommand(vector<string>::iterator &it) {
    string ip = (*(++it));
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
    //skips on '{'
    (++it);
    while (*(++it) != RIGHT_CURLY_PARENTHESIS_STR) {
        commandsList.push_back(createExpression(it));
    }
    return commandsList;

}

Expression* CommandExpressionFactory::getIfCommand(vector<string>::iterator &it) {
    string condition = *(++it);
    vector<Expression*> commandsList = getCommandsVecOfCondition(it);
    return new ExpressionCommand(new IfCommand(commandsList , condition, expressionNumberCreator));

}

Expression* CommandExpressionFactory::getWhileCommand(vector<string>::iterator &it) {
    string condition = *(++it);
    vector<Expression*> commandsList = getCommandsVecOfCondition(it);
    return new ExpressionCommand(new WhileCommand(commandsList , condition, expressionNumberCreator));
}

Expression* CommandExpressionFactory::getPrintCommand(vector<string>::iterator &it) {
    string strToPrint = *(++it);
}

Expression* CommandExpressionFactory::getSleepCommand(vector<string>::iterator &it) {
    double time = (expressionNumberCreator->createExpression(((++it))))->calculate();
    return new ExpressionCommand(new SleepCommand(time));
}

CommandExpressionFactory::~CommandExpressionFactory() {
    delete this->expressionNumberCreator;
    delete this->symTbl;
}
