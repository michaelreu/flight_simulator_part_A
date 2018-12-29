//
// Created by cs on 12/13/18.
//

#ifndef PROJECTPART1_COMMAND_H
#define PROJECTPART1_COMMAND_H
//for connectCommand
#define START_OF_STRING 1
#define END_OF_STRING 1
#define IP_REGEX "^([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])$"
#define SET "set "
//for OpenServerCommand
#define BUFF_SIZE 1024
#define BACKLOG 5
//for PrintCommand
#define FIRST 1
//for SleepCommand
#define TEN_MILL_SEC 10


#include "../expression/Expression.h"
#include "../factory/ExpressionFactory.h"

#include <chrono>
#include <thread>

#include <iostream>
#include <pthread.h>
#include <cstdio>
#include <cstdlib>
#include <regex>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>

#include <vector>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#define SLEEP_TIME 300

class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};


class DefineVarCommand : public Command {
private:
    SymbolTable* symTbl;
    string var;
public:
    DefineVarCommand(SymbolTable* &symTable, const string &key);
    virtual void execute();
    virtual ~DefineVarCommand() = default;
};

/*
 * responsible for assigning to our SymbolTable the key, value of specific var
 */
class AssignCommand : public Command {
private:
    ExpressionFactory* expressionFactory;
    SymbolTable* symTbl;
    vector<string>::iterator it;
    string var;
    string dest;
    double value;
    bool addValue = true;
public:
    /*
     * AssignCommand can be built with numeric value, or a destination path.
     */
    AssignCommand(SymbolTable* &symTable,const string &varToAdd, const string &dest);
    AssignCommand(SymbolTable* &symTable, ExpressionFactory* &expFac, const string &varToAdd, vector<string>::iterator &it);
    virtual void execute();
    virtual ~AssignCommand()= default;
};



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



using namespace std;
class PrintCommand : public Command {
private:
    ExpressionFactory* expFactory;
    string strToPrint;
    bool isInQoutes();

public:
    PrintCommand(ExpressionFactory* expFac, string &str);
    virtual void execute();
    virtual ~PrintCommand() = default;
};


#include "Command.h"


class SleepCommand : public Command{
private:
    long time;

public:
    SleepCommand(long time);
    virtual void execute();
    virtual ~SleepCommand() = default;

};

#endif //PROJECTPART1_COMMAND_H
