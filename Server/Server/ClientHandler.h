#pragma once
#include <winsock2.h>
#include <string>

class ClientHandler {
public:
    ClientHandler(SOCKET socket);
    void operator()();
private:
    SOCKET clientSocket;
    std::string Id;
};
