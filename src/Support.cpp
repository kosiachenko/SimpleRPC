#include <string.h>
#include <stdexcept>
#include <stdint.h>

#include "Support.h"

int writeInt(char buffer[], int32_t value) {
    memcpy(buffer, &value, 4);

    return 4;
}

int readInt(char buffer[], int32_t &dest) {
    memcpy(&dest, buffer, 4);
    return 4;
}

int writeDouble(char buffer[], double value) {
    if (sizeof(value) != 8)
    {
        throw std::logic_error("double is not 64 bit");
    }
    memcpy(buffer, &value, 8);
    return 8;
}

int readDouble(char buffer[], double &value) {
    if (sizeof(value) != 8)
    {
        throw std::logic_error("double is not 64 bit");
    }
    memcpy(&value, buffer, 8);
    return 8;
}