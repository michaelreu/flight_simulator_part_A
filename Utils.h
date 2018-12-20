
#ifndef SEMPROJECT_UTILS_H
#define SEMPROJECT_UTILS_H

#include <string>

#define MIN_DIGIT_ASCII 48
#define MAX_DIGIT_ASCII 57
#define MIN_OPERATION_ASCII 40
#define MAX_OPERATION_ASCII 47
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
    enum Type { UNKONWN = 0, NUMBER, OPERATOR, LEFT_PARENTHESES, RIGHT_PARENTHESES };
    bool isDigit (const char c);
    bool isOperation(const char c);
    int charToInt(const char c);
    Type getType(int numOfType);
    bool isStrDouble(const string str);
    bool isLetter(char c);
    bool isOperator(char c);
    bool isValidVarChar(char c);
};


#endif //SEMPROJECT_UTILS_H
