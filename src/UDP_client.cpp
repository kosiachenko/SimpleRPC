#include "UDP_client.h"
#include <errno.h>

UDP_client::UDP_client(std::string host, int port)
{
    this-> host = host.c_str();
    this-> port = port;
}

UDP_client::~UDP_client()
{
    close(clientSd);
}

int UDP_client::getClientSocket()
{
    slen=sizeof(si_other);
 
    if ( (clientSd=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {
        std::cerr << "socket fail" << std::endl;
        exit(1);
    }
 
    memset((char *) &si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(port);
     
    if (inet_aton(host , &si_other.sin_addr) == 0) 
    {
        std::cerr << "inet_aton() failed" << std::endl;
        exit(1);
    }

    //setting Timeout
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;

    if (setsockopt(clientSd, SOL_SOCKET, SO_RCVTIMEO, (struct timeval *) &tv, sizeof(struct timeval)) == -1)
    {        
        int errsv = errno;

        std::cerr << "set timeout failed " << errsv << std::endl;

        exit(1);
    }

    return clientSd;
}

int UDP_client::sendData(char buf[], int bufSize)
{
    if (sendto(clientSd, buf, bufSize , 0 , (struct sockaddr *) &si_other, slen)==-1)
    {
        std::cerr << "sendto() failed" << std::endl;
        return -1;
    }
    return 0;
}

int UDP_client::receiveData(char buf[], int bufSize)
{
    for (int i = 0; i < max_retries; i++)
    {
        int rc = recvfrom(clientSd, buf, bufSize, 0, (struct sockaddr *) &si_other, &slen);
        if (rc != -1)
        {
            return 0;
        }
    }

    return -1;
}