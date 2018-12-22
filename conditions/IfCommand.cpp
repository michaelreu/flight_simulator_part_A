//
// Created by cs on 12/18/18.
//

#include "IfCommand.h"
#include "../factory/CommandExpressionFactory.h"

IfCommand::IfCommand(vector<Expression*> &vecOfExp, string &con, ExpressionFactory* expFac)
:ConditionParser(vecOfExp,con, expFac) {}

/**
 * if the condition is true -> do all the internal commands
 */
void IfCommand::execute(){
    if (checkCondition()) {
        for (Expression* command : getVecOfExpCommands()) {
            command->calculate();
        }
    }
}
