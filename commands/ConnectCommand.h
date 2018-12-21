
#ifndef PROJECTPART1_CONNECTCOMMAND_H
#define PROJECTPART1_CONNECTCOMMAND_H
#define INVALID_IP_ADRESS_ERR "Error: connection failed - invalid IP adress"
#include "Command.h"
#include "../reader/Reader.h"
#include <string>

using namespace std;

class ConnectCommand: public Command {
private:
    string ip;
    int port;

public:
    ConnectCommand(string ip, int port);

    bool validIP();

    virtual void execute();

};


#endif //PROJECTPART1_CONNECTCOMMAND_H
