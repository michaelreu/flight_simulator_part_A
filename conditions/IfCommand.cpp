//
// Created by cs on 12/18/18.
//

#include "IfCommand.h"

IfCommand::IfCommand(vector<Expression *> &vecOfExp, string &con, SymbolTable *&symbolTable) {
    this->vecOfExpCommands = vecOfExp;
    this->symTbl = symbolTable;
    this->condition = con;
}

string IfCommand:: getCondition(){
    return this->condition;
}

void IfCommand::execute(){
    if (checkCondition(getCondition(), this->symTbl)) {
        for (Expression* command : this->vecOfExpCommands) {
            command->calculate();
        }
    }
}
