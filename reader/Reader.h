

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

class Reader  {



public:
    Reader() = default;
    bool readCommandsFromFile(string fileName, LexerParser* interpreter);
    void run(int argc, char* argv[]);
    bool readCommandsFromCmd(string commad, LexerParser* interpreter);
};


#endif //EX3_READER_H



