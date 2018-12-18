
#ifndef INC_14_12_12_46_PARSER_H
#define INC_14_12_12_46_PARSER_H

#define RUN "run"
#define OPEN_DATA_SERVER_STR "openDataServer"

#include <vector>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <utility>
#include <map>

#include "../expression/Expression.h"
#include "../factory/CommandExpressionFactory.h"
#include "../maps/SymbolTable.h"
#include "../factory/openServerFactory.h"

using namespace std;

class LexerParser {
    SymbolTable symTbl;
    map<string,CommandExpressionFactory*> mapStrToCommand;
    vector<string> vecOfExpressions;

public:
    void initMapOfCommands();
    LexerParser (const SymbolTable &sym);
    vector<string> loadfile(const string& fileName);
    vector<string> lexer(const string&  command);
    void parser();

    const vector<string> &getVecOfExpressions() const;

    SymbolTable getSymbolTable();
};



#endif //INC_14_12_12_46_PARSER_H
