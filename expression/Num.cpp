

#include "Num.h"
//Ctor
Num::Num(double num) {
    this->num=num;
}

Num::Num(int num) {
    this->num=num;
}
Num::Num(const char *num) {
    this->num = strtol(num, nullptr,DECIMAL_BASE);
}
double Num::getNum() const {
    return this->num;
}

void Num::setNum(double newNum) {
    this->num=newNum;
}

double Num::calculate() {
    return getNum();
}

string Num::getNumOrOperationExp() {
    return  to_string(this->num);
}
