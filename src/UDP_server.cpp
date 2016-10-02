#include "UDP_server.h"

UDP_server::UDP_server(int port) {
  this -> port = port;
  this -> serverSd = NULL_SD;
}

UDP_server::~UDP_server()
{
    close(serverSd);
}

 
int UDP_server::getServerSocket()
{
    slen = sizeof(si_other);
     
    //create a UDP socket
    if ((serverSd=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {
        std::cerr << "socket() failed" << std::endl;
        exit(1);
    }

    // zero out the structure
    memset((char *) &si_me, 0, sizeof(si_me));
     
    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(port);
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);
     
    //bind socket to port
    if( bind(serverSd , (struct sockaddr*)&si_me, sizeof(si_me) ) == -1)
    {
        std::cerr << "bind() failed" << std::endl;
        exit(1);
    }

    return serverSd;
}

bool UDP_server::receiveData(char buf[], int bufSize)
{
    if ((recv_len = recvfrom(serverSd, buf, bufSize, 0, (struct sockaddr *) &si_other, &slen)) == -1)
    {
        std::cerr << "recvfrom() failed" << std::endl;
        exit(1);
    }
     
    std::cout << "  Received packet from: " << inet_ntoa(si_other.sin_addr) << ":" << ntohs(si_other.sin_port) << std::endl;

    return true;
         
}

bool UDP_server::sendData(char buf[], int bufSize)
{
    if (sendto(serverSd, buf, recv_len, 0, (struct sockaddr*) &si_other, slen) == -1)
    {
        std::cerr << "sendto() failed" << std::endl;
        exit(1);
    }

    std::cout << "  Sent packet to: " << inet_ntoa(si_other.sin_addr) << ":" << ntohs(si_other.sin_port) << std::endl;
    return true;
}