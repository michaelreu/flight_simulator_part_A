
#ifndef PROJECTPART1_OPENSERVERCOMMAND_H
#define PROJECTPART1_OPENSERVERCOMMAND_H

#define NUM_OF_PARAM 3
#define PARAMETERS_NUMBER_EXCEPTION "not enough parameters"

#include "Command.h"
#include "Reader.h"
//#include "../expression/StrToDoubleClass.h"
#include <vector>
#include <string>

using namespace std;


class OpenServerCommand: public Command {
private:
    vector<string> *dataVector;
    double extractDoubleFromString(string &s);
    double getNextDoubleInVector1(vector<string> *data);

public:
    OpenServerCommand(vector<string> *dataV);
    vector<string> *getDataVector() const;
    virtual void execute();

};


#endif //PROJECTPART1_OPENSERVERCOMMAND_H
