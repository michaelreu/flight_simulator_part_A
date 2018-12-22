
#ifndef INC_14_12_12_46_LEXERPARSER_H
#define INC_14_12_12_46_LEXERPARSER_H



#define PRINT_STR "print"
#define QUOTES_CHAR 34
#define COMMA 44
#define LEFT_CURLY_PARENT_CHAR 123
#define RIGHT_CURLY_PARENT_CHAR '}'
#define EQUAL '='

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
    //map<string,CommandExpressionFactory*> mapStrToCommand;
    vector<string> vecOfExpressions;
    Utils utils;
    CommandExpressionFactory* commandExpfac;

public:
    LexerParser ();
    void loadfile(const string& fileName);
    vector<string> lexer(const string&  command);
    void parser();
    const vector<string> &getVecOfExpressions() const;
    void lexByValue();
    bool charCase(char prev, int i);
    bool parnthesesCase(char prev);

    void checkVarsOfCommand();

    ~LexerParser();

};



#endif //INC_14_12_12_46_LEXERPARSER_H
