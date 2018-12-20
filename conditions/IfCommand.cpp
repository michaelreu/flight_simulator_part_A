//
// Created by cs on 12/18/18.
//

#include "IfCommand.h"

IfCommand::IfCommand(vector<Expression *> &vecOfExp, string &con, SymbolTable *&symbolTable)
:ConditionParser(vecOfExp,con,symbolTable) {  }
//this->vecOfExpCommands = vecOfExp;
   // this->symTbl = symbolTable;
   // this->condition = con;


void IfCommand::execute(){
    if (checkCondition()) {
        for (Expression* command : getVecOfExpCommands()) {
            command->calculate();
        }
    }
}
