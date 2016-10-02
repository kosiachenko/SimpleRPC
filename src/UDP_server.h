#ifndef UDP_SERVER_H
#define UDP_SERVER_H

#include <stdio.h> //printf
#include <string.h> //memset
#include <stdlib.h> //exit(0);
#include <arpa/inet.h>
#include <sys/socket.h>
#include <cstring>
#include <unistd.h>
#include <iostream>
 
#define BUFLEN 512  //Max length of buffer
#define NULL_SD -1

class UDP_server {
public:
    UDP_server(int port);
    ~UDP_server();
    int getServerSocket();
    bool receiveData(char buf[], int bufSize);
    bool sendData(char buf[], int bufSize);
private:
    int serverSd;
    int port;
    char address[BUFLEN];
    struct sockaddr_in si_me;
    struct sockaddr_in si_other;
    socklen_t slen;
    int recv_len;
     
};

#endif