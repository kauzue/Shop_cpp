#include <iostream>

#include "Init.h"
#include "ServerSocket.h"

int main() {
    Init init;
    init.CheckAndCreateFiles();

    int port;
    std::cout << "���� ��Ʈ ��ȣ �Է�: ";
    std::cin >> port;

    ServerSocket server;
    if (!server.Start(port)) {
        std::cerr << "���� ���� ����\n";
        return 1;
    }

    server.AcceptClients(); // Ŭ���̾�Ʈ ���� ����

    return 0;
}
