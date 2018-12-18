#ifndef INC_14_12_12_46_FACTORYINTER_H
#define INC_14_12_12_46_FACTORYINTER_H


#include "../expression/Expression.h"
#include <string>
#include <vector>

using namespace std;

class FactoryInter {
public:
    virtual Expression* createExpression(vector<string> *dataVec)=0;
};

#endif //INC_14_12_12_46_FACTORYINTER_H
