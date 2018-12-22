//
// Created by tamir on 21/12/18.
//

#include <iostream>
#include "LessThen.h"
LessThen::LessThen(Expression* leftEx, Expression* rightEx):BinaryExpression(leftEx,rightEx){}

LessThen::LessThen(double leftNum, double rightNum):BinaryExpression(new Num(leftNum),new Num(rightNum)) {}

LessThen::LessThen(double leftNum, Expression* rightEx):BinaryExpression(new Num(leftNum),rightEx) {}

LessThen::LessThen(Expression* leftEx, double rightNum):BinaryExpression(leftEx,new Num(rightNum)) {}

double LessThen::calculate() {
    double left = getLeftExpression()->calculate();
    double right = getRightExpression()->calculate();
    cout<<"left: "; cout<< left;
    cout<<", right: ";cout<< right << endl;
    if ( left < right ) {
        return TRUE;
    }
    return FALSE;
}