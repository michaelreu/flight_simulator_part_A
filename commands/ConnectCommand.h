
#ifndef PROJECTPART1_CONNECTCOMMAND_H
#define PROJECTPART1_CONNECTCOMMAND_H

#define START_OF_STRING 2
#define END_OF_STRING 3
#define SEEP_TIME (1/4)
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
    static bool shouldStop;
    SymbolTable* symbolTable;
    const char* ip;
    int port;
    threadParams *threadsParam;


public:
    ConnectCommand(){}
    ConnectCommand(const char* ip, int port, SymbolTable* &symTable, threadParams *threadsParam);
    static void stop();
    virtual void execute();
    virtual ~ConnectCommand()= default;

    static bool getShouldStop();


};


#endif //PROJECTPART1_CONNECTCOMMAND_H
