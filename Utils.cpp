//
// Created by tamir on 13/12/18.
//

#include "Utils.h"
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
bool Utils::isOperation(const char c) {
    return  ( (c >= MIN_OPERATION_ASCII) && (c <= MAX_OPERATION_ASCII) && (c!=44) );
}

bool Utils::isOperator(char c) {
    return (((c >= 42) && (c <= 43)) || ((c >= 45) && (c <= 47)));
}

bool Utils::isValidVarChar(char c) {
    return ((isLetter(c))||(isDigit(c))||(c='_'));
}
bool Utils::isStrDouble(const string str) {
    bool hasDot = false;
    for(const auto* it = str.c_str(); *it; ++it) {
        if (((*it)=='.') && (hasDot)) {
            return false;

        } else if ((*it)=='.') {
            hasDot = true;
        }
        if ((!isDigit(*it)) && (*it)!='.') {
            return false;
        }
    }
    return true;
}