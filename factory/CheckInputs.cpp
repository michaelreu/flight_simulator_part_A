
#include "CheckInputs.h"

bool CheckInputs::checkNameOfVar(string &s){
    regex ipPattern (NAME_REGEX);
    return  (regex_match (s, ipPattern));
}

bool CheckInputs:: checkIP(const char* ip){
    regex ipPattern (IP_REGEX);
    return  (regex_match (ip, ipPattern));
}

bool CheckInputs:: checkPort(int port){
   return ((port > 0) && (port < MAX_PORT_VALUE));
}

bool CheckInputs:: checkHertz(int hertz){
    return  (hertz >= 0);
}

bool CheckInputs:: checkTime(int time){
    return  (time >= 0);
}