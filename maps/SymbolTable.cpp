#include "SymbolTable.h"
/*
map<const string, double> &SymbolTable::getValuesMap() {
    return valuesMap;
}

 const map<const string, const string> &SymbolTable::getDestinationMap() const {
    return destinationMap;
}
*/
void SymbolTable::setVar(const string &key) {
    valuesMap.insert({key,0});
    destinationMap.insert({key, ""});
}
void SymbolTable::addValuesToMap(const string &key, double value) {
    //valuesMap.insert(pair<const string, double>(key,value));
    valuesMap.at(key) = value;
}

void SymbolTable::addDestinationToMap(string &key, string &dest) {
    destinationMap.at(key) = dest;
}

bool SymbolTable::isVarInMap(const string &key) {
    return ((destinationMap.find(key) != destinationMap.end()) && (valuesMap.find(key)) != valuesMap.end());
}