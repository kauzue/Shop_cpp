#include <iostream>
#include "ClientSocket.h"

int main() {
    std::string ip;
    std::string portStr;

    std::cout << "���� IP �ּ� �Է�: ";
    std::getline(std::cin, ip);

    std::cout << "���� ��Ʈ ��ȣ �Է�: ";
    std::getline(std::cin, portStr);
    int port = std::stoi(portStr);

    ClientSocket client;
    if (!client.ConnectToServer(ip, port)) {
        std::cerr << "���� ���� ����\n";
        return 1;
    }

    while (true) {
        std::string msg;
        std::cout << "�޽��� �Է� (exit �Է� �� ����): ";
        std::getline(std::cin, msg);

        if (msg == "exit") break;

        if (!client.SendMessage(msg)) {
            std::cerr << "�޽��� ���� ����\n";
            break;
        }

        std::string reply = client.ReceiveMessage();
        if (!reply.empty()) {
            std::cout << "���� ����: " << reply << "\n";
        }
        else {
            std::cout << "�����κ��� ���� ����\n";
        }
    }

    return 0;
}
