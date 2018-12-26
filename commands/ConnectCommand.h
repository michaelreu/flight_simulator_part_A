
#ifndef PROJECTPART1_CONNECTCOMMAND_H
#define PROJECTPART1_CONNECTCOMMAND_H

#define START_OF_STRING 1
#define END_OF_STRING 1
#define IP_REGEX "^([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])$"
#define SET "set "

#include "Command.h"


using namespace std;


struct clientParams {
    SymbolTable* symbolTablePa;
    const char* ipPa;
    int portPa;
    int clientSocket;
    bool* isRun;
    bool* updateData;
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
