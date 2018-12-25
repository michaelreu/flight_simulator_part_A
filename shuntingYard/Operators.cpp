

#include "Operators.h"
Operators::Operators(const char op) {
    this->operation = op;
}
/*
 * the string of the operation
 */
string Operators::getNumOrOperationExp() {
    string s;
    s+=operation;
    return s;
}
