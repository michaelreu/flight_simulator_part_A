#include "OpenServerCommand.h"

//this class gets from the client(flightSimulator) 23 doubles seperated by comma
bool OpenServerCommand::shouldStop = false;

OpenServerCommand::OpenServerCommand(int prt, int hz, SymbolTable* symTable, pthread_mutex_t* mutex) {
    this->symbolTable = symTable;
    this->port = prt;
    this->hertz = hz;
    this->mutex = mutex;
}

void OpenServerCommand::updateDataFromClient(const string &str, SymbolTable* symbolTable){
    Utils utils;
    stringstream valuesStream(str);
    vector<double>valuesVector;
    string tempStr;
    while (valuesStream.good()) {
        getline(valuesStream, tempStr, COMMA_CHAR);
        if (utils.isStrDouble(tempStr)) {
            cout << tempStr<<endl;
            valuesVector.push_back(stod(tempStr));
        }
    }
    symbolTable->updateValuesFromClient(valuesVector);
}
//void* OpenServerCommand::runServer(void *arg) {

//}
void* runServer(void *arg) {

    OpenServerCommand ops = OpenServerCommand();
    struct serverParams* serverPar = (struct serverParams*) arg;
    int sockfd, newsockfd, clilen;
    char buffer[256];
    struct sockaddr_in serverAddress, clientAddress;
    int  n;
    string tempStr;
    //**********setup starts here************
    // First call to socket() function
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Initialize socket structure
    bzero((char *) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(serverPar->portPa);

    // Now bind the host address using bind() call.
    if (bind(sockfd, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
    /* Now start listening for the clients, here process will
    go in sleep mode and will wait for the incoming connection */

    listen(sockfd, 5);
    //**********setup ends here************
    while (!ops.getShouldStop()) {
        clilen = sizeof(clientAddress);
        // Accept actual connection from the client
        newsockfd = accept(sockfd, (struct sockaddr* )&clientAddress, (socklen_t*)&clilen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }
        bzero(buffer,256);
        int i = 0, n = 0;
        char lastDigit = '\0';
        //getting data into the buffer
        while ((i < 1024) && (lastDigit != '\n') && (n >= 0)) {
            n = read(newsockfd, buffer + i, 1);
            lastDigit = buffer[i];
            (++i);
        }
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        printf("Here is the message: %s\n",buffer);
        try {
            pthread_mutex_lock(serverPar->mutexPa);
            ops.updateDataFromClient(string(buffer), serverPar->symbolTablePa);
            pthread_mutex_unlock(serverPar->mutexPa);
        } catch (exception &exception) {
            cout<<"ERROR: couldn't update data"<<endl;
        }
        sleep((unsigned int)1/serverPar->hertzPa);
        //this_thread::sleep_for(chrono::seconds(1/hertz));
    }
    close(sockfd);
}

void OpenServerCommand::execute(){
    //thread serverFlightSimulator(runServer, port, hertz, symbolTable);
    struct serverParams* params = new serverParams();
    params->symbolTablePa = this->symbolTable;
    params->portPa = this->port;
    params->hertzPa = this->hertz;
    params->mutexPa = this->mutex;
    pthread_t serverFlightSimulator;
    pthread_create(&serverFlightSimulator, nullptr, runServer, params);

    //serverFlightSimulator.detach();
}

void OpenServerCommand::stop() {
    shouldStop = true;
}

bool OpenServerCommand::getShouldStop() {
    return shouldStop;
}