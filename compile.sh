g++ -std=c++11 src/ServerDriver.cpp src/UDP_server.cpp src/Server.cpp src/Point.cpp src/Request.cpp src/Response.cpp src/Support.cpp -o bin/server 
g++ -std=c++11 src/ClientDriver.cpp src/UDP_client.cpp src/Client.cpp src/Point.cpp src/Request.cpp src/Response.cpp src/Support.cpp -o bin/client 