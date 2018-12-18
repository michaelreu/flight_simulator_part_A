//
// Created by tamir on 07/12/18.
//

#include "UnaryExpression.h"
UnaryExpression::UnaryExpression(Expression* exp) {
    this->expression = exp;
}
Expression* UnaryExpression::getExpression() {
    return this->expression;
}