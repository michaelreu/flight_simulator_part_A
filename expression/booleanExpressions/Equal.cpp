#include "Equal.h"
Equal::Equal(Expression* leftEx, Expression* rightEx):BinaryExpression(leftEx,rightEx){}

double Equal::calculate() {
    if (getLeftExpression()->calculate() == getRightExpression()->calculate()) {
        return TRUE;
    }
    return FALSE;
}