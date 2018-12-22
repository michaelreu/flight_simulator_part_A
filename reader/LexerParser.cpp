#include "LexerParser.h"

using namespace std;



LexerParser::LexerParser (){
    this->commandExpfac = new CommandExpressionFactory();
}

const vector<string> &LexerParser::getVecOfExpressions() const {
    return this->vecOfExpressions;
}

void LexerParser::loadfile(const string& fileName){
    string expression;
    vector<string> dataFromFile;
    ifstream myFile(fileName);
    if (myFile.is_open()) {
        // read line by line
        while (getline(myFile, expression)) {
            dataFromFile.push_back(expression);
        }
        vector<string>::iterator it = dataFromFile.begin();
        // each line separated by space
        for ( ;it != dataFromFile.end(); (++it)) {
            string temp(*(it));
            istringstream iss(temp);
            for(string temp; iss >> temp;) {
                // print case - leave the spaces
                if (temp == PRINT_STR){
                    this->vecOfExpressions.push_back((*it));
                    break;
                }
                this->vecOfExpressions.push_back(temp);

            }
            // end of line from file
            this->vecOfExpressions.push_back("\n");
        }
    }
    myFile.close();
}


bool LexerParser::parnthesesCase(char prev){
    return !((utils.isOperator(prev)) || (prev == LEFT_PARENTHESES));
}

bool LexerParser::charCase(char prev, int i){
    // if the prev char is letter or digit
    if (utils.isLetter(prev) || utils.isDigit(prev)){
        // if prev in same cell or not
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
    bool condition = false;
    bool inQuoteFlag = false;
    vector<string> lex;
    char prev;
    string value;
    vector<string>::iterator it = this->vecOfExpressions.begin();
    for ( ;it != getVecOfExpressions().end(); (++it)) {
        // and line case
        if ((*it) == "\n"){
            if (prev == LEFT_CURLY_PARENT_CHAR){
                value.erase(value.size()-1);
                lex.push_back(value);
                value = LEFT_CURLY_PARENT_CHAR;
            }
            if (prev == RIGHT_CURLY_PARENT_CHAR){
                value.erase(value.size()-1);
                if(value != "") {
                    lex.push_back(value);
                }
                value = RIGHT_CURLY_PARENT_CHAR;
            }
            if(value != "") {
                lex.push_back(value);
                value = "";
                prev = ' ';
            }
            // reset the flags and continue to next line
            condition = false;
            inQuoteFlag = false;
            continue;
        }

        // read char by char
        for (int i = 0; i < (*it).size(); i++){
            char current = ((*it)[i]);

            //if we are not in quote or condition
            if ((inQuoteFlag == false) && (condition == false)) {
                // condition case
                if ((value == IF_STR) || (value == WHILE_STR)) {
                    lex.push_back(value);
                    value = "";
                    value += current;
                    condition = true;
                    continue;
                }
                // print case
                if (value == PRINT_STR){
                    lex.push_back(value);
                    value = "";
                    condition = true;
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
                // start of ' " '
                else if (current == QUOTES_CHAR) {
                    lex.push_back(value);
                    value = "";
                    value += current;
                    inQuoteFlag = true;
                }
                 // other char that unrecognized
                 else {
                    value += current;
                }
            // if we in quote or condition
            }else{
                // If we got to the end of the quote
                if ((current == QUOTES_CHAR) &&  (condition == false)){
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
    // command from command line
    for (auto it = listOfCommands.begin() ; it != listOfCommands.end(); ++it) {
        // split the data by white spaces
        istringstream iss((*it));
        for (string s; iss >> s;) {
            // print case
            if (s == PRINT_STR){
                this->vecOfExpressions.push_back((*it));
                break;
            }
            (this->vecOfExpressions).push_back(s);
        }
        this->vecOfExpressions.push_back("\n");
    }
    lexByValue();
    return this->vecOfExpressions;
}

void LexerParser::parser() {
    vector<string>::iterator it = vecOfExpressions.begin();
    // run on all commands
    for ( ;it != getVecOfExpressions().end(); (++it)) {
        // create new expression
        Expression* tempExp = this->commandExpfac->createExpression((it));
        // calculate it
        tempExp->calculate();
        delete (tempExp);
    }
    this->vecOfExpressions.clear();
}

/**
 * distructor
 */
LexerParser::~LexerParser() {
    delete this->commandExpfac;
}
