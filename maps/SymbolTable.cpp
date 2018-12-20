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
}
void SymbolTable::addValuesToMap(const string &key, double value) {
    //valuesMap.insert(pair<const string, double>(key,value));
    valuesMap[key] = value;
}

void SymbolTable::addDestinationToMap(const string &key, const string &dest) {
    //destinationMap.insert(pair<const string,const string>(key,dest));
    destinationMap[key] = dest;
    //destinationMap[key] = dest;
}