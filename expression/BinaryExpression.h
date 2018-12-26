

#ifndef SEMPROJECT_BINARYEXPRESSION_H
#define SEMPROJECT_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression {

private:
    Expression* left;
    Expression* right;

public:
    BinaryExpression(Expression* leftEx, Expression* rightEx);

    virtual double calculate() = 0;

    Expression* getLeftExpression();

    Expression* getRightExpression();

    ~BinaryExpression() {
        delete(this->left);
        this->left = nullptr;
        delete(this->right);
        this->right = nullptr;
    };


};

#endif //SEMPROJECT_BINARYEXPRESSION_H
