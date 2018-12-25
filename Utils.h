
#ifndef SEMPROJECT_UTILS_H
#define SEMPROJECT_UTILS_H

#include <string>
#define PARENT_ERR "Error: too many right parentheses"
#define INV_EQUATION_FORMT "ERROR: invalid format of equation"
#define CHAR_NOT_DIGIT "ERROR: cannot convert digit to int because the char is not a digit"

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
#define UNDER_SCR_CHAR 95
#define LOW_Z_CHAR 122
#define LOW_A_CHAR 97
#define CAP_Z_CHAR 90
#define CAP_A_CHAR 65
#define MULT_CHAR '*'
#define PLUS_CHAR '+'
#define MINUS_CHAR '-'
#define DIV_CHAR '/'
#define COMMA_CHAR ','

using namespace std;

struct threadParams {
    pthread_t* serverThread;
    pthread_t* clientThread;
    pthread_mutex_t* mutex;
    int sockfdConnect;
    int sockfdServer;
    bool serverThreadIsRun;
    bool clientThreadIsRun;
};
typedef struct threadParams threadParams;

class Utils {
public:
    bool isDigit (const char c);
    bool isShunYardOperation(const char c);
    int digitCharToInt(const char c);
    bool isStrDouble(const string str);
    bool isLetter(char c);
    bool isOperator(char c);
    bool isValidVarChar(char c);
    bool isBooleanOperator (char c);
    string getStringOfOperation(string &condition);
};


#endif //SEMPROJECT_UTILS_H
