

#ifndef INC_14_12_12_46_CHECKINPUTS_H
#define INC_14_12_12_46_CHECKINPUTS_H

#define IP_REGEX "^([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])$"
#define NAME_REGEX "[a-zA-Z_][a-zA-Z_0-9]*"
#define MAX_PORT_VALUE 65535

#include <regex>
#include <string>

using namespace std;

class CheckInputs {
public:
    bool checkNameOfVar(string &s);
    bool checkIP(const char* ip);
    bool checkPort(int port);
    bool checkHertz(int hertz);
    bool checkTime(int time);
    ~CheckInputs() = default;

};


#endif //INC_14_12_12_46_CHECKINPUTS_H
