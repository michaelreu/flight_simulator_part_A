
#ifndef PROJECTPART1_OPENSERVERCOMMAND_H
#define PROJECTPART1_OPENSERVERCOMMAND_H

#define NUM_OF_PARAM 3
#define PARAMETERS_NUMBER_EXCEPTION "not enough parameters"

#include "Command.h"
#include "Reader.h"
#include <vector>
#include <string>

using namespace std;


class OpenServerCommand: public Command {
private:
    int port;
    int hertz;

public:
    OpenServerCommand(int prt, int hz);
    virtual void execute();

};


#endif //PROJECTPART1_OPENSERVERCOMMAND_H
