#include <iostream>
#include "ClientSocket.h"

int main() {
    std::string ip;
    std::string portStr;

    std::cout << "서버 IP 주소 입력: ";
    std::getline(std::cin, ip);

    std::cout << "서버 포트 번호 입력: ";
    std::getline(std::cin, portStr);
    int port = std::stoi(portStr);

    ClientSocket client;
    if (!client.ConnectToServer(ip, port)) {
        std::cerr << "서버 연결 실패\n";
        return 1;
    }

    while (true) {
        std::string msg;
        std::cout << "메시지 입력 (exit 입력 시 종료): ";
        std::getline(std::cin, msg);

        if (msg == "exit") break;

        if (!client.SendMessage(msg)) {
            std::cerr << "메시지 전송 실패\n";
            break;
        }

        std::string reply = client.ReceiveMessage();
        if (!reply.empty()) {
            std::cout << "서버 응답: " << reply << "\n";
        }
        else {
            std::cout << "서버로부터 응답 없음\n";
        }
    }

    return 0;
}
