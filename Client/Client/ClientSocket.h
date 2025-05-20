#pragma once

#include <winsock2.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")

class ClientSocket {
private:
    SOCKET socket;

    bool InitWinSock();

public:
    ClientSocket();
    ~ClientSocket();

    bool ConnectToServer(const std::string& ip, int port);
    bool SendMessage(const std::string& msg);
    std::string ReceiveMessage();
};
