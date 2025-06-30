#include "ClientHandler.h"
#include "UserManager.h"
#include <string>
#include <iostream>

ClientHandler::ClientHandler(SOCKET socket) : clientSocket(socket) {}

void ClientHandler::operator()() {
    char buf[1024];
    int len;

    while ((len = recv(clientSocket, buf, sizeof(buf) - 1, 0)) > 0) {
        buf[len] = '\0';
        std::string msg(buf);

        if (msg.compare(0, 7, "signup:") == 0) {
            std::string payload = msg.substr(7);
            std::string res = UserManager::Signup(payload);
            send(clientSocket, res.c_str(), res.size(), 0);
        }
        else if (msg.compare(0, 6, "login:") == 0) {
            std::string payload = msg.substr(6);
            std::string res = UserManager::Login(payload);
            send(clientSocket, res.c_str(), res.size(), 0);
        }
        else if (msg.compare(0, 11, "addproduct:") == 0) {
            std::string payload = msg.substr(11);
            std::string res = UserMagager::AddProduct(payload);
            send(clientSocket, res.c_str(), res.size(), 0);
        }
    }

    std::cout << "클라이언트 연결 종료" << std::endl;
    closesocket(clientSocket);
}
