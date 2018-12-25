//
// Created by tamir on 25/12/18.
//

#include "ShuntingNum.h"
ShuntingNum::ShuntingNum(double sHnum) {
    this->num = sHnum;
}
string ShuntingNum::getNumOrOperationExp() {
    return  to_string(this->num);
}