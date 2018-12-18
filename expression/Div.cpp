

#include "Div.h"
Div::Div(Expression* leftEx, Expression* rightEx):BinaryExpression(leftEx,rightEx){}

Div::Div(double leftNum, double rightNum):BinaryExpression(new Num(leftNum),new Num(rightNum)) {}

Div::Div(double leftNum, Expression* rightEx):BinaryExpression(new Num(leftNum),rightEx) {}

Div::Div(Expression* leftEx, double rightNum):BinaryExpression(leftEx,new Num(rightNum)) {}

double Div::calculate() {
    return (getLeftExpression()->calculate() / getRightExpression()->calculate());
}