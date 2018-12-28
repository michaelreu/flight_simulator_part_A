

#ifndef SEMPROJECT_BINARYEXPRESSION_H
#define SEMPROJECT_BINARYEXPRESSION_H
#define TRUE 1
#define FALSE 0
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

class Mult : public BinaryExpression  {
public:
    Mult(Expression* leftEx, Expression* rightEx):BinaryExpression(leftEx,rightEx){}
    virtual double calculate() {
        return (getLeftExpression()->calculate() * getRightExpression()->calculate());
    }
};

class Div : public BinaryExpression  {
public:
    Div(Expression* leftEx, Expression* rightEx):BinaryExpression(leftEx,rightEx){};

    virtual double calculate() {
        return (getLeftExpression()->calculate() / getRightExpression()->calculate());
    }
};

class Plus : public BinaryExpression  {
public:
    Plus(Expression* leftEx, Expression* rightEx):BinaryExpression(leftEx,rightEx){}
    virtual double calculate() {
        return (getLeftExpression()->calculate() + getRightExpression()->calculate());
    }
};

class Minus : public BinaryExpression  {
public:
    Minus(Expression* leftEx, Expression* rightEx):BinaryExpression(leftEx,rightEx){}
    virtual double calculate() {
        return (getLeftExpression()->calculate() - getRightExpression()->calculate());
    }
};

class Equal : public BinaryExpression  {
public:
    Equal(Expression* leftEx, Expression* rightEx):BinaryExpression(leftEx,rightEx){}
    virtual double calculate(){
        double left = getLeftExpression()->calculate();
        double right = getRightExpression()->calculate();
        if ( left == right ) {
            return TRUE;
        }
        return FALSE;
    }
};

class LessThen : public BinaryExpression  {
public:
    LessThen(Expression* leftEx, Expression* rightEx):BinaryExpression(leftEx,rightEx){}

    virtual double calculate(){
        double left = getLeftExpression()->calculate();
        double right = getRightExpression()->calculate();
        if ( left < right ) {
            return TRUE;
        }
        return FALSE;
    }
};

class GreaterThen : public BinaryExpression  {
public:
    GreaterThen(Expression* leftEx, Expression* rightEx):BinaryExpression(leftEx,rightEx){}
    virtual double calculate(){
        double left = getLeftExpression()->calculate();
        double right = getRightExpression()->calculate();
        if ( left > right ) {
            return TRUE;
        }
        return FALSE;
    }
};


#endif //SEMPROJECT_BINARYEXPRESSION_H
