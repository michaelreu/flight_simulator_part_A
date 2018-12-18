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
    map<string, double> valuesMap;
    map<string, string> destinationMap;

public:
    SymbolTable () = default;
    const map<string, double> &getValuesMap() const;
    const map<string, string> &getDestinationMap() const;
};


#endif //INC_14_12_12_46_VARIABLESMAP_H
