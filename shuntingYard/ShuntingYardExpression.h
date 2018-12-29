
#ifndef INC_14_12_12_46_SHUNTINGYARDEXPRESSION_H
#define INC_14_12_12_46_SHUNTINGYARDEXPRESSION_H

#include <string>
/*
 * this class is the class of the stack template for the shunting yard algorithm
 */
using namespace std;

class ShuntingYardExpression {

public:
    virtual string getNumOrOperationExp() = 0;
    ~ShuntingYardExpression() = default;
};


class ShuntingNum : public ShuntingYardExpression {
private:
    double num;
public:
    ShuntingNum(double sHnum){
        this->num = sHnum;
    }
    virtual string getNumOrOperationExp() {
        return  to_string(this->num);
    }
};


class Operators : public ShuntingYardExpression {
private:
    char operation;
public:
    Operators(const char op){
        this->operation = op;
    }

    virtual string getNumOrOperationExp(){
        string s;
        s+=operation;
        return s;
    }
};

#endif //INC_14_12_12_46_SHUNTINGYARDEXPRESSION_H
