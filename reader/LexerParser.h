
#ifndef INC_14_12_12_46_PARSER_H
#define INC_14_12_12_46_PARSER_H


#include "../maps/SymbolTable.h"
#include <vector>
#include <string.h>
#include <iostream>
#include "fstream"
#include <sstream>
#include "list"
#include <utility>
#include <map>
#include "../shuntingYard/StrToDoubleClass.h"
#include "../expression/Expression.h"
#include "../factory/CommandExpressionFactory.h"
#include "regex"

using namespace std;

class LexerParser {
    SymbolTable symTbl;

public:
    LexerParser (const SymbolTable &sym);
    vector<string> loadfile(const string& fileName);
    vector<string>  lexer(const string&  command);
    void parser(vector<string> vec);
    SymbolTable getSymbolTable();
};


#endif //INC_14_12_12_46_PARSER_H
