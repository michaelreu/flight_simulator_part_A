#include "Command.h"
DefineVarCommand::DefineVarCommand(SymbolTable* &symTable, const string &key) {
    this->symTbl = symTable;
    this->var = key;
}
/**
 * init new var on var table
 */
void DefineVarCommand::execute() {
    symTbl->initVar(var);
}