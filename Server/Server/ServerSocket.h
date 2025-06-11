#pragma once
#include <winsock2.h>
#include <vector>
#include <string>

class ServerSocket {
private:
    SOCKET serverSocket;
    std::vector<SOCKET> clients;

public:
    bool StartServer(int port);
    void AcceptClients();
    void HandleClient(SOCKET clientSocket);
};
