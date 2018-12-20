#include "LexerParser.h"

using namespace std;

const vector<string> &LexerParser::getVecOfExpressions() const {
    return this->vecOfExpressions;
}

void LexerParser::loadfile(const string& fileName){
    //regex numPattern();
    string expression;
    vector<string> dataFromFile;
    ifstream myFile(fileName);
    if (myFile.is_open()) {
        while (getline(myFile, expression)) {
            dataFromFile.push_back(expression);
        }
        vector<string>::iterator it = dataFromFile.begin();
        for ( ;it != dataFromFile.end(); (++it)) {
            string temp(*(it));
            istringstream iss(temp);
            for(string temp; iss >> temp; ) {
                this->vecOfExpressions.push_back(temp);
            }
            this->vecOfExpressions.push_back("\n");
            }

    }
    myFile.close();
}


void LexerParser::lexByValue(){
    bool inQuoteFlag = false;
    vector<string> lex;
    char prev;
    string value;
    vector<string>::iterator it = this->vecOfExpressions.begin();
    for ( ;it != getVecOfExpressions().end(); (++it)) {
        if ((*it) == "\n"){
            if(value != "") {
                lex.push_back(value);
                value = "";
                prev = ' ';
            }
            continue;
        }
        for (int i = 0; i < (*it).size(); i++){
            char current = ((*it)[i]);
            //if we are not in quote
            if (inQuoteFlag == false) {
                // char after char
                if ((utils.isLetter(current)) && (utils.isLetter(prev))) {
                    // If they are in a different cell
                    if (i == 0) {
                        lex.push_back(value);
                        value = "";
                        value += current;
                    } else {
                        value += current;
                    }

                }
                    // char after digit
                else if ((utils.isLetter(current)) && (utils.isDigit(prev))) {
                    value += current;

                }
                    // char after operator
                else if ((utils.isLetter(current)) && (utils.isOperator(prev))) {
                    value += current;

                }
                    // char after '='
                else if ((utils.isLetter(current)) && (prev == 61)) {
                    lex.push_back(value);
                    value = "";
                    value += current;
                }
                    // digit after char
                else if ((utils.isDigit(current)) && (utils.isLetter(prev))) {
                    // If they are in a different cell
                    if (i == 0) {
                        lex.push_back(value);
                        value = "";
                        value += current;
                    } else {
                        value += current;
                    }
                }
                    // digit after digit
                else if ((utils.isDigit(current)) && (utils.isDigit(prev))) {
                    // If they are in a different cell
                    if (i == 0) {
                        lex.push_back(value);
                        value = "";
                        value += current;
                    } else {
                        value += current;
                    }
                }
                    // digit after operator
                else if ((utils.isDigit(current)) && (utils.isOperator(prev))) {
                    value += current;
                }
                    // digit after '='
                else if ((utils.isDigit(current)) && (prev == 61)) {
                    lex.push_back(value);
                    value = "";
                    value += current;
                }
                    // operator after char
                else if ((utils.isOperator(current)) && (utils.isLetter(prev))) {
                    value += current;

                }
                    // operator after digit
                else if ((utils.isOperator(current)) && (isdigit(prev))) {
                    value += current;

                }
                    // operator after operator
                else if ((utils.isOperator(current)) && (utils.isOperator(prev))) {
                    value += current;

                }
                    // operator after '='
                else if ((utils.isOperator(current)) && (prev == 61)) {
                    lex.push_back(value);
                    value = "";
                    value += current;
                }
                // '='
                else if ((current == 61)||(prev == 61)) {
                    lex.push_back(value);
                    value = "";
                    value += current;
                }
                // '('
                else if ((current == 34) || (current == 123)) {
                    lex.push_back(value);
                    value = "";
                    value += current;
                    inQuoteFlag = true;
                }
                    // ','
                else if (current == 44) {
                    lex.push_back(value);
                    value = "";
                    value += current;
                } else {
                    value += current;
                }
            // if we in quote
            }else{
                // If we got to the end of the quote
                if (current == 34) {
                    value += current;
                    lex.push_back(value);
                    value = "";
                    inQuoteFlag = false;
                // Push to the same cell
                }else{
                    value += current;
                }
            }
                prev = current;
        }
    }
    if (value != ""){
        lex.push_back(value);
    }
    this->vecOfExpressions = lex;
}

vector<string> LexerParser::lexer(const string &command) {
    vector <string> listOfCommands;
    listOfCommands.push_back(command);
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
