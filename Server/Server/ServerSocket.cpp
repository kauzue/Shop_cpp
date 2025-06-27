#include "ServerSocket.h"
#include "ClientHandler.h"
#include <iostream>
#include <thread>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

bool ServerSocket::Start(int port) {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) return false;

    sockaddr_in addr = {};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR)
        return false;

    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
        return false;

    char hostname[256];
    gethostname(hostname, sizeof(hostname));
    addrinfo hints = {}, * res;
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    getaddrinfo(hostname, NULL, &hints, &res);

    sockaddr_in* ipv4 = (sockaddr_in*)res->ai_addr;
    char ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(ipv4->sin_addr), ip, INET_ADDRSTRLEN);

    std::cout << "[서버 실행됨] IP: " << ip << ", 포트: " << port << std::endl;

    freeaddrinfo(res);
    return true;
}

void ServerSocket::Accept() {
    while (true) {
        SOCKET client = accept(serverSocket, nullptr, nullptr);
        if (client != INVALID_SOCKET) {
            std::thread t([client]() {
                ClientHandler handler(client);
                handler();
                });
            t.detach();
        }
    }
}
