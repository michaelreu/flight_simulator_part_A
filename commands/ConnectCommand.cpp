

#include "ConnectCommand.h"

ConnectCommand::ConnectCommand(const char* ip, int port, SymbolTable *symTable){
    this->ip = ip;
    this->port = port;
    this->symTbl = symTable;
}

bool ConnectCommand::validIP() {
    regex ipPattern (IP_REGEX);
    return  (regex_match (ip, ipPattern));

}

void ConnectCommand::execute(){
    if(!validIP()) {
        throw INVALID_IP_ADRESS_ERR;
    }
    //char* opop = ip;
    int sockfd, n;
    //int portno;
    struct sockaddr_in serverAddress;
    struct hostent *server;

    char buffer[256];

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(this->ip);

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    //init the buffer
    bzero((char *) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    //copy the message to buffer
    bcopy((char *)server->h_addr, (char *)&serverAddress.sin_addr.s_addr, server->h_length);
    serverAddress.sin_port = htons(this->port);

    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    /* Now ask for a message from the user, this message
       * will be read by server
    */

    printf("Please enter the message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);


    while (!ConnectCommand::shouldStop) {
        /* Send message to the server as: "set path value" */
        n = write(sockfd, buffer, strlen(buffer));

        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

        this_thread::sleep_for(chrono::milliseconds(300));
    }


    //check if there is a message


    /* Now read server response */
    bzero(buffer,256);
    n = read(sockfd, buffer, 255);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n",buffer);
}

//*********************** check********************************
bool ConnectCommand::shouldStop{};