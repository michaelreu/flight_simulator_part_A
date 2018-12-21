
#ifndef PROJECTPART1_CONNECTCOMMAND_H
#define PROJECTPART1_CONNECTCOMMAND_H
#define INVALID_IP_ADRESS_ERR "Error: connection failed - invalid IP adress"
#include "Command.h"
#include "../reader/Reader.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

using namespace std;

class ConnectCommand: public Command {
private:
    const char* ip;
    int port;

public:
    ConnectCommand(const char* ip, int port);

    bool validIP();

    virtual void execute();

};


#endif //PROJECTPART1_CONNECTCOMMAND_H
