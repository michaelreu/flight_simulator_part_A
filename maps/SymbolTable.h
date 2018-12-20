//
// Created by tamir on 18/12/18.
//

#ifndef INC_14_12_12_46_VARIABLESMAP_H
#define INC_14_12_12_46_VARIABLESMAP_H

#include <string>
#include <map>
using namespace std;

class SymbolTable {
private:
    map<const string, double> valuesMap;
    map<const string, const string> destinationMap;

public:
    SymbolTable () = default;
    //const map<const string, double> &getValuesMap() const;
    //const map<const string, const string> &getDestinationMap() const;
    void setVar(const string &key);
    void addValuesToMap(const string &key, double value);
    void addDestinationToMap(const string &key,const string &dest);
};

#endif //INC_14_12_12_46_VARIABLESMAP_H
