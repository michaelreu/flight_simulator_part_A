#include "OpenServerCommand.h"


OpenServerCommand::OpenServerCommand(int prt, int hz) {
    this->port = prt;
    this->hertz = hz;
    this->shouldStop = false;
}

void OpenServerCommand::updateDataFromClient(string str){}

void OpenServerCommand::execute(){}
    /*
    int sockfd, newsockfd, clilen;
    char buffer[256];
    struct sockaddr_in serverAddress, clientAddress;
    int  n;
    string tempStr;
    //***************************setup starts here***********************************
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
    * Now start listening for the clients, here process will
     * go in sleep mode and will wait for the incoming connection
     *
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

         *
         * The inet_ntoa() function converts the Internet host address in, given in network byte order, to a string in
         * IPv4 dotted-decimal notation. The string is returned in a statically allocated buffer, which subsequent
         * calls will overwrite.
         *
        //tempStr = inet_ntoa(clientAddress.sin_addr);
        //pthread_create(&serverAddress, NULL, &Task, )
        // If connection is established then start communicating
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
