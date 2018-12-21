
#ifndef INC_14_12_12_46_LEXERPARSER_H
#define INC_14_12_12_46_LEXERPARSER_H




#define QUOTES_CHAR 34
#define COMMA 44
#define LEFT_CURLY_PARENT_CHAR 123


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
    Utils utils;

public:
    LexerParser ()= default;
    void loadfile(const string& fileName);
    vector<string> lexer(const string&  command);
    void parser();
    void checkVarsOfCommand();
    const vector<string> &getVecOfExpressions() const;
    void lexByValue();
    void mergeIfNeeded(vector<string> *lex);
    bool charCase(char prev, int i);
    bool parnthesesCase(char prev);
};



#endif //INC_14_12_12_46_LEXERPARSER_H
