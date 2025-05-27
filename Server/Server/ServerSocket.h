#pragma once

#include <winsock2.h>
#include <string>
#include <vector>

#pragma comment(lib, "ws2_32.lib")

class ServerSocket {
private:
    SOCKET socket;
    std::vector<SOCKET> clients;

    bool InitWinSock();
    std::string GetLocalIPAddress();

public:
    ServerSocket();
    ~ServerSocket();

    bool Start(int port);
    void AcceptClients();
};
