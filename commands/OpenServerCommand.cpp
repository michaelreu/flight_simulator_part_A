#include <thread>
#include "OpenServerCommand.h"


OpenServerCommand::OpenServerCommand(int prt, int hz, SymbolTable* &symTable) {
    this->symbolTable = symTable;
    this->port = prt;
    this->hertz = hz;
    this->shouldStop = false;
}

void OpenServerCommand::updateDataFromClient(const string &str){
    Utils utils;
    stringstream valuesStream(str);
    vector<double>valuesVector;
    string tempStr;
    while (valuesStream.good()) {
        getline(valuesStream, tempStr, COMMA_CHAR);
        if (utils.isStrDouble(tempStr)) {
            valuesVector.push_back(stod(tempStr));
        }
    }
    symbolTable->updateValuesFromClient(valuesVector);
}

void OpenServerCommand::execute(){
    int sockfd, newsockfd, clilen;
    char buffer[256];
    struct sockaddr_in serverAddress, clientAddress;
    int  n;
    string tempStr;
    //***************************setup starts here***********************************//
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
    serverAddress.sin_port = htons(this->port);

    // Now bind the host address using bind() call.
    if (bind(sockfd, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
    /* Now start listening for the clients, here process will
     * go in sleep mode and will wait for the incoming connection
     */
    listen(sockfd, 5);
    //***************************setup ends here***********************************


    while (!shouldStop) {
        clilen = sizeof(clientAddress);
        // Accept actual connection from the client
        newsockfd = accept(sockfd, (struct sockaddr *)&clientAddress, (socklen_t*)&clilen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }
        bzero(buffer,256);
        //getting data into the buffer
        n = read(newsockfd, buffer, 255);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        try {
            updateDataFromClient(string(buffer));
        } catch (exception &exception) {
            cout<<"ERROR: couldn't update data"<<endl;
        }
        this_thread::sleep_for(chrono::seconds(1/hertz));

    }

    //printf("Here is the message: %s\n",buffer);

    //Write a response to the client
    //n = write(newsockfd,"I got your message",18);
    /*
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
     */
}
