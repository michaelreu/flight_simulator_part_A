
#ifndef PROJECTPART1_CONNECTCOMMAND_H
#define PROJECTPART1_CONNECTCOMMAND_H
#define SET "set "
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
    ConnectCommand(const char* ip, int port, SymbolTable* &symTable);
    static void stop();
    virtual void execute();
    static bool getShouldStop();

    virtual ~ConnectCommand();
};


#endif //PROJECTPART1_CONNECTCOMMAND_H
