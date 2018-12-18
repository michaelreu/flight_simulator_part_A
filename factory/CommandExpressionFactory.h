
#ifndef INC_14_12_12_46_COMMANDEXPRESSIONFACTORY_H
#define INC_14_12_12_46_COMMANDEXPRESSIONFACTORY_H


#include "ExpressionFactory.h"
#include <vector>

using namespace std;

class CommandExpressionFactory {
private:
    ExpressionFactory expressionNumberCreator;

public:
    CommandExpressionFactory();

    virtual Expression* createExpression(vector<string> *dataVector) = 0;
    double extractDoubleFromString(string &s);
    string getNextDoubleInVector(vector<string> *dataVector);

};


#endif //INC_14_12_12_46_COMMANDEXPRESSIONFACTORY_H
