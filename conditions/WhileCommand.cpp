
#include "WhileCommand.h"

WhileCommand::WhileCommand(vector<Expression *> &vecOfExp, string &con, SymbolTable *&symbolTable)
:ConditionParser(vecOfExp,con,symbolTable) {}

void WhileCommand::execute(){
    while (checkCondition()) {
        for (Expression* command : getVecOfExpCommands()) {
            command->calculate();
        }
    }
}