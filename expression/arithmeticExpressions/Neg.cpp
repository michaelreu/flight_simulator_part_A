//
// Created by tamir on 07/12/18.
//

#include "Neg.h"

Neg::Neg(Expression* exp):UnaryExpression(exp) {}

Neg::Neg(double num):UnaryExpression(new Num(num)) {}

double Neg::calculate() {
    return -1*(getExpression()->calculate());
}