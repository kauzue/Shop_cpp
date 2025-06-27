#pragma once
#include <winsock2.h>

class ClientHandler {
public:
    ClientHandler(SOCKET socket);
    void operator()();
private:
    SOCKET clientSocket;
};
