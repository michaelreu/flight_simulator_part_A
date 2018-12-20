//
// Created by tamir on 20/12/18.
//

#include "PrintCommand.h"
PrintCommand::PrintCommand(SymbolTable *&symbolTable, string &str) {
    this->symTbl = symbolTable;
    this->strToPrint = str;
}

void PrintCommand::execute() {
    if (strToPrint[0] == '\"') {

    }
}