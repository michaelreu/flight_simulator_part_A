//
// Created by tamir on 20/12/18.
//

#include <iostream>
#include "PrintCommand.h"
PrintCommand::PrintCommand(ExpressionFactory* expFac, string &str) {
    this->expFactory = expFac;
    this->strToPrint = str;
}
/**
 * check if print string or var value
 * @return true or false
 */
bool PrintCommand::isInQoutes() {
    // string case
    if ((strToPrint[0] == '\"') && (strToPrint[strToPrint.size()-1] == '\"')) {
        strToPrint = strToPrint.substr(FIRST,strToPrint.size()-2);
        return true;
    }
    // var case
    return false;
}

/**
 * print
 */
void PrintCommand::execute() {
    // string case
    if (isInQoutes()) {
        cout<< strToPrint << endl;
    // var value case
    } else {

        cout << (expFactory->createExpression(strToPrint))->calculate() << endl;
    }
}