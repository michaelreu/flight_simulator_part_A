
#include "GreaterThen.h"
GreaterThen::GreaterThen(Expression* leftEx, Expression* rightEx):BinaryExpression(leftEx,rightEx){}

GreaterThen::GreaterThen(double leftNum, double rightNum):BinaryExpression(new Num(leftNum),new Num(rightNum)) {}

GreaterThen::GreaterThen(double leftNum, Expression* rightEx):BinaryExpression(new Num(leftNum),rightEx) {}

GreaterThen::GreaterThen(Expression* leftEx, double rightNum):BinaryExpression(leftEx,new Num(rightNum)) {}

double GreaterThen::calculate() {
    return (getLeftExpression()->calculate() > getRightExpression()->calculate());
}