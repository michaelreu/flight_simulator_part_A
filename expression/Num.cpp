
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

double Num::calculate() {
    return getNum();
}


