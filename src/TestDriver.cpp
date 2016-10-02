#include "Request.h"
#include "Response.h"
#include "Point.h"
#include "Support.h"
#include <assert.h>

int main(int argc, char const *argv[])
{
    Request request;
    request.transactionId = 42;
    request.code = cartesian;
    request.p1 = Point(2.0, 5.0);
    request.p2 = Point(6.0, 10.0);

    char buffer[1024];
    request.writeToBuf(buffer);

    Request request2;
    request2.readFromBuf(buffer);

    assert (request.transactionId == request2.transactionId);
    assert (request.code == request2.code);
    assert (request.p1.x == request2.p1.x);
    assert (request.p1.y == request2.p1.y);
    assert (request.p2.x == request2.p2.x);
    assert (request.p2.y == request2.p2.y);

    CartesianResponse response1;
    response1.transactionId = 239;
    response1.resultCode = -1;
    response1.distance = 34.05;

    response1.writeToBuf(buffer);

    CartesianResponse response2;
    response2.readFromBuf(buffer);

    assert(response1.transactionId == response2.transactionId);
    assert(response1.resultCode == response2.resultCode);
    assert(response1.distance == response2.distance);

    MidpointResponse response3;
    response3.transactionId = 23;
    response3.resultCode = 0;
    response3.midpoint = Point(2.3, 5.4);

    response3.writeToBuf(buffer);

    MidpointResponse response4;
    response4.readFromBuf(buffer);

    assert(response3.transactionId == response4.transactionId);
    assert(response3.resultCode == response4.resultCode);
    assert(response3.midpoint.x == response4.midpoint.x);
    assert(response3.midpoint.y == response4.midpoint.y);

    return 0;
}