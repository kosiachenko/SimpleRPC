#ifndef CLIENT_H
#define CLIENT_H

#include "Point.h"
#include "UDP_client.h"

#define BUFLEN 512  //Max length of buffer

class Client {
public:
    int cartesian_distance(UDP_client *rpc, Point *p1, Point *p2, double *result);

    int midpoint(UDP_client *rpc, Point *p1, Point *p2, Point *result);

private:

};

#endif