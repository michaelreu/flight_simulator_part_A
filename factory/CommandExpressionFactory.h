
#ifndef INC_14_12_12_46_COMMANDEXPRESSIONFACTORY_H
#define INC_14_12_12_46_COMMANDEXPRESSIONFACTORY_H


#include "FactoryInter.h"
#include "ExpressionFactory.h"
#include <vector>

using namespace std;

class CommandExpressionFactory : public FactoryInter{
private:
    ExpressionFactory expressionNumberCreator;

public:
    CommandExpressionFactory();


    virtual Expression* createExpression(vector<string> *dataVector) = 0;
    double extractDoubleFromString(string &s);
    double getNextDoubleInVector1(vector<string> *dataVector);

};


#endif //INC_14_12_12_46_COMMANDEXPRESSIONFACTORY_H
