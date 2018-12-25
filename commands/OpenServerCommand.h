#ifndef PROJECTPART1_OPENSERVERCOMMAND_H
#define PROJECTPART1_OPENSERVERCOMMAND_H


#define BUFF_SIZE 256
#define BACKLOG 5

#include "Command.h"
#include "../Utils.h"
#include <vector>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>
#include <pthread.h>



using namespace std;

struct serverParams {
    SymbolTable* symbolTablePa;
    int portPa;
    int hertzPa;
    int sockfd;
    int newsockfd;
    bool* isRun;
    bool* clientIsRun;
};


class OpenServerCommand: public Command {

private:
    SymbolTable* symbolTable;
    int port;
    int hertz;
    static bool shouldStop;
    threadParams *threadsParam;


public:
    OpenServerCommand(){}
    OpenServerCommand(int prt, int hz, SymbolTable* symTable, threadParams *threadsParam);
    void updateDataFromClient(const string &str, SymbolTable* symTable);
    virtual void execute();
    virtual ~OpenServerCommand() = default;

};

#endif //PROJECTPART1_OPENSERVERCOMMAND_H