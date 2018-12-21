//
// Created by tamir on 20/12/18.
//

#ifndef INC_14_12_12_46_PRINTCOMMAND_H
#define INC_14_12_12_46_PRINTCOMMAND_H
#define FIRST 1
#include <string>
#include "Command.h"
#include "../factory/ExpressionFactory.h"

using namespace std;
class PrintCommand : public Command {
private:
    ExpressionFactory* expFactory;
    string strToPrint;
    //const SymbolTable* symTbl;

    bool isInQoutes();

public:
    PrintCommand(ExpressionFactory* expFac, string &str);

    virtual void execute();
};


#endif //INC_14_12_12_46_PRINTCOMMAND_H
