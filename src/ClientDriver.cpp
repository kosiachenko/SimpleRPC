#include "UDP_client.h"
#include "Client.h"

#include <string>

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        std::cerr << "usage: client server_host server_port" << std::endl;
        return 1;
    }
    std::string host = argv[1];

    int port = atoi (argv[2]);
    if (port < 5001)
    {
        std::cerr << "usage: client server_host server_port" << std::endl;
        return 1;
    }

    UDP_client udp = UDP_client(host, port);
    Client client;
    udp.getClientSocket();

    while(true) {
        std::cout << "Enter points on a cartesian plane : ";

        Point p1, p2, midpoint;
        double distance;

        std::cin >> p1.x >> p1.y >> p2.x >> p2.y;
        std::cout << std::endl;

        if (std::cin.eof()) {
            break;
        }

        int rc1 = client.cartesian_distance(&udp, &p1, &p2, &distance);
        int rc2 = client.midpoint(&udp, &p1, &p2, &midpoint);

        if ((rc1 == 0) && (rc2 == 0))
        {
            std::cout << "  P1 = (" << p1.x << ", " << p1.y << "), P2 = (" << p2.x << ", " << p2.y 
                      << "), Distance = " << distance << ", Midpoint = (" << midpoint.x << ", " 
                      << midpoint.y << ")" << std::endl;
        }
        else
        {
            std::cout << "  The data requested could not be received" << std::endl;
        }
        
    }
    return 0;
}