#include "LessThen.h"

LessThen::LessThen(Expression* leftEx, Expression* rightEx):BinaryExpression(leftEx,rightEx){}


double LessThen::calculate() {
    double left = getLeftExpression()->calculate();
    double right = getRightExpression()->calculate();
    if ( left < right ) {
        return TRUE;
    }
    return FALSE;
}