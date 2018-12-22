

#include "ConnectCommand.h"
bool ConnectCommand::shouldStop = false;
ConnectCommand::ConnectCommand(const char* ip, int port, SymbolTable* symTable){
    this->symbolTable = symTable;
    this->ip = ip;
    this->port = port;
    shouldStop = false;
}

bool ConnectCommand::validIP() {
    regex ipPattern (IP_REGEX);
    return  (regex_match (ip, ipPattern));
}
//void ConnectCommand::runUser(const char* ip, const char* port1, SymbolTable* &symbolTable) {
void ConnectCommand::runUser(const char* ip, int port, SymbolTable* symbolTable) {
    double valueOfVar;
    int sockfd, n;
    struct sockaddr_in serverAddress;
    struct hostent *server;
    string tempPath, messageOfSet;
    //int port = stoi(port1);
    char buffer[256];

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(ip);

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    //init the buffer
    bzero((char *) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    //copy the message to buffer
    bcopy((char *)server->h_addr, (char *)&serverAddress.sin_addr.s_addr, server->h_length);
    serverAddress.sin_port = htons(port);

    /* Now connect to the server */
    //if (connect(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
     //   perror("ERROR connecting1");
     //   exit(1);
    //}
    int timesToTry = 0;
    while (timesToTry < 200) {
        if (connect(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
            break;
        }
        sleep(1);
        ++timesToTry;
    }
    if (timesToTry == 200) {
        perror("ERROR connecting");
        exit(1);
    }

    //while  (connect(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        //trying to connect
    //}
    /* Now ask for a message from the user, this message
     * will be read by server
     */
    //printf("Please enter the message: ");
    //bzero(buffer,256);
    //fgets(buffer,255,stdin);
    while (!ConnectCommand::shouldStop) {
        /* need to check what variables changed and send to the
         * server in this format: "set path value"   */
        for(string var : symbolTable->getChangedArgsVec()) {
            if (symbolTable->isVarInBindsMap(var)) {
                tempPath = symbolTable->getPathByVar(var);
                valueOfVar = symbolTable->getValueOfVar(var);
                messageOfSet = "set " + tempPath + " ";
                messageOfSet += to_string(valueOfVar) + "\r\n";
                //messageOfSet +=
            }
        }
        /* Send message to the server as: "set path value" */
        n = write(sockfd, messageOfSet.c_str(), messageOfSet.size());

        //check if there is a message
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
        this_thread::sleep_for(chrono::milliseconds(300));
    }
}
void ConnectCommand::execute(){
    if(!validIP()) {
        throw INVALID_IP_ADRESS_ERR;
    }
    thread clientFlightSimulator(runUser, ip, port, symbolTable);
    clientFlightSimulator.detach();
}
    /*
    while (!ConnectCommand::shouldStop) {

        // need to check what variables changed and send to the
        // server in this format: "set path value"
        for(string var : symbolTable->getChangedArgsVec()) {
            if (symbolTable->isVarInBindsMap(var)) {
                tempPath = symbolTable->getPathByVar(var);
                valueOfVar = symbolTable->getValueOfVar(var);
                messageOfSet = "set " + tempPath + " ";
                messageOfSet += to_string(valueOfVar);
            }
        }
        // Send message to the server as: "set path value" //
        n = write(sockfd, messageOfSet.c_str(), messageOfSet.size());

        //check if there is a message
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

        this_thread::sleep_for(chrono::milliseconds(300));
    }
     */

    // Now read server response //
    //bzero(buffer,256);
    //n = read(sockfd, buffer, 255);

    //if (n < 0) {
        //perror("ERROR reading from socket");
        //exit(1);
    //}
    //printf("%s\n",buffer);



//*********************** check********************************

void ConnectCommand::stop() {
    shouldStop = true;
}