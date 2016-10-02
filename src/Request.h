#ifndef REQUEST_H
#define REQUEST_H

#include <stdint.h>
#include "Point.h"

enum OperationCode {CARTESIAN, MIDPOINT};

class Request {
    public:
        int32_t transactionId;
        OperationCode code;
        Point p1;
        Point p2;

        int readFromBuf(char buffer[]);
        int writeToBuf(char buffer[]);
};

#endif