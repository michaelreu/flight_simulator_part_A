
#ifndef INC_14_12_12_46_SLEEPCOMMAND_H
#define INC_14_12_12_46_SLEEPCOMMAND_H
#define TEN_MILL_SEC 10
#include "Command.h"


class SleepCommand : public Command{
private:
    long time;

public:
    SleepCommand(long time);
    virtual void execute();
    virtual ~SleepCommand() = default;

};




#endif //INC_14_12_12_46_SLEEPCOMMAND_H
