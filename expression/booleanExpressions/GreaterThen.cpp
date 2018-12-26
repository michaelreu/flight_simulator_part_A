
#include "GreaterThen.h"
GreaterThen::GreaterThen(Expression* leftEx, Expression* rightEx):BinaryExpression(leftEx,rightEx){}

double GreaterThen::calculate() {
    if (getLeftExpression()->calculate() > getRightExpression()->calculate()) {
        return TRUE;
    }
    return FALSE;
}