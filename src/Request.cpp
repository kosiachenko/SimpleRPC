#include <string.h>
#include <stdexcept>
#include "Request.h"
#include "Support.h"

int writeEnum(char buffer[], OperationCode value) {
    switch(value) {
        case CARTESIAN: return writeInt(buffer, 1);
        case MIDPOINT: return writeInt(buffer, 2);
        default:
            throw std::logic_error("unknown enum code");
    }
}

int readEnum(char buffer[], OperationCode &value) {
    int32_t p;
    readInt(buffer, p);
    if (p == 1) {
        value = CARTESIAN;
    }
    else if (p == 2) {
        value = MIDPOINT;
    }
    else {
        throw std::logic_error("unknown enum code");
    }

    return 4;
}

int Request::readFromBuf(char buffer[])
{
    int total = 0;
    int read = 0;

    read = readInt(buffer, this->transactionId);
    total += read;
    buffer += read;

    read = readEnum(buffer, this->code);
    total += read;
    buffer += read;

    read = this->p1.readPointFromBuf(buffer);
    total += read;
    buffer += read;

    read = this->p2.readPointFromBuf(buffer);
    total += read;
    buffer += read;

    return total;
}

int Request::writeToBuf(char buffer[])
{
    int total = 0;
    int written = 0;
    
    written = writeInt(buffer, this->transactionId);
    total += written;
    buffer += written;

    written = writeEnum(buffer, this->code);
    total += written;
    buffer += written;

    written = this->p1.writePointToBuf(buffer);
    total += written;
    buffer += written;

    written = this->p2.writePointToBuf(buffer);
    total += written;
    buffer += written;

    return total;
}
