//
// Created by tamir on 20/12/18.
//

#include <iostream>
#include "PrintCommand.h"
PrintCommand::PrintCommand(ExpressionFactory* expFac, string &str) {
    this->expFactory = expFac;
    this->strToPrint = str;
}
bool PrintCommand::isInQoutes() {
    if ((strToPrint[0] == '\"') && (strToPrint[strToPrint.size()-1] == '\"')) {
        strToPrint = strToPrint.substr(1,strToPrint.size()-2);
    }
}

void PrintCommand::execute() {
    if (isInQoutes()) {
        cout<< strToPrint << endl;
    }
}