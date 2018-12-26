//
// Created by cs on 12/13/18.
//

#ifndef PROJECTPART1_COMMAND_H
#define PROJECTPART1_COMMAND_H

#include "../expression/Expression.h"
#include "../factory/ExpressionFactory.h"

#include <chrono>
#include <thread>

#include <iostream>
#include <pthread.h>
#include <cstdio>
#include <cstdlib>
#include <regex>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>

#include <vector>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#define SLEEP_TIME 300

class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};


#endif //PROJECTPART1_COMMAND_H
