


#include "Plus.h"
Plus::Plus(Expression* leftEx, Expression* rightEx):BinaryExpression(leftEx,rightEx){}

Plus::Plus(double leftNum, double rightNum):BinaryExpression(new Num(leftNum),new Num(rightNum)) {}

Plus::Plus(double leftNum, Expression* rightEx):BinaryExpression(new Num(leftNum),rightEx) {}

Plus::Plus(Expression* leftEx, double rightNum):BinaryExpression(leftEx,new Num(rightNum)) {}


double Plus::calculate() {
    return (getLeftExpression()->calculate() + getRightExpression()->calculate());
}
