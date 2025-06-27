#include "Init.h"
#include "ServerSocket.h"
#include <iostream>

int main() {
    Init::CheckFiles();

    int port;
    std::cout << "������ �� ��Ʈ�� �Է��ϼ���: ";
    std::cin >> port;

    ServerSocket server;
    if (!server.Start(port)) {
        std::cerr << "���� ���� ����" << std::endl;
        return 1;
    }

    server.Accept();
    return 0;
}
