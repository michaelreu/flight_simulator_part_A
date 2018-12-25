

#ifndef SEMPROJECT_EXPRESSION_H
#define SEMPROJECT_EXPRESSION_H
#define TRUE 1
#define FALSE 0

#include <cstdlib>
#include <string>

using namespace std;
class Expression {
public:
    virtual double calculate() = 0;

    virtual ~Expression() = default;
};


#endif //SEMPROJECT_EXPRESSION_H
