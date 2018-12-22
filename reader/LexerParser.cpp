#include "LexerParser.h"

using namespace std;

const vector<string> &LexerParser::getVecOfExpressions() const {
    return this->vecOfExpressions;
}

void LexerParser::loadfile(const string& fileName){

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


bool LexerParser::parnthesesCase(char prev){
    return !((utils.isOperator(prev)) || (prev == LEFT_PARENTHESES));
}

bool LexerParser::charCase(char prev, int i){
    if (utils.isLetter(prev) || utils.isDigit(prev)){
       return (i == 0);
    }
    if (utils.isOperator(prev)|| prev == LEFT_PARENTHESES){
        return false;
    }
    if (prev == EQUAL){
        return true;
    }
}

bool isSeparatingChar (char check){
    return ((check == EQUAL) || (check == LEFT_CURLY_PARENT_CHAR) || (check == COMMA));
}


void LexerParser::lexByValue(){
    //string ifStr = "if";
    //string whileStr = "while";
    bool inQuoteFlag = false;
    vector<string> lex;
    char prev;
    string value;
    vector<string>::iterator it = this->vecOfExpressions.begin();
    for ( ;it != getVecOfExpressions().end(); (++it)) {
        // and of line case
        if ((*it) == "\n"){
            if(value != "") {
                lex.push_back(value);
                value = "";
                prev = ' ';
            }
            inQuoteFlag = false;
            continue;
        }

        // read char by char
        for (int i = 0; i < (*it).size(); i++){
            char current = ((*it)[i]);

            //if we are not in quote
            if (inQuoteFlag == false) {
                // condition case
                if ((value == IF_STR) || (value == WHILE_STR)) {
                    lex.push_back(value);
                    value = "";
                    value += current;
                    inQuoteFlag = true;
                    continue;
                }

                //char or number
                if(utils.isLetter(current) || (utils.isDigit(current))) {
                    if (charCase(prev, i)) {
                        lex.push_back(value);
                        value = "";
                        value += current;
                    } else {
                        value += current;
                    }
                }
                // operator case
                else if (utils.isOperator(current)) {
                    if (prev == EQUAL){
                        lex.push_back(value);
                        value = "";
                        value += current;
                    }else{
                        value += current;
                    }
                }

                // '='
                else if ((isSeparatingChar(current)) || (isSeparatingChar(prev))) {
                    lex.push_back(value);
                    value = "";
                    value += current;
                }
                // '('
                else if (current == LEFT_PARENTHESES) {
                    if (parnthesesCase(prev)) {
                        lex.push_back(value);
                        value = "";
                        value += current;
                    } else {
                        value += current;
                    }
                }
                // start of ""
                else if (current == QUOTES_CHAR) {
                    lex.push_back(value);
                    value = "";
                    value += current;
                    inQuoteFlag = true;
                }
                 // defult
                 else {
                    value += current;
                }
            // if we in quote
            }else{
                // If we got to the end of the quote
                if (current == QUOTES_CHAR) {
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
    CommandExpressionFactory* commandExpfac = new CommandExpressionFactory();
    for ( ;it != getVecOfExpressions().end(); (++it)) {
        Expression* tempExp = commandExpfac->createExpression((it));
        tempExp->calculate();
        delete (tempExp);
    }
    delete (commandExpfac);
}
