//
// Created by tamir on 18/12/18.
//

#ifndef INC_14_12_12_46_VARIABLESMAP_H
#define INC_14_12_12_46_VARIABLESMAP_H

#include <string>
#include <map>
#include "VarValue.h"

using namespace std;
class VarValue;
class SymbolTable {
private:
    map<const string, VarValue> valuesMap;
    map<string, string> destinationMap;

public:
    SymbolTable () = default;
    //const map<const string, double> &getValuesMap() const;
    //const map<const string, const string> &getDestinationMap() const;
    void setVar(const string &key);
    void addValuesToMap(const string &key, double value);
    void addDestinationToMap(string &key, string &dest);
    bool isVarInMap(const string &key);
    bool isVarInValueMap(const string &key);
    double getValueOfVar(const string &key);
};

#endif //INC_14_12_12_46_VARIABLESMAP_H
