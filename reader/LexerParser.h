
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
#include <map>

#include "../expression/Expression.h"
#include "../factory/CommandExpressionFactory.h"
#include "../maps/SymbolTable.h"

using namespace std;
class CommandExpressionFactory;


typedef struct threadParams threadParams;

class LexerParser {

    vector<string> vecOfExpressions;
    Utils utils;
    CommandExpressionFactory* commandExpfac;
    threadParams* threadsParam;
    vector<string>* lexByValue(vector<string>* vecOfExp);
public:
    LexerParser (threadParams* threadsParam);
    vector<string>* loadfile(const string& fileName);
    vector<string>* lexerCommand(const string&  command);
    void parser(vector<string>* vecOfExpressions);
    const vector<string> &getVecOfExpressions() const;
    bool charCase(char prev, int i);
    bool parnthesesCase(char prev);

    ~LexerParser();

};



#endif //INC_14_12_12_46_LEXERPARSER_H
