#include "Response.h"
#include "Support.h"

int CartesianResponse::readFromBuf(char buffer[]) {

    int total = 0;
    int read = 0;

    read = readInt(buffer, this->transactionId);
    total += read;
    buffer += read;

    read = readInt(buffer, this->resultCode);
    total += read;
    buffer += read;

    if (this->resultCode != -1) {
        read = readDouble(buffer, this -> distance);
        total += read;
        buffer += read;
    }

    return total;
}

int CartesianResponse::writeToBuf(char buffer[]) {
    int total = 0;
    int written = 0;
    
    written = writeInt(buffer, this->transactionId);
    total += written;
    buffer += written;

    written = writeInt(buffer, this->resultCode);
    total += written;
    buffer += written;

    if (this->resultCode != -1) {
        written = writeDouble(buffer, this ->distance);
        total += written;
        buffer += written;
    }

    return total;
}

int MidpointResponse::readFromBuf(char buffer[]) {
    int total = 0;
    int read = 0;

    read = readInt(buffer, this->transactionId);
    total += read;
    buffer += read;

    read = readInt(buffer, this->resultCode);
    total += read;
    buffer += read;

    if (this->resultCode != -1) {
        read = this->midpoint.readPointFromBuf(buffer);
        total += read;
        buffer += read;
    }

    return total;
}

int MidpointResponse::writeToBuf(char buffer[]) {
    int total = 0;
    int written = 0;
    
    written = writeInt(buffer, this->transactionId);
    total += written;
    buffer += written;

    written = writeInt(buffer, this->resultCode);
    total += written;
    buffer += written;

    if (this->resultCode != -1) {
        written = this->midpoint.writePointToBuf(buffer);
        total += written;
        buffer += written;
    }

    return total;
}