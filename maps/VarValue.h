//
// Created by tamir on 20/12/18.
//

#ifndef INC_14_12_12_46_VARVALUE_H
#define INC_14_12_12_46_VARVALUE_H


class VarValue {
private:
    double value;
    bool isInitialize;
public:
    VarValue();
    VarValue(double val);
    bool isVarInitialized();
    double getValue();
};


#endif //INC_14_12_12_46_VARVALUE_H
