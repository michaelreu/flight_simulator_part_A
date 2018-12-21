//
// Created by cs on 12/20/18.
//

#ifndef INC_14_12_12_46_SLEEPCOMMAND_H
#define INC_14_12_12_46_SLEEPCOMMAND_H


#include "Command.h"

class SleepCommand : public Command{
private:
    double time;
public:
    SleepCommand(double time);
    virtual void execute();
};




#endif //INC_14_12_12_46_SLEEPCOMMAND_H
