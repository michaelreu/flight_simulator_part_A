//
// Created by tamir on 19/12/18.
//

#ifndef INC_14_12_12_46_DEFINEVARCOMMAND_H
#define INC_14_12_12_46_DEFINEVARCOMMAND_H


#include "../Command.h"

class DefineVarCommand : public Command {
private:
    SymbolTable* symTbl;
    string var;

public:
    DefineVarCommand(SymbolTable* &symTable, const string &key);
    virtual void execute();
    virtual ~DefineVarCommand() = default;
};

#endif //INC_14_12_12_46_DEFINEVARCOMMAND_H
