
#ifndef PROJECTPART1_CONNECTCOMMAND_H
#define PROJECTPART1_CONNECTCOMMAND_H
#define INVALID_IP_ADRESS_ERR "Error: connection failed - invalid IP adress"
#define IP_REGEX "^([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])$"
#include "Command.h"
#include "../reader/Reader.h"
#include <thread>
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

class ConnectCommand: public Command {
private:
    static bool shouldStop;
    SymbolTable* symbolTable;
    const char* ip;
    int port;
    bool validIP();

public:
    ConnectCommand(const char* ip, int port, SymbolTable* symTable);
    //static void runUser(const char* ip, const char* port, SymbolTable* &symTable);
    static void runUser(const char* ip, int port, SymbolTable* symTable);
    static void stop();
    virtual void execute();
    virtual ~ConnectCommand()= default;


};


#endif //PROJECTPART1_CONNECTCOMMAND_H
