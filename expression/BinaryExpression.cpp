//
// Created by tamir on 07/12/18.
//

#include "BinaryExpression.h"
BinaryExpression::BinaryExpression(Expression *leftEx, Expression *rightEx) {
    this->left = leftEx;
    this->right = rightEx;
}
Expression* BinaryExpression::getLeftExpression() {
    return this->left;
}

Expression* BinaryExpression::getRightExpression() {
    return this->right;
}