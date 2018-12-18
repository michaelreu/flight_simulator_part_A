

#ifndef EX3_READER_H
#define EX3_READER_H



#include <string.h>
#include "list"
#include <utility>
#include <vector>
#include <iostream>
#include "LexerParser.h"
#include "../maps/SymbolTable.h"
#include "../factory/ExpressionFactory.h"





using namespace std;


class Reader  {

public:
    Reader() = default;
    void readCommands();

};


#endif //EX3_READER_H



