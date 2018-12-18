#include "LexerParser.h"

using namespace std;

LexerParser::LexerParser(const SymbolTable &sym) {
    this->symTbl = sym;
}
const vector<string> &LexerParser::getVecOfExpressions() const {
    return this->vecOfExpressions;
}
void LexerParser::initMapOfCommands() {

    //mapStrToCommand.insert({ OPEN_DATA_SERVER_STR, new openServerFactory});
    mapStrToCommand.insert(pair<string,CommandExpressionFactory*>(OPEN_DATA_SERVER_STR,new openServerFactory()));


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
    //vector <string> vecOfExpressions;

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
}

SymbolTable LexerParser::getSymbolTable(){
    return symTbl;
}
void LexerParser::parser() {
    for (auto it = getVecOfExpressions().begin(); it != getVecOfExpressions().end(); ++it) {
        if (!(mapStrToCommand.find(*it) == mapStrToCommand.end())) {
            mapStrToCommand.at(*it)->createExpression(&vecOfExpressions);
        }
    }
}
