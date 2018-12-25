

#ifndef EX3_READER_H
#define EX3_READER_H

#define NUM_OF_SOCK 2


#include <string>
#include "list"
#include <utility>
#include <vector>
#include <iostream>
#include "LexerParser.h"


using namespace std;


struct threadParams {
    pthread_t* thread;
    pthread_mutex_t* lock;
    int hertz;
    int sockfdConnect;
    int sockfdServer;
    int newsockfd;
};
typedef struct threadParams threadParams;

class Reader  {



public:
    Reader() = default;
    bool readCommandsFromFile(string fileName, LexerParser* interpreter);
    void run(int argc, char* argv[]);
    bool readCommandsFromCmd(string commad, LexerParser* interpreter);
};


#endif //EX3_READER_H



