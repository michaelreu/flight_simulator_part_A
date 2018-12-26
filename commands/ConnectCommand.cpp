//this class sends messages to the flight simulator such as: set path value

#include "ConnectCommand.h"

ConnectCommand::ConnectCommand(const char* ip, int port, SymbolTable* &symTable, threadParams *threadsParam){
    this->symbolTable = symTable;
    this->ip = ip;
    this->port = port;
    this->threadsParam = threadsParam;
}

void* runClient(void *arg) {
    ConnectCommand cnct = ConnectCommand();
    struct clientParams* clientPar = (struct clientParams*) arg;
    double valueOfVar;
    int n;
    struct sockaddr_in serverAddress;
    struct hostent *server;
    string tempPath = "", messageOfSet = "";
    const char* buffer;
    /* Create a socket point */
    clientPar->clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (clientPar->clientSocket < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(clientPar->ipPa);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    //init the buffer
    bzero((char *) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    //copy the message to buffer
    bcopy((char *)server->h_addr, (char *)&serverAddress.sin_addr.s_addr, server->h_length);
    serverAddress.sin_port = htons(clientPar->portPa);

    /* Now connect to the server */
    while ((connect(clientPar->clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0)){}

    while (*clientPar->isRun) {
        pthread_mutex_lock(clientPar->mutex);
        *clientPar->updateData = true;
        pthread_mutex_unlock(clientPar->mutex);
        /* need to check what variables changed and send to the
         * server in this format: "set path value"   */
        n = 0;
        pthread_mutex_lock(clientPar->mutex);
        for(string var : (clientPar->symbolTablePa)->getChangedArgsVec()) {
            if ((clientPar->symbolTablePa)->isVarInBindsMap(var)) {
                tempPath = (clientPar->symbolTablePa)->getPathByVar(var);
                tempPath = tempPath.substr(START_OF_STRING,tempPath.size()-END_OF_STRING);
                valueOfVar = (clientPar->symbolTablePa)->getValueOfVar(var);
                messageOfSet = SET + tempPath + " ";
                messageOfSet += to_string(valueOfVar) + "\r\n";
                buffer = messageOfSet.c_str();
                n = write(clientPar->clientSocket, buffer, strlen(buffer));

            }
        }
        ((clientPar->symbolTablePa)->getChangedArgsVec()).clear();
        pthread_mutex_unlock(clientPar->mutex);
        //check if there is a message
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
        pthread_mutex_lock(clientPar->mutex);
        *clientPar->updateData = false;
        pthread_mutex_unlock(clientPar->mutex);
    }
    close(clientPar->clientSocket);
    (*clientPar->isRun) = false;
    delete(clientPar);
    clientPar = nullptr;
}

void ConnectCommand::execute(){
    struct clientParams* clParams = new clientParams();
    clParams->symbolTablePa = this->symbolTable;
    clParams->portPa = this->port;
    clParams->ipPa = this->ip;
    clParams->clientSocket = this->threadsParam->sockfdConnect;
    clParams->isRun = &this->threadsParam->clientThreadIsRun;
    clParams->updateData = &this->threadsParam->clientIsRun;
    clParams->mutex = this->threadsParam->mutex;
    this->threadsParam->clientThreadIsRun = true;
    pthread_create(this->threadsParam->clientThread, nullptr, runClient, clParams);
}