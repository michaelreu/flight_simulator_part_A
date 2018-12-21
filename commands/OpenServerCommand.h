
#ifndef PROJECTPART1_OPENSERVERCOMMAND_H
#define PROJECTPART1_OPENSERVERCOMMAND_H

#include "Command.h"
//#include "Reader.h"
#include <vector>
#include <string.h>
#include "../factory/ExpressionFactory.h"
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>

using namespace std;


class OpenServerCommand: public Command {
private:
    int port;
    int hertz;
    bool shouldStop;

public:
    OpenServerCommand(int prt, int hz);
    void updateDataFromClient(string str);
    virtual void execute();
};


#endif //PROJECTPART1_OPENSERVERCOMMAND_H
