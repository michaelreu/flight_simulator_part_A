//
// Created by tamir on 19/12/18.
//

#ifndef INC_14_12_12_46_EXPRESSIONFACTORY1_H
#define INC_14_12_12_46_EXPRESSIONFACTORY1_H


#include <string>
#include <vector>
#include "../expression/Expression.h"

using namespace std;

class ExpressionFactory1 {

public:
    //Expression* getOpenServerCommand(vector<string>::iterator it);
    //virtual Expression* createExpression(const string &strToExp);
    //virtual Expression* createExpression(vector<string> *dateVec);
    virtual Expression* createExpression(vector<string>::iterator it);

};


#endif //INC_14_12_12_46_EXPRESSIONFACTORY1_H
