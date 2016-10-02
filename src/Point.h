#ifndef POINT_H
#define POINT_H

class Point {
public:
    double x;
    double y;

    Point(double x, double y);
    Point();

    int readPointFromBuf(char buffer[]);
    int writePointToBuf(char buffer[]);
};

#endif