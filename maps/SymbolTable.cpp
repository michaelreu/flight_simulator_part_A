#include "SymbolTable.h"
/*
map<const string, double> &SymbolTable::getValuesMap() {
    return valuesMap;
}

 const map<const string, const string> &SymbolTable::getDestinationMap() const {
    return destinationMap;
}
*/
void SymbolTable::initVar(const string &key) {
    valuesMap.insert({key,VarValue()});
    destinationMap.insert({key, ""});
}
void SymbolTable::addValuesToMap(const string &key, double value) {
    //valuesMap.insert(pair<const string, double>(key,value));
    VarValue varVal = VarValue(value);
    valuesMap.at(key) = varVal;
    changedArgsVec.push_back(key);
}

void SymbolTable::addDestinationToMap(string &key, string &dest) {
    string pathDest = dest;
    // type of x = bind y
    if (destinationMap.count(dest) == IN_MAP){
        pathDest = destinationMap[dest];
    }
    destinationMap.at(key) = pathDest;
    bindMap[pathDest].push_back(key);
    changedArgsVec.push_back(key);
}

bool SymbolTable::isVarInMap(const string &key) {
    //return ((destinationMap.find(key) != destinationMap.end()) && (isVarInValueMap(key)));
    //return ((destinationMap.count(key) == IN_MAP) && (isVarInValueMap(key)));
    return ((destinationMap.count(key) == IN_MAP) && (valuesMap.count(key)==IN_MAP));
}



bool SymbolTable::isVarInValueMap(const string &key) {
    if (valuesMap.count(key)==IN_MAP) {
        return ((valuesMap.at(key)).isVarInitialized());
    }
    /*
    if ((valuesMap.find(key)) != valuesMap.end()) {
        return ((valuesMap.at(key)).isVarInitialized());
        //VarValue val = (valuesMap.at(key));
        //return val.isVarInitialized();
    }
    return false;
     */
}

double SymbolTable::getValueOfVar(const string &key) {
    if (isVarInValueMap(key)) {
        return ((valuesMap.at(key)).getValue());
    } else {
        throw "Error: var " + key + "is not initialized";
    }
}
