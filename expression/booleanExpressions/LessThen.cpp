//
// Created by tamir on 21/12/18.
//

#include "LessThen.h"
LessThen::LessThen(Expression* leftEx, Expression* rightEx):BinaryExpression(leftEx,rightEx){}

LessThen::LessThen(double leftNum, double rightNum):BinaryExpression(new Num(leftNum),new Num(rightNum)) {}

LessThen::LessThen(double leftNum, Expression* rightEx):BinaryExpression(new Num(leftNum),rightEx) {}

LessThen::LessThen(Expression* leftEx, double rightNum):BinaryExpression(leftEx,new Num(rightNum)) {}

double LessThen::calculate() {
    return (getLeftExpression()->calculate() < getRightExpression()->calculate());
}