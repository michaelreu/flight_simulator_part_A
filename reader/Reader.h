

#ifndef EX3_READER_H
#define EX3_READER_H


#include "fstream"
#include <sstream>
#include <string.h>
#include "list"
#include <utility>
#include <map>
#include <vector>
#include <iostream>
#include "ExpressionCommand.h"
#include "../shuntingYard/StrToDoubleClass.h"
#include "../expression/Expression.h"
#include "OpenServerCommand.h"



using namespace std;


class Reader  {
private:
    map<string, Expression*> commandsMap;
    map<string, int> vars;
    map<string, Expression*> &getCommandsMap();
    vector<string> dataVector;

public:
    void lexer();
    vector<string>& getVector();
    vector<string> loadfile(const string& fileName);
    void parser();
    void initCommandMap();

};


#endif //EX3_READER_H



