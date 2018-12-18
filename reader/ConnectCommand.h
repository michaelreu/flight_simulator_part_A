
#ifndef PROJECTPART1_CONNECTCOMMAND_H
#define PROJECTPART1_CONNECTCOMMAND_H

#include "Command.h"
#include "Reader.h"
#include <vector>
#include <string>

using namespace std;


class ConnectCommand: public Command {
private:
    int port;
    string server;

public:
    ConnectCommand(string server, int port);
    virtual void execute();

};


#endif //PROJECTPART1_CONNECTCOMMAND_H
