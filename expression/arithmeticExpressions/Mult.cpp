
#include "Mult.h"
Mult::Mult(Expression* leftEx, Expression* rightEx):BinaryExpression(leftEx,rightEx){}


double Mult::calculate() {
    return (getLeftExpression()->calculate() * getRightExpression()->calculate());
}
