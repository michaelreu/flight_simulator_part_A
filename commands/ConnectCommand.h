
#ifndef PROJECTPART1_CONNECTCOMMAND_H
#define PROJECTPART1_CONNECTCOMMAND_H

#define START_OF_STRING 1
#define END_OF_STRING 1
#define IP_REGEX "^([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])$"
#define SET "set "

#include "Command.h"
#include <iostream>
#include <pthread.h>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <regex>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#include <cstring>

using namespace std;


struct clientParams {
    SymbolTable* symbolTablePa;
    const char* ipPa;
    int portPa;
    int clientSocket;
    bool* isRun;
    pthread_mutex_t* mutex;
};
class ConnectCommand: public Command {
private:
    SymbolTable* symbolTable;
    const char* ip;
    int port;
    threadParams *threadsParam;


public:
    ConnectCommand(){}
    ConnectCommand(const char* ip, int port, SymbolTable* &symTable, threadParams *threadsParam);
    virtual void execute();
    virtual ~ConnectCommand()= default;
};


#endif //PROJECTPART1_CONNECTCOMMAND_H
