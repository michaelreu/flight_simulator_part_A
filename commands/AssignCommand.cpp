
#include "Command.h"
/**
 * constructor
 * @param symTable symbol table
 * @param varToAdd var to add to the map
 * @param dest path to simulator
 */
AssignCommand::AssignCommand(SymbolTable* &symTable, const string &varToAdd, const string &dest) {
    this->addValue = false;
    this->symTbl = symTable;
    this->var = varToAdd;
    this->dest = dest;
}

/**
 * constructor
 * @param symTable symbol table
 * @param expFac expression factory for building the new value
 * @param varToAdd var to add to the map
 * @param it next value
 */
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

/**
 * evaluate the new value and update the maps
 */
void AssignCommand::execute() {
    // value case
    if (this->addValue) {
        Expression* tempExp = expressionFactory->createExpression(this->it);
        value = tempExp->calculate();
        symTbl->addValuesToMap(var,value);
        delete(tempExp);
        tempExp = nullptr;
    // path case
    } else {
        symTbl->addDestinationToMap(var, dest);
    }
}

