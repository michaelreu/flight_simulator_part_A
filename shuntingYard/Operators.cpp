//
// Created by tamir on 14/12/18.
//

#include "Operators.h"
Operators::Operators(const char op) {
    this->operation = op;
}
char Operators::getOperation() const {
    return this->operation;
}
