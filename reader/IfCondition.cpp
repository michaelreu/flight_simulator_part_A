//
// Created by cs on 12/18/18.
//

#include "IfCondition.h"


IfCondition::IfCondition(vector <ExpressionCommand> vecOfExpressionCommands, string condition){
 this->vecOfExpressionCommands = vecOfExpressionCommands;
 this->symbolTable;
 this->condition = condition;

}

void IfCondition::addExpressionCommand(ExpressionCommand command){
    this->vecOfExpressionCommands.push_back(command);
}

void IfCondition:: setSymbolTable(SymbolTable &symbolTable1){
    this->symbolTable = &symbolTable1;
}

string IfCondition:: getCondition(){
    return this->condition;
}

void IfCondition::execute(){
    if (checkCondition(getCondition(), this->symbolTable)) {
        for (ExpressionCommand command : this->vecOfExpressionCommands) {
            command.calculate();
        }
    }
}