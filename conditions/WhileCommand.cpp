
#include "WhileCommand.h"
/*
WhileCondition::WhileCondition(vector <ExpressionCommand> vecOfExpressionCommands, string condition){
    this->vecOfExpressionCommands = vecOfExpressionCommands;
    this->condition = condition;
}

void WhileCondition:: setSymbolTable(SymbolTable &symbolTable1){
    this->symbolTable = &symbolTable1;
}

string WhileCondition:: getCondition(){
    return this->condition;
}

void WhileCondition::execute(){
    while (checkCondition(getCondition(), this->symbolTable)) {
        for (ExpressionCommand command : this->vecOfExpressionCommands) {
            command.calculate();
        }
    }
}
*/

WhileCommand::WhileCommand(vector<Expression *> &vecOfExp, string &con, SymbolTable *&symbolTable) {
    this->symTbl=symbolTable;
    this->vecOfExpCommands = vecOfExp;
    this->condition = con;
}
void WhileCommand::execute(){
    while (checkCondition(getCondition(), this->symTbl)) {
        for (Expression* command : this->vecOfExpCommands) {
            command->calculate();
        }
    }
}