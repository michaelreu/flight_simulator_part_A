//
// Created by tamir on 18/12/18.
//

#include "SymbolTable.h"

const map<string, double> &SymbolTable::getValuesMap() const {
    return valuesMap;
}

const map<string, string> &SymbolTable::getDestinationMap() const {
    return destinationMap;
}
