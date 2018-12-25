//this class sends messages to the flight simulator such as: set path value

#include "ConnectCommand.h"



bool ConnectCommand::shouldStop = false;
ConnectCommand::ConnectCommand(const char* ip, int port, SymbolTable* &symTable){
    this->symbolTable = symTable;
    this->ip = ip;
    this->port = port;
    shouldStop = false;
}


void* runClient(void *arg) {
    cout << "in the runClien func" << endl;
    ConnectCommand cnct = ConnectCommand();
    struct clientParams* clientPar = (struct clientParams*) arg;
    double valueOfVar;
    int sockfd, n;
    struct sockaddr_in serverAddress;
    struct hostent *server;
    string tempPath, messageOfSet = "hi";
    //int port = stoi(port1);
    //char buffer[256];
    const char* buffer;
    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
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
    while ((connect(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0)){}
    cout<<"connected"<<endl;
    //&&(!ConnectCommand::getShouldStop())

    while (!cnct.getShouldStop()) {
    //while(true) {
        /* need to check what variables changed and send to the
         * server in this format: "set path value"   */
        n = 0;
        pthread_mutex_lock(clientPar->symbolTablePa->getMutex());
        vector<string> changedArgs = (clientPar->symbolTablePa)->getChangedArgsVec();
        for(string var : changedArgs) {
            if ((clientPar->symbolTablePa)->isVarInBindsMap(var)) {
                tempPath = (clientPar->symbolTablePa)->getPathByVar(var);
                tempPath = tempPath.substr(START_OF_STR,tempPath.size()-END_OF_STR);
                valueOfVar = (clientPar->symbolTablePa)->getValueOfVar(var);
                messageOfSet = SET + tempPath + " ";
                messageOfSet += to_string(valueOfVar) + "\r\n";
                buffer = messageOfSet.c_str();
                n = write(sockfd, buffer, strlen(buffer));

            }
        }
        ((clientPar->symbolTablePa)->getChangedArgsVec()).clear();
        pthread_mutex_unlock(clientPar->symbolTablePa->getMutex());
        //check if there is a message
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
        sleep((unsigned int)SEEP_TIME);
        //this_thread::sleep_for(chrono::milliseconds(300));
    }
    close(sockfd);
    delete(clientPar);
}

void ConnectCommand::execute(){
    struct clientParams* clParams = new clientParams();
    clParams->symbolTablePa = this->symbolTable;
    clParams->portPa = this->port;
    clParams->ipPa = this->ip;
    pthread_t clientFlightSimulator;
    pthread_create(&clientFlightSimulator, nullptr, runClient, clParams);
    //no need to delete clParams it has been deleted above
}

void ConnectCommand::stop() {
    shouldStop = true;
}

bool ConnectCommand::getShouldStop() {
    return shouldStop;
}

ConnectCommand::~ConnectCommand() {

}