#ifndef PROJECTPART1_OPENSERVERCOMMAND_H
#define PROJECTPART1_OPENSERVERCOMMAND_H


#define BUFF_SIZE 1024
#define BACKLOG 5

#include "Command.h"
#include "../Utils.h"


using namespace std;

struct serverParams {
    SymbolTable* symbolTablePa;
    pthread_mutex_t* mutexPa;
    int sockfd;
    int newsockfd;
    bool* isRun;
    bool* clientIsRun;
    bool *clientThreadIsRun;
};


class OpenServerCommand: public Command {

private:
    SymbolTable* symbolTable;
    int port;
    int hertz;
    threadParams *threadsParam;


public:
    OpenServerCommand(){}
    OpenServerCommand(int prt, int hz, SymbolTable* symTable, threadParams *threadsParam);
    void updateDataFromClient(const string &str, SymbolTable* symTable);
    virtual void execute();
    virtual ~OpenServerCommand() = default;
};

#endif //PROJECTPART1_OPENSERVERCOMMAND_H