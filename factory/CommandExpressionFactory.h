//
// Created by tamir on 18/12/18.
//

#ifndef INC_14_12_12_46_COMMANDEXPRESSIONFACTORY_H
#define INC_14_12_12_46_COMMANDEXPRESSIONFACTORY_H


#include "FactoryInter.h"
using namespace std;

class CommandExpressionFactory : public FactoryInter{
private:
    string expressionStr;

public:
    CommandExpressionFactory(const string &strOfExpression);

    virtual Expression* createExpression()=0;

};


#endif //INC_14_12_12_46_COMMANDEXPRESSIONFACTORY_H
