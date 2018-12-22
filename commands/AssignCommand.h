//
// Created by tamir on 19/12/18.
//

#ifndef INC_14_12_12_46_ASSIGNCOMMAND_H
#define INC_14_12_12_46_ASSIGNCOMMAND_H


#include "Command.h"
#include "../maps/SymbolTable.h"

/*
 * responsible for assigning to our SymbolTable the key, value of specific var
 */
class AssignCommand : public Command {
private:
    SymbolTable* symTbl;
    string var;
    string dest;
    double value;
    bool addValue = true;

public:
    /*
     * AssignCommand can be built with numeric value, or a destination path.
     */
    AssignCommand(SymbolTable* &symTable,const string &varToAdd, double valueToAdd);
    AssignCommand(SymbolTable* &symTable,const string &varToAdd, const string &dest);
    virtual void execute();

    virtual ~AssignCommand()= default;
    //void addToSymbolTable();
};


#endif //INC_14_12_12_46_ASSIGNCOMMAND_H
