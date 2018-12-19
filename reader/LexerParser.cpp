#include "LexerParser.h"

using namespace std;

const vector<string> &LexerParser::getVecOfExpressions() const {
    return this->vecOfExpressions;
}

string extractFileName(string command){
    //listOfCommand[1].substr(1, listOfCommand[1].size() - 2)
    size_t startFileName = command.find("\"");
    string fileName = command.substr (startFileName + 1, command.size()-6);
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
        //listOfCommands = loadfile(extractFileName(command));
        this->vecOfExpressions = loadfile(extractFileName(command)) ;
    } else {
        listOfCommands.push_back(command);
    }
    /*
    for (auto it = listOfCommands.begin() ; it != listOfCommands.end(); ++it) {
        // split the data by white spaces
        istringstream iss((*it));
        for (string s; iss >> s;) {
            (this->vecOfExpressions).push_back(s);
        }
    }
    */
    return this->vecOfExpressions;
}

void LexerParser::checkVarsOfCommand(){
    regex mathExpression("[(]?-?([1-9][0-9]*)[ ]*([(\\*+\\/\\-)][ ]*([1-9][0-9]*)[ ]*)*[)]?");
    regex varExpression("[a-z_][a-zA-Z_0-9]*");
    string s = this->vecOfExpressions.at(1);

}

void LexerParser::parser() {
    vector<string>::iterator it = vecOfExpressions.begin();
    CommandExpressionFactory commandExpfac = CommandExpressionFactory();
    for ( ;it != getVecOfExpressions().end(); (++it)) {
        Expression* tempExp = commandExpfac.createExpression((it));
    }
}

/*
        //(!(mapStrToCommand.find(*it) == mapStrToCommand.end()))
        if ((false)) {

                    //createExpression(*it);
            //checkVarsOfCommand();
            //mapStrToCommand.at(*it)->createExpression(it);
        } else {

        }
*/