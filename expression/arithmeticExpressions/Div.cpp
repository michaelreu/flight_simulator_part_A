
#include "Div.h"
Div::Div(Expression* leftEx, Expression* rightEx):BinaryExpression(leftEx,rightEx){}

double Div::calculate() {
    return (getLeftExpression()->calculate() / getRightExpression()->calculate());
}