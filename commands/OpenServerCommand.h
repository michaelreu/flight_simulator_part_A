
#ifndef PROJECTPART1_OPENSERVERCOMMAND_H
#define PROJECTPART1_OPENSERVERCOMMAND_H

#include "Command.h"
//#include "Reader.h"
#include <vector>
#include <string.h>
#include <sstream>

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
    SymbolTable* symbolTable;
    int port;
    int hertz;
    static bool shouldStop;

public:
    OpenServerCommand(int prt, int hz, SymbolTable* symTable);
    static void updateDataFromClient(const string &str, SymbolTable* symTable);
    static void runServer(int port, int hz, SymbolTable* symTable);
    static void stop();
    virtual void execute();
    virtual ~OpenServerCommand() = default;

};


#endif //PROJECTPART1_OPENSERVERCOMMAND_H
