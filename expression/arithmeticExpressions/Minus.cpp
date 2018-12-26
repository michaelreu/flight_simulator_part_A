
#include "Minus.h"
Minus::Minus(Expression* leftEx, Expression* rightEx):BinaryExpression(leftEx,rightEx){}

double Minus::calculate() {
    return (getLeftExpression()->calculate() - getRightExpression()->calculate());
}
