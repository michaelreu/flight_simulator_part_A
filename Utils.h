
#ifndef SEMPROJECT_UTILS_H
#define SEMPROJECT_UTILS_H

#include <string>

#define MIN_DIGIT_ASCII 48
#define MAX_DIGIT_ASCII 57
#define MIN_OPERATION_ASCII 40
#define MAX_OPERATION_ASCII 47
#define LEFT_PARENTHESES '('
#define RIGHT_PARENTHESES ')'
#define QUOTES_CHAR 34
#define COMMA 44
#define LEFT_CURLY_PARENT_CHAR 123
#define EQUAL '='

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
    bool isOperation(const char c);
    int charToInt(const char c);
    bool isStrDouble(const string str);
    bool isLetter(char c);
    bool isOperator(char c);
    bool isValidVarChar(char c);
};


#endif //SEMPROJECT_UTILS_H
