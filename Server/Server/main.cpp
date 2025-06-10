#include <iostream>

#include "Init.h"
#include "ServerSocket.h"

int main() {
    Init init;
    init.CheckAndCreateFiles();

    int port;
    std::cout << "서버 포트 번호 입력: ";
    std::cin >> port;

    ServerSocket server;
    if (!server.Start(port)) {
        std::cerr << "서버 시작 실패\n";
        return 1;
    }

    server.AcceptClients(); // 클라이언트 수락 시작

    return 0;
}
