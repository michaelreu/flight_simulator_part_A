
#ifndef INC_14_12_12_46_LEXERPARSER_H
#define INC_14_12_12_46_LEXERPARSER_H

#define RUN "run"
#define VAR "var"
#define WHILE "while"
#define IF "if"

//#define OPEN_DATA_SERVER_STR "openDataServer"
#define CONNECT_TO_SERVER_STR "connect"
#define IF_CONDITION_STR "if"
#define WHILE_CONDITION_STR "while"

#include <vector>
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <utility>
#include <regex>
#include <map>

#include "../expression/Expression.h"
#include "../factory/CommandExpressionFactory.h"
#include "../maps/SymbolTable.h"

using namespace std;
class CommandExpressionFactory;

class LexerParser {
    //CommandExpressionFactory commandExpFac;
    //SymbolTable symTbl;
    map<string,CommandExpressionFactory*> mapStrToCommand;
    vector<string> vecOfExpressions;

public:
    LexerParser ()= default;
    vector<string> loadfile(const string& fileName);
    vector<string> lexer(const string&  command);
    void parser();
    void checkVarsOfCommand();
    const vector<string> &getVecOfExpressions() const;
    void lexByValue();
    void mergeIfNeeded(vector<string> *lex);
};



#endif //INC_14_12_12_46_LEXERPARSER_H
