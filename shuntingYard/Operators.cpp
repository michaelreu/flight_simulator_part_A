#include "Operators.h"
Operators::Operators(const char op) {
    this->operation = op;
}
char Operators::getOperation() const {
    return this->operation;
}
string Operators::getNumOrOperationExp() {
    string s;
    s+=operation;
    return s;
}