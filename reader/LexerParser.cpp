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

//void LexerParser::mergeIfNeeded(vector<string> *lex){
  //  regex lop ("[{[(\"]");
    //vector<string>::iterator it = this->vecOfExpressions.begin();
    //for ( ;it != this->getVecOfExpressions().end(); (++it)) {
      //  if ((regex_match(it, lop))

 //   }
//}

void LexerParser::lexByValue(){
    vector<string> lex;
    char prev = this->vecOfExpressions[0][0];
    string value;
    vector<string>::iterator it = this->vecOfExpressions.begin();
    for ( ;it != getVecOfExpressions().end(); (++it)) {
        for (int i = 0; i < (*it).size(); i++){
            char current = ((*it)[i]);
            // char after char
            if((utils.isLetter(current)) && (utils.isLetter(prev))){
                value += current;

            }
            // char after digit
            else if((utils.isLetter(current)) && (utils.isDigit(prev))){
                value += current;

            }
            // char after operator
            else if((utils.isLetter(current)) && (utils.isOperator(prev))){
                lex.push_back(value);
                value = "";
                value += current;

            }
            // char after '='
            else if((utils.isLetter(current)) && (prev == 61)){
                lex.push_back(value);
                value = "";
                value += current;
            }
            // digit after char
            else if((utils.isDigit(current)) && (utils.isLetter(prev))){
                // If they are in a different cell
                if(i == 0){
                    lex.push_back(value);
                    value = "";
                    value += current;
                } else{
                    value += current;
                }
            }
            // digit after digit
            else if((utils.isDigit(current)) && (utils.isDigit(prev))){
                // If they are in a different cell
                if(i == 0){
                    lex.push_back(value);
                    value = "";
                    value += current;
                } else{
                    value += current;
                }
            }
            // digit after operator
            else if((utils.isDigit(current)) && (utils.isOperator(prev))){
                value += current;
            }
            // digit after '='
            else if((utils.isDigit(current)) && (prev == 61)){
                lex.push_back(value);
                value = "";
                value += current;
            }
            // operator after char
            else if((utils.isOperator(current)) && (utils.isLetter(prev))){
                value += current;

            }
            // operator after digit
            else if((utils.isOperator(current)) && (isdigit(prev))){
                value += current;

            }
            // operator after operator
            else if((utils.isOperator(current)) && (utils.isOperator(prev))){
                value += current;

            }
            // operator after '='
            else if((utils.isOperator(current))  && (prev == 61)){
                lex.push_back(value);
                value = "";
                value += current;
            }
            // '='
            else if (current == 61){
                lex.push_back(value);
                value = "";
                value += current;
            }
            // ','
            else if (current == 44){
                lex.push_back(value);
                value = "";
                value += current;
            }else {
                value += current;
            }
            prev = current;

        }
    }
  //  mergeIfNeeded(&lex);
    this->vecOfExpressions = lex;
}

vector<string> LexerParser::lexer(const string &command) {
    vector <string> listOfCommands;
    //vector <string> vecOfExpressions;

    if (command.rfind(RUN, 0) == 0){
        //listOfCommands = loadfile(extractFileName(command));
        this->vecOfExpressions = loadfile(extractFileName(command)) ;
    } else {
        listOfCommands.push_back(command);
    }

    for (auto it = listOfCommands.begin() ; it != listOfCommands.end(); ++it) {
        // split the data by white spaces
        istringstream iss((*it));
        for (string s; iss >> s;) {
            (this->vecOfExpressions).push_back(s);
        }
    }
    lexByValue();

    return this->vecOfExpressions;
}

void LexerParser::parser() {
    vector<string>::iterator it = vecOfExpressions.begin();
    CommandExpressionFactory commandExpfac = CommandExpressionFactory();
    for ( ;it != getVecOfExpressions().end(); (++it)) {
        Expression* tempExp = commandExpfac.createExpression((it));
        tempExp->calculate();
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