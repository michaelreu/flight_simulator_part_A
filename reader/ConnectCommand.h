
#ifndef PROJECTPART1_CONNECTCOMMAND_H
#define PROJECTPART1_CONNECTCOMMAND_H

#include "Command.h"
#include "Reader.h"
#include <string>

using namespace std;

class ConnectCommand: public Command {
private:
    string ip;
    int port;

public:
    ConnectCommand(string ip, int port);
    virtual void execute();

};


#endif //PROJECTPART1_CONNECTCOMMAND_H
