//
// Created by cs on 12/18/18.
//

#include "IfCommand.h"

IfCommand::IfCommand(vector<Expression *> &vecOfExp, string &con, ExpressionFactory* expFac)
:ConditionParser(vecOfExp,con,expFac) {  }
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
