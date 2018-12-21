//
// Created by tamir on 21/12/18.
//

#include "Equal.h"
Equal::Equal(Expression* leftEx, Expression* rightEx):BinaryExpression(leftEx,rightEx){}

Equal::Equal(double leftNum, double rightNum):BinaryExpression(new Num(leftNum),new Num(rightNum)) {}

Equal::Equal(double leftNum, Expression* rightEx):BinaryExpression(new Num(leftNum),rightEx) {}

Equal::Equal(Expression* leftEx, double rightNum):BinaryExpression(leftEx,new Num(rightNum)) {}

double Equal::calculate() {
    return (getLeftExpression()->calculate() == getRightExpression()->calculate());
}