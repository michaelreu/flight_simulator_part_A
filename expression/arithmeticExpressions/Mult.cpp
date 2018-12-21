//
// Created by tamir on 07/12/18.
//

#include "Mult.h"
Mult::Mult(Expression* leftEx, Expression* rightEx):BinaryExpression(leftEx,rightEx){}

Mult::Mult(double leftNum, double rightNum):BinaryExpression(new Num(leftNum),new Num(rightNum)) {}

Mult::Mult(double leftNum, Expression* rightEx):BinaryExpression(new Num(leftNum),rightEx) {}

Mult::Mult(Expression* leftEx, double rightNum):BinaryExpression(leftEx,new Num(rightNum)) {}

double Mult::calculate() {
    return (getLeftExpression()->calculate() * getRightExpression()->calculate());
}