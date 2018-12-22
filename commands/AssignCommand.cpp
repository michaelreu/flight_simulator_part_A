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

AssignCommand::AssignCommand(SymbolTable* &symTable, ExpressionFactory *&expFac, const string &varToAdd, vector<string>::iterator &it) {
    //when executing can use those params
    this->addValue = true;
    this->expressionFactory = expFac;
    this->var = varToAdd;
    this->symTbl = symTable;
    this->it = it;
    //Expression* temp = expressionFactory->createExpression(it);
    //this->value = temp->calculate();
}

void AssignCommand::execute() {
    if (this->addValue) {
        Expression* tempExp = expressionFactory->createExpression(this->it);
        value = tempExp->calculate();
        symTbl->addValuesToMap(var,value);
    } else {
        symTbl->addDestinationToMap(var, dest);
    }
    //need to add to the map
}

