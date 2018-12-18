//
// Created by cs on 12/13/18.
//

#ifndef PROJECTPART1_COMMANDEXPRESSION_H
#define PROJECTPART1_COMMANDEXPRESSION_H

#include "../expression/Expression.h"
#include "Command.h"

class ExpressionCommand : public Expression {
        Command *c;

public:
    ExpressionCommand(Command *command){
        c = command;
    }
    //need to check about the return value if calculate returns double but execute ret void
    ExpressionCommand(){}

    virtual double calculate(){
        c->execute();
        return 0;
    }
};


#endif //PROJECTPART1_COMMANDEXPRESSION_H

/*
if ((x<=0) && (y<=0)) {
    this.radius = 0;
    this.alfa=0;
} else if (x<=0) {
    this.radius = y;
    this.alfa = 90
} else if (y<=0) {
    this.radius = x;
    this.alfa = 0;
} else {
    this.radius = radius(x,y);
    this.alfa = alfa (x,y)
}
*/