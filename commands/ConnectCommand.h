
#ifndef PROJECTPART1_CONNECTCOMMAND_H
#define PROJECTPART1_CONNECTCOMMAND_H
#define START_OF_STR 2
#define END_OF_STR 3
#define SEEP_TIME 1/4
#define INVALID_IP_ADRESS_ERR "Error: connection failed - invalid IP adress"
#define IP_REGEX "^([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])$"


#include "Command.h"
#include "../reader/Reader.h"
#include <pthread.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <regex>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

using namespace std;


struct clientParams {
    SymbolTable* symbolTablePa;
    const char* ipPa;
    int portPa;
};
class ConnectCommand: public Command {
private:
    static bool shouldStop;
    SymbolTable* symbolTable;
    const char* ip;
    int port;


public:
    ConnectCommand(){}
    ConnectCommand(const char* ip, int port, SymbolTable* symTable);
    static void stop();
    virtual void execute();
    virtual ~ConnectCommand()= default;

    static bool getShouldStop();


};


#endif //PROJECTPART1_CONNECTCOMMAND_H
