
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
#include "regex"

using namespace std;

class LexerParser {
    SymbolTable symTbl;

public:
    vector<string> loadfile(const string& fileName);
    vector<string>  lexer(string commands);
    void parser(vector<string>);
};


#endif //INC_14_12_12_46_PARSER_H
