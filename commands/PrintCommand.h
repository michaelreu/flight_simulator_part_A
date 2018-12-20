//
// Created by tamir on 20/12/18.
//

#ifndef INC_14_12_12_46_PRINTCOMMAND_H
#define INC_14_12_12_46_PRINTCOMMAND_H

#include <string>
#include "Command.h"

using namespace std;
class PrintCommand : public Command {
private:
    string strToPrint;
    const SymbolTable* symTbl;

public:
    PrintCommand(SymbolTable* &symbolTable, string &str);
    virtual void execute();
};


#endif //INC_14_12_12_46_PRINTCOMMAND_H
