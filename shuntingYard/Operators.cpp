//
// Created by tamir on 14/12/18.
//

#include "Operators.h"
Operators::Operators(const char op) {
    this->operation = op;
}

 string Operators::getNumOrOperationExp() {
    string s;
    s+=operation;
    return s;
}