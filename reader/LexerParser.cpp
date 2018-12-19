#include "LexerParser.h"

using namespace std;

LexerParser::LexerParser(const SymbolTable &sym) {
    this->symTbl = sym;
}
const vector<string> &LexerParser::getVecOfExpressions() const {
    return this->vecOfExpressions;
}
void LexerParser::initMapOfCommands() {
    //mapStrToCommand.insert(pair<string,CommandExpressionFactory*>(OPEN_DATA_SERVER_STR, new OpenServerFactory(this->symTbl)));
   // mapStrToCommand.insert(pair<string,CommandExpressionFactory*>(CONNECT_TO_SERVER_STR, new ConnectFactory()));
    //mapStrToCommand.insert(pair<string,CommandExpressionFactory*>(WHILE_CONDITION_STR, new whileCommandFactory()));
   // mapStrToCommand.insert(pair<string,CommandExpressionFactory*>(IF_CONDITION_STR, new ifCommandFactory()));

}


string extractFileName(string command){
    size_t startFileName = command.find("/""");
    string fileName = command.substr (startFileName + 1, command.size() -2);
    return fileName;
}

vector<string> LexerParser::loadfile(const string& fileName){
    //regex numPattern();
    string expression;
    vector<string> dataFromFile;
    ifstream myFile(fileName);
    if (myFile.is_open()) {
        while (myFile >> expression) {
            dataFromFile.push_back(expression);
        }
        myFile.close();
    }
    return dataFromFile;
}


vector<string> LexerParser::lexer(const string &command) {
    vector <string> listOfCommands;
    vector <string> vecOfExpressions;

    if (command.rfind(RUN, 0) == 0){
        listOfCommands = loadfile(extractFileName(command));
    } else {
        listOfCommands.push_back(command);
    }
    for (auto it = listOfCommands.begin() ; it != listOfCommands.end(); ++it) {
        // split the data by white spaces
        istringstream iss(command);
        for (string s; iss >> s;) {
            (this->vecOfExpressions).push_back(s);
        }
    }
    return this->vecOfExpressions;
}

SymbolTable LexerParser::getSymbolTable(){
    return symTbl;
}

void LexerParser::checkVarsOfCommand(){
    regex mathExpression("[(]?-?([1-9][0-9]*)[ ]*([(\\*+\\/\\-)][ ]*([1-9][0-9]*)[ ]*)*[)]?");
    regex varExpression("[a-z_][a-zA-Z_0-9]*");
    string s = this->vecOfExpressions.at(1);

}

void LexerParser::parser() {
    for (auto it = getVecOfExpressions().begin(); it != getVecOfExpressions().end(); ++it) {
        if (!(mapStrToCommand.find(*it) == mapStrToCommand.end())) {
            checkVarsOfCommand();
            mapStrToCommand.at(*it)->createExpression(&vecOfExpressions);
        }
    }
}
