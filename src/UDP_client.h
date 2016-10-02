#ifndef UDP_CLIENT_H
#define UDP_CLIENT_H

#include <stdio.h> //printf
#include <string.h> //memset
#include <stdlib.h> //exit(0);
#include <arpa/inet.h>
#include <sys/socket.h>
#include <cstring>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/time.h>

#include "Point.h"
#include "Request.h"
#include "Response.h"

class UDP_client {
public:
    UDP_client(std::string host, int port);
    ~UDP_client();

    int getClientSocket();
    int sendData(char buf[], int bufSize);
    int receiveData(char buf[], int bufSize);

private:
    const char* host;
    int port;

    int timeout = 5;
    int max_retries = 3;

    struct sockaddr_in si_other;
    int clientSd;
    socklen_t slen;
};

#endif