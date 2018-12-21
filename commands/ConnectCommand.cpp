

#include "ConnectCommand.h"

ConnectCommand::ConnectCommand(string ip, int port){
    this->ip = ip;
    this->port = port;
}

bool ConnectCommand::validIP() {
    regex ipPattern
    ("^([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])$");
    return  (regex_match (ip, ipPattern));

}

void ConnectCommand::execute(){
    if(!validIP()) {
        throw INVALID_IP_ADRESS_ERR;
    }
    //connect in some way
}
