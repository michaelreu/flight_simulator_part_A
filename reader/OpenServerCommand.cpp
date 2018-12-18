

#include "OpenServerCommand.h"
#include "../factory/ExpressionFactory.h"


#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

#include <sys/socket.h>
/*
void openServer(int port, int hertz) {
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int  n;

    // First call to socket() function
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Initialize socket structure
    bzero((char*) &serv_addr, sizeof(serv_addr));
    //portno = 5001;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    // Now bind the host address using bind() call.
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /
     * Now start listening for the clients, here process will
     * go in sleep mode and will wait for the incoming connection
     /

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    // Accept actual connection from the client
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    // If connection is established then start communicating
    bzero(buffer,256);
    n = read( newsockfd,buffer,255 );

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("Here is the message: %s\n",buffer);

    //Write a response to the client
    n = write(newsockfd,"I got your message",18);

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
}
*/
OpenServerCommand::OpenServerCommand(vector<string> *dataV) {
    dataVector = dataV;
}

vector<string> *OpenServerCommand::getDataVector() const {
    return this->dataVector;
}


double OpenServerCommand::extractDoubleFromString(string &s) {
    ExpressionFactory e = ExpressionFactory(s);
    return (e.createExpression())->calculate(s);
    //StrToDoubleClass strToDouble = StrToDoubleClass(s);

    //return strToDouble.calculate();
}

double OpenServerCommand::getNextDoubleInVector1(vector<string> *dataVector) {
    dataVector->erase((dataVector)->begin());
    auto it = (dataVector)->begin();
    double d = extractDoubleFromString(*it);
    return d;
}



void OpenServerCommand::execute(){
    if (dataVector->size() < NUM_OF_PARAM) {
        throw PARAMETERS_NUMBER_EXCEPTION;
    }
    int port = (int) getNextDoubleInVector1(getDataVector());
    int hertz = (int) getNextDoubleInVector1(getDataVector());
    //openServer(port,hertz);
}


