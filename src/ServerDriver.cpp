#include "UDP_server.h"
#include "Server.h"
#include "Request.h"
#include "Response.h"
#include "Point.h"
#include <iostream>
#include <sstream>

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cerr << "usage: server port" << std::endl;
        return 1;
    }
    int port = atoi (argv[1]);
    if (port < 5001)
    {
        std::cerr << "usage: server port" << std::endl;
        return 1;
    }

    UDP_server udp = UDP_server(port);
    Server server;
    udp.getServerSocket();

    while (true)
    {
        std::cout << "Waiting for data..." << std::endl;
        fflush(stdout);

        char buf[BUFLEN];

        bool success = udp.receiveData(buf, BUFLEN);

        Request request;
        request.readFromBuf(buf);
        if ((request.p1.x < 0) || (request.p2.x < 0))
        {
            //ignore the request
            std::cout << "  Request ignored" << std::endl;
        }
        else
        {
            if (request.code == CARTESIAN)
            {
                CartesianResponse response;
                response.transactionId = request.transactionId;

                if (((request.p1.x >= 0) && (request.p1.y < 0)) ||
                    ((request.p2.x >= 0) && (request.p2.y < 0)))
                {
                    response.resultCode = -1;
                }
                else
                {
                    response.resultCode = 0;
                    response.distance = server.cartesian_distance(request.p1, request.p2);
                }
                
                response.writeToBuf(buf);
            }
            else if (request.code == MIDPOINT)
            {
                MidpointResponse response;
                response.transactionId = request.transactionId;
                
                if (((request.p1.x >= 0) && (request.p1.y < 0)) ||
                    ((request.p2.x >= 0) && (request.p2.y < 0)))
                {
                    response.resultCode = -1;
                }
                else
                {
                    response.resultCode = 0;
                    response.midpoint = server.midpoint(request.p1, request.p2);
                }

                response.writeToBuf(buf);
            }

            udp.sendData(buf, BUFLEN);
        }        
    }

    return 0;
}