
#include "Plus.h"
Plus::Plus(Expression* leftEx, Expression* rightEx):BinaryExpression(leftEx,rightEx){}

double Plus::calculate() {
    return (getLeftExpression()->calculate() + getRightExpression()->calculate());
}
