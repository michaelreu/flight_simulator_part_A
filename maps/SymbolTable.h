//
// Created by tamir on 18/12/18.
//

#ifndef INC_14_12_12_46_VARIABLESMAP_H
#define INC_14_12_12_46_VARIABLESMAP_H

#include <string>
#include <map>
#include <vector>
#include "VarValue.h"

using namespace std;
class VarValue;
class SymbolTable {
private:
    //key - var, value - double, bool initialized
    map<const string, VarValue> valuesMap;
    //key - var, value - path
    map<string, string> destinationMap;
    //each path has number of parameters that can be mapped to it
    map<string,vector<string>> bindMap;
    //vector of the changes
    vector<string> changeVec;

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
