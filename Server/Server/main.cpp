#include "Init.h"
#include "ServerSocket.h"
#include <iostream>

int main() {
    Init::CheckFiles();

    int port;
    std::cout << "서버를 열 포트를 입력하세요: ";
    std::cin >> port;

    ServerSocket server;
    if (!server.Start(port)) {
        std::cerr << "서버 시작 실패" << std::endl;
        return 1;
    }

    server.Accept();
    return 0;
}
