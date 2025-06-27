#pragma once
#include <winsock2.h>
#include <vector>

class ServerSocket {
public:
    bool Start(int port);
    void Accept();

private:
    SOCKET serverSocket;
    std::vector<SOCKET> clients;
};
