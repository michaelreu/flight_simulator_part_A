#include "OpenServerCommand.h"
//this class gets from the client(flightSimulator) 23 doubles seperated by comma

OpenServerCommand::OpenServerCommand(int prt, int hz, SymbolTable* symTable, threadParams *threadsParam) {
    this->symbolTable = symTable;
    this->port = prt;
    this->hertz = hz;
    this->threadsParam = threadsParam;
}

void OpenServerCommand::updateDataFromClient(const string &str, SymbolTable* symbolTable){
    Utils utils;
    stringstream valuesStream(str);
    vector<double>valuesVector;
    string tempStr;

    while (valuesStream.good()) {

        getline(valuesStream, tempStr, COMMA_CHAR);
        if (tempStr.at(tempStr.size() - 1 == '\n')){
            tempStr = tempStr.substr(0, tempStr.size() - 2);
        }
        if (utils.isStrDouble(tempStr)) {
            valuesVector.push_back(stod(tempStr));
        }
    }
    symbolTable->updateValuesFromClient(valuesVector);
}

void* runServer(void *arg) {
    OpenServerCommand ops = OpenServerCommand();
    struct serverParams* serverPar = (struct serverParams*) arg;
    char buffer[BUFF_SIZE];
    string tempStr;

    if (serverPar->newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    while (*serverPar->isRun) {
        bzero(buffer,BUFF_SIZE);
        int i = 0, n = 0;
        char lastDigit = '\0';
        //getting data into the buffer
        while ((i < BUFF_SIZE) && (lastDigit != '\n') && (n >= 0)) {
            n = read(serverPar->newsockfd, buffer + i, 1);
            lastDigit = buffer[i];
            (++i);
        }
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        printf("Here is the message: %s\n",buffer);
        try {
            ops.updateDataFromClient(string(buffer), serverPar->symbolTablePa);
        } catch (exception &exception) {
            //delete(serverPar);
            cout<<"ERROR: couldn't update data"<<endl;
            *serverPar->isRun = false;
        }
        this_thread::sleep_for(chrono::milliseconds(SLEEP_TIME));
    }

    close(serverPar->sockfd);
    *serverPar->isRun = false;
    delete(serverPar);
    serverPar = nullptr;
}

void OpenServerCommand::execute() {
    int newsockfd, clilen;
    struct sockaddr_in serverAddress, clientAddress;
    string tempStr;
    //**********setup starts here************
    // First call to socket() function
    this->threadsParam->sockfdServer = socket(AF_INET, SOCK_STREAM, 0);
    if (this->threadsParam->sockfdServer < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Initialize socket structure
    bzero((char *) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(this->port);

    // Now bind the host address using bind() call.
    if (bind(this->threadsParam->sockfdServer, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
    /* Now start listening for the clients, here process will
    go in sleep mode and will wait for the incoming connection */

    listen(this->threadsParam->sockfdServer, BACKLOG);
    //**********setup ends here************
    clilen = sizeof(clientAddress);
    // Accept actual connection from the client
    newsockfd = accept(this->threadsParam->sockfdServer, (struct sockaddr*) &clientAddress, (socklen_t*) &clilen);
    cout << "accepted!!!!!!!!!!!!!" << endl;

    struct serverParams *params = new serverParams();
    params->symbolTablePa = this->symbolTable;
    params->newsockfd = newsockfd;
    params->sockfd = this->threadsParam->sockfdServer;
    params->isRun = &this->threadsParam->serverThreadIsRun;
    params->clientIsRun = &this->threadsParam->clientThreadIsRun;
    this->threadsParam->serverThreadIsRun = true;
    pthread_create(this->threadsParam->serverThread, nullptr, runServer, params);
}