

#include "ConnectCommand.h"

ConnectCommand::ConnectCommand(string ip, int port){
    this->ip = ip;
    this->port = port;
}

void ConnectCommand::execute(){
    //connect in some way
}
