
#include "CommandExpressionFactory.h"

/**
 * constructor
 */
CommandExpressionFactory::CommandExpressionFactory(threadParams *threadsParam) {
    this->threadsParam = threadsParam;
    this->symTbl = new SymbolTable(threadsParam);
    this->expressionNumberCreator = new ExpressionFactory(symTbl);
    //this->check = new CheckInputs();
    initMapOfStrToFunctionsAddress();
}
/**
 * init mapcreate
 */
void CommandExpressionFactory::initMapOfStrToFunctionsAddress(){
    mapCreate[OPEN_DATA_SERVER_STR] = &CommandExpressionFactory::getOpenServerCommand;
    mapCreate[CONNECT_STR] = &CommandExpressionFactory::getConnectCommand;
    mapCreate[VAR_STR] = &CommandExpressionFactory::getDefineVarCommand;
    mapCreate[ASSIGN_CHAR] = &CommandExpressionFactory::getAssignCommand;
    mapCreate[IF_STR] = &CommandExpressionFactory::getIfCommand;
    mapCreate[WHILE_STR] = &CommandExpressionFactory::getWhileCommand;
    mapCreate[PRINT_STR] = &CommandExpressionFactory::getPrintCommand;
    mapCreate[SLEEP_STR] = &CommandExpressionFactory::getSleepCommand;
}

/**
 * create new expression
 * @param it command type
 * @return new expression
 */
Expression* CommandExpressionFactory::createExpression(vector<string>::iterator &it) {
    // 'x = y' case while x is already on varMap
    if (symTbl->isVarInMap(*it)) {
        (++it);
    }
    // find the command on map
    if (this->mapCreate.count((*it)) == IN_MAP) {
        create func = this->mapCreate[(*it)];
        // create the requested command
        return (this->*func)(it);
    }else{
        // unknown command
        throw ERR_MSG + (*it) + NOT_INIT_ERR;
    }
}

/**
 * create open server command
 * @param it openServerCommand and his values
 * @return new expression of type openServerCommand
 */
Expression* CommandExpressionFactory::getOpenServerCommand(vector<string>::iterator &it) {
    int port = (int) (expressionNumberCreator->createExpression(((++it))))->calculate();
    int hertz = (int) (expressionNumberCreator->createExpression(((++it))))->calculate();
    if (!check.checkPort(port)){
        throw "invalid port";
    }
    if (!check.checkHertz(hertz)){
        throw "invalid hertz";
    }
    return new ExpressionCommand(new OpenServerCommand(port, hertz,symTbl, this->threadsParam));
}

/**
 * create connect command
 * @param it connect and his values
 * @return new expression of type connect
 */
Expression* CommandExpressionFactory::getConnectCommand(vector<string>::iterator &it) {
    const char* ip = (*(++it)).c_str();
    int port = (int) (expressionNumberCreator->createExpression(((++it))))->calculate();
    if (!check.checkPort(port)){
        throw "invalid port";
    }
    if (!check.checkIP(ip)){
        throw  "invalid ip";
    }
    return new ExpressionCommand(new ConnectCommand(ip,port, symTbl, this->threadsParam));
}

/**
 * create define var command
 * @param it DefineVar and his values
 * @return new expression of type DefineVar
 */
Expression* CommandExpressionFactory::getDefineVarCommand(vector<string>::iterator &it) {
    string var = (*(++it));
    if(!check.checkNameOfVar(var)){
        throw "invalid name";
    }
    return new ExpressionCommand(new DefineVarCommand(symTbl, var));
}

/**
 * create assign command
 * @param it assign and his values
 * @return new expression of type assign
 */
Expression* CommandExpressionFactory::getAssignCommand(vector<string>::iterator &it) {
    string var = (*(--it)++);
    (++it);
    // path case
    if ((*it)==BIND_STR) {
        string destinationPath =  (*(++it));
        destinationPath = destinationPath.substr(START_OF_STR,destinationPath.size() - END_OF_STR);;
        return new ExpressionCommand(new AssignCommand(symTbl, var, destinationPath));
    // value case
    } else {
        Expression* exp = new ExpressionCommand(new AssignCommand(symTbl, expressionNumberCreator, var , it));
        //because it's a var - it has to get an ExpressionFactory, var, and it's value so it can update them.
        return exp;
    }
}

/**
 * put all commands of condition in one vec
 * @param it all the internal commands
 * @return vector of all the internal commands
 */
vector<Expression*> CommandExpressionFactory::getCommandsVecOfCondition(vector<string>::iterator &it) {
    vector<Expression*> commandsList;
    //skips on '{'
    (++it);
    while (*(++it) != RIGHT_CURLY_PARENTHESIS_STR) {
        commandsList.push_back(createExpression(it));
    }
    return commandsList;

}

/**
 * create if command
 * @param it ifCommand and his values
 * @return new expression of type if
 */
Expression* CommandExpressionFactory::getIfCommand(vector<string>::iterator &it) {
    string condition = *(++it);
    // vector of all the internal commands
    vector<Expression*> commandsList = getCommandsVecOfCondition(it);
    return new ExpressionCommand(new IfCommand(commandsList , condition, expressionNumberCreator));
}

/**
 * create while command
 * @param it whileCommand and his values
 * @return new expression of type while
 */
Expression* CommandExpressionFactory::getWhileCommand(vector<string>::iterator &it) {
    string condition = *(++it);
    // vector of all the internal commands
    vector<Expression*> commandsList = getCommandsVecOfCondition(it);
    return new ExpressionCommand(new WhileCommand(commandsList , condition, expressionNumberCreator));
}

/**
 * create print command
 * @param it printCommand and his values
 * @return new expression of type print
 */
Expression* CommandExpressionFactory::getPrintCommand(vector<string>::iterator &it) {
    string strToPrint = *(++it);
    return new ExpressionCommand(new PrintCommand(expressionNumberCreator, strToPrint));
}

/**
 * create sleep command
 * @param it sleepCommand and his values
 * @return new expression of type sleep
 */
Expression* CommandExpressionFactory::getSleepCommand(vector<string>::iterator &it) {
    double time = (expressionNumberCreator->createExpression(((++it))))->calculate();
    if (check.checkTime(time)) {
        return new ExpressionCommand(new SleepCommand(time));
    }else{
        throw "invalid time";
    }
}

/**
 * distructor
 */
CommandExpressionFactory::~CommandExpressionFactory() {
    delete(this->expressionNumberCreator);
    this->expressionNumberCreator = nullptr;
}
