
#include "WhileCommand.h"

WhileCommand::WhileCommand(vector<Expression *> &vecOfExp, string &con, ExpressionFactory* expFac)
:ConditionParser(vecOfExp,con,expFac) {}

void WhileCommand::execute(){
    while (checkCondition()) {
        for (Expression* command : getVecOfExpCommands()) {
            command->calculate();
        }
    }
}