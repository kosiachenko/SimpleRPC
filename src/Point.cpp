#include <string.h>
#include <stdexcept>
#include "Point.h"
#include "Support.h"

Point::Point()
{
    this -> x = 0;
    this -> y = 0;
}

Point::Point(double x, double y)
{
    this -> x = x;
    this -> y = y;
}

int Point::readPointFromBuf(char buffer[])
{
    buffer += readDouble(buffer, this -> x);
    buffer += readDouble(buffer, this -> y);
    return 16;

}

int Point::writePointToBuf(char buffer[])
{
    buffer += writeDouble(buffer, this -> x);
    buffer += writeDouble(buffer, this -> y);
    return 16;
}