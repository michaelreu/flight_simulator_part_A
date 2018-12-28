

#ifndef SEMPROJECT_EXPRESSION_H
#define SEMPROJECT_EXPRESSION_H


#include <cstdlib>
#include <string>

using namespace std;
class Expression {
public:
    virtual double calculate() = 0;

    virtual ~Expression() = default;
};


class Num : public Expression {
private:
    double num;

public:
    //ctor
    Num(double num) {     this->num=num;    }
    Num(int num){       this->num=num;    }
    //getter
    double getNum() const{    return this->num;    }

    virtual double calculate(){ return this->num; }

    virtual ~Num() = default;
};

#endif //SEMPROJECT_EXPRESSION_H
