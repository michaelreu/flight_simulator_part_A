//
// Created by tamir on 19/12/18.
//

#include "DefineVarCommand.h"
DefineVarCommand::DefineVarCommand(SymbolTable* &symTable, const string &key) {
    this->symTbl = symTable;
    this->var = key;
}

void DefineVarCommand::execute() {
    symTbl->setVar(var);
}