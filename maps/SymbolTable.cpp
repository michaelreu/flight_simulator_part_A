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

void SymbolTable::addValuesToMap(string key, double value) {
    valuesMap[key] = value;
}

void SymbolTable::addDestinationToMap(string key, double value) {
    valuesMap[key] = value;
}
