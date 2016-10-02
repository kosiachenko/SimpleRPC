#include "Client.h"

#include <stdlib.h> //rand()

int Client::cartesian_distance(UDP_client *udp, Point *p1, Point *p2, double *result)
{
    Request request;
    request.transactionId = rand();
    request.code = CARTESIAN;
    request.p1 = *p1;
    request.p2 = *p2;

    char message[BUFLEN];
    int msgLenght = request.writeToBuf(message);
    udp->sendData(message, msgLenght);

    char buf[BUFLEN];

    

    while (true)
    {
        int rc = udp->receiveData(buf, BUFLEN);
        if (rc != 0)
        {
            std::cerr << "  Cartesian distance: timeout reached 3 times, could not get response from the server" << std::endl;
            return -1;
        }
        CartesianResponse response;
        response.readFromBuf(buf);
        if (response.transactionId == request.transactionId)
        {
            if (response.resultCode == 0)
            {
                *result = response.distance;
                return 0;
            }
            else
            {
                std::cerr << "  Cartesian distance: got -1 result code from the server, failed to get required data" << std::endl;
                return -1;
            }
        }
    }

    return -1;
}

int Client::midpoint(UDP_client *udp, Point *p1, Point *p2, Point *result)
{
    Request request;
    request.transactionId = rand();
    request.code = MIDPOINT;
    request.p1 = *p1;
    request.p2 = *p2;

    char message[BUFLEN];
    int msgLenght = request.writeToBuf(message);
    udp->sendData(message, msgLenght);

    char buf[BUFLEN];

    while (true)
    {
        int rc = udp->receiveData(buf, BUFLEN);

        if (rc != 0)
        {
            std::cerr << "  Midpoint: timeout reached 3 times, could not get response from the server" << std::endl;
            return -1;
        }

        MidpointResponse response;
        response.readFromBuf(buf);

        if (response.transactionId == request.transactionId)
        {
            if (response.resultCode == 0)
            {
                *result = response.midpoint;
                return 0;
            }
            else 
            {
                std::cerr << "  Midpoint: got -1 result code from the server, failed to get required data" << std::endl;
                return -1;
            }
        }
    }

    return -1;
}