
#ifndef PROJECTPART1_COMMANDEXPRESSION_H
#define PROJECTPART1_COMMANDEXPRESSION_H

#include "../expression/Expression.h"
#include "Command.h"

class ExpressionCommand : public Expression {
        Command* c;

public:
    ExpressionCommand(Command *command){
        c = command;
    }

    //need to check about the return value if calculate returns double but execute ret void
    virtual double calculate(){
        c->execute();
        return 0;
    }
    virtual ~ExpressionCommand() = default;

};

#endif //PROJECTPART1_COMMANDEXPRESSION_H