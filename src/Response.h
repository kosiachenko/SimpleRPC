#ifndef RESPONSE_H
#define RESPONSE_H

#include <stdint.h>
#include "Point.h"

class CartesianResponse {
    public:
        int32_t transactionId;
        int32_t resultCode;
        double distance;

        int readFromBuf(char buffer[]);
        int writeToBuf(char buffer[]);
};

class MidpointResponse {
    public:
        int32_t transactionId;
        int32_t resultCode;
        Point midpoint;

        int readFromBuf(char buffer[]);
        int writeToBuf(char buffer[]);
};

#endif