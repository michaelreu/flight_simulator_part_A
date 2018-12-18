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

Utils::Type Utils::getType(int numOfType) {
    switch (numOfType) {
        case 1:
            return Type::NUMBER;
            break;
        case 2:
            return Type::OPERATOR;
            break;
        case 3:
            return Type::LEFT_PARENTHESES;
            break;
        case 4:
            return Type::RIGHT_PARENTHESES;
            break;
        default:
            return Type ::UNKONWN;
            break;
    }

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