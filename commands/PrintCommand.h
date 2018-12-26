//
// Created by tamir on 20/12/18.
//

#ifndef INC_14_12_12_46_PRINTCOMMAND_H
#define INC_14_12_12_46_PRINTCOMMAND_H
#define FIRST 1
#include "Command.h"

using namespace std;
class PrintCommand : public Command {
private:
    ExpressionFactory* expFactory;
    string strToPrint;
    bool isInQoutes();

public:
    PrintCommand(ExpressionFactory* expFac, string &str);
    virtual void execute();
    virtual ~PrintCommand() = default;
};


#endif //INC_14_12_12_46_PRINTCOMMAND_H
