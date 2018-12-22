//
// Created by tamir on 19/12/18.
//

#include "AssignCommand.h"
AssignCommand::AssignCommand(SymbolTable* &symTable,const string &varToAdd, double valueToAdd) {
    this->addValue = true;
    this->symTbl = symTable;
    this->var = varToAdd;
    this->value = valueToAdd;
}

AssignCommand::AssignCommand(SymbolTable* &symTable, const string &varToAdd, const string &dest) {
    this->addValue = false;
    this->symTbl = symTable;
    this->var = varToAdd;
    this->dest = dest;
}
void AssignCommand::execute() {
    if (this->addValue) {
        symTbl->addValuesToMap(var,value);
    } else {
        symTbl->addDestinationToMap(var, dest);

    }
    //need to add to the map
}

