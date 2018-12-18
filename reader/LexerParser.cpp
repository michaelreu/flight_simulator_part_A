#include "LexerParser.h"

using namespace std;

LexerParser::LexerParser(const SymbolTable &sym) {
    this->symTbl = sym;
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
    if (command.rfind("run", 0) == 0){
        listOfCommands = loadfile(extractFileName(command));
    } else {
        listOfCommands.push_back(command);
    }

    while (!listOfCommands.empty()) {

    }
}


void LexerParser::parser(vector<string> listOfCommand){

}
