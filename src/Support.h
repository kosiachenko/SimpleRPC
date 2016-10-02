#ifndef SUPPORT_H
#define SUPPORT_H

#include <stdint.h>

int writeInt(char buffer[], int32_t value);
int readInt(char buffer[], int32_t &dest);
int writeDouble(char buffer[], double value);
int readDouble(char buffer[], double &value);

#endif