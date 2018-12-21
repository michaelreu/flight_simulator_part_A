
#ifndef SEMPROJECT_UTILS_H
#define SEMPROJECT_UTILS_H

#include <string>

#define MIN_DIGIT_ASCII 48
#define MAX_DIGIT_ASCII 57
#define MIN_OPERATION_ASCII 40
#define MAX_OPERATION_ASCII 47
#define DOT_CHAR '.'
#define LEFT_PARENTHESES '('
#define RIGHT_PARENTHESES ')'
#define EQUAL_CHAR '='
#define GREATER_CHAR '>'
#define LESS_CHAR '<'
#define NOT_CHAR '!'



/*
#define UNKNOWN 0
#define NUM 1
#define OPERATOR 2
#define UNKNOWN 0
#define UNKNOWN 0
*/

using namespace std;

class Utils {
public:
    bool isDigit (const char c);
    bool isShunYardOperation(const char c);
    int charToInt(const char c);
    bool isStrDouble(const string str);
    bool isLetter(char c);
    bool isOperator(char c);
    bool isValidVarChar(char c);
    bool isBooleanOperator (char c);
    int findBoolExpression(string &condition);
    string getStringOfOperation(string &condition);
};


#endif //SEMPROJECT_UTILS_H
