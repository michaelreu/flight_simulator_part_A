#include "LexerParser.h"

using namespace std;


string extractFileName(string command){
    size_t startFileName = command.find("/""");
    string fileName = command.substr (startFileName + 1, command.size() -2);
    return fileName;
}

vector<string> LexerParser::loadfile(const string& fileName){
    regex numPattern();
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


vector<string> LexerParser::lexer(string commands) {
    vector <string> listOfCommand;
    if (commands.rfind("run", 0) == 0){
        listOfCommand = loadfile(extractFileName(commands));
    }

}


void LexerParser::parser(vector<string> listOfCommand){



}
