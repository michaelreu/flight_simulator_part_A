
#include "WhileCommand.h"

WhileCommand::WhileCommand(vector<Expression *> &vecOfExp, string &con, ExpressionFactory* expFac)
:ConditionParser(vecOfExp,con, expFac) {}

/**
 * while the condition is true -> -> do all the internal commands
 */
void WhileCommand::execute(){
    while (checkCondition()) {
        for (Expression* command : getVecOfExpCommands()) {
            command->calculate();
        }
    }
}