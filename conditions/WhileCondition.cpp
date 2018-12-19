
#include "WhileCondition.h"

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