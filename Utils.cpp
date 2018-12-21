//
// Created by tamir on 13/12/18.
//

#include "Utils.h"
#include <algorithm>
/**
 * @param c is a char from a string
 * @return true if char is digit 0-9
 */
bool Utils::isDigit(const char c) {
    return ((c >= MIN_DIGIT_ASCII) && (c <= MAX_DIGIT_ASCII));
}
bool Utils::isLetter(char c) {
    return (((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122)) || c == 95);
}

int Utils::charToInt(const char c) {
    if (isDigit(c)) {
        return (c - MIN_DIGIT_ASCII);
    } else {
        //throw exception
    }
}

/**
 * @param c is a char from a string
 * @return true if the char is { '(' , ')' , '*' , '+' , '-' , '.' , '/' }
 */
bool Utils::isShunYardOperation(const char c) {
    return  ( (c >= MIN_OPERATION_ASCII) && (c <= MAX_OPERATION_ASCII) && (c!=44) );
}

bool Utils::isOperator(char c) {
    return (((c >= 42) && (c <= 43)) || ((c >= 45) && (c <= 47)));
}

bool Utils::isValidVarChar(char c) {
    return ((isLetter(c))||(isDigit(c))||(c=='_'));
}
bool Utils::isStrDouble(const string str) {
    bool hasDot = false;
    for(const auto* it = str.c_str(); *it; ++it) {
        if (((*it) == DOT_CHAR) && (hasDot)) {
            return false;

        } else if ((*it) == DOT_CHAR) {
            hasDot = true;
        }
        if ((!isDigit(*it)) && ((*it) != DOT_CHAR)) {
            return false;
        }
    }
    return true;
}
bool Utils::isBooleanOperator(char c) {
    return ((c==NOT_CHAR)||(c==GREATER_CHAR)||(c==LESS_CHAR));
}

int Utils::findBoolExpression(string &condition) {
    int conIndex = (int)condition.find(GREATER_CHAR);
    //if ((int)condition.find(LESS_CHAR) > co)
}
string Utils::getStringOfOperation(string &condition) {
    string con = condition , boolExpOperator;
    int boolExpNum = 0, diffOfParents = 0;
    bool onlyOneEqualChar = false;
    for(const auto* it = con.c_str(); *it; ++it) {
        if ((*it)==LEFT_PARENTHESES) {
            ++diffOfParents;
        } else if ((*it)==RIGHT_PARENTHESES) {
            if ((--diffOfParents)<0) {
                throw PARENT_ERR;
            }
        } else if ((isValidVarChar(*it))||((*it)==DOT_CHAR)) {
            continue;
        } else if (boolExpNum==1) {
            if ((*it)==EQUAL_CHAR) {
                onlyOneEqualChar = false;
                boolExpOperator+=(*it);
                ++boolExpNum;
                //means it's not - (, ), letter, digit, dot, = , then it's not valid condition
            } else {
                return "";
            }
        } else if ((isBooleanOperator(*it)) && (boolExpNum == 0)) {
            boolExpOperator+=(*it);
            ++boolExpNum;
        } else if (((*it) == EQUAL_CHAR) && (boolExpNum == 0)) {
            ++boolExpNum;
            boolExpOperator+=(*it);
            onlyOneEqualChar = true;
        } else {
            return "";
        }
    }
    if (onlyOneEqualChar) {
        return "";
    }
    return boolExpOperator;
}