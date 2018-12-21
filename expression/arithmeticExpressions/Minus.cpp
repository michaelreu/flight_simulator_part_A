//
// Created by tamir on 07/12/18.
//

#include "Minus.h"
Minus::Minus(Expression* leftEx, Expression* rightEx):BinaryExpression(leftEx,rightEx){}

Minus::Minus(double leftNum, double rightNum):BinaryExpression(new Num(leftNum),new Num(rightNum)) {}

Minus::Minus(double leftNum, Expression* rightEx):BinaryExpression(new Num(leftNum),rightEx) {}

Minus::Minus(Expression* leftEx, double rightNum):BinaryExpression(leftEx,new Num(rightNum)) {}

double Minus::calculate() {
    return (getLeftExpression()->calculate() - getRightExpression()->calculate());
}