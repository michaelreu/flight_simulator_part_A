//
// Created by tamir on 20/12/18.
//

#include "VarValue.h"
VarValue::VarValue() {
    this->value = 0;
    this->isInitialize = false;
}
VarValue::VarValue(double val) {
    this->value = val;
    this->isInitialize = true;
}
bool VarValue::isVarInitialized() {
    return this->isInitialize;
}

double VarValue::getValue() {
    return this->value;
}