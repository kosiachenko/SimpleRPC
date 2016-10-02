#include "Server.h"
#include <string>
#include <iostream>
#include <sstream>
#include <math.h> 

double Server::cartesian_distance(Point p1, Point p2) {
    // Point *p1, Point *p2, double* result);
    double result = sqrt (pow (p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));

    return result;
}
        

Point Server::midpoint(Point p1, Point p2)
{
    // Point *p1, Point *p2, Point* result);
    Point midpoint = Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
    return midpoint;
}