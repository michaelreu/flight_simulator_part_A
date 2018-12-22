

#include "DefineVarCommand.h"
DefineVarCommand::DefineVarCommand(SymbolTable* &symTable, const string &key) {
    this->symTbl = symTable;
    this->var = key;
}

void DefineVarCommand::execute() {
    symTbl->initVar(var);
}