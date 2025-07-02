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
            if (res == "success" || res == "success:admin") {
                size_t sep = payload.find(':');
                if (sep != std::string::npos) {
					Id = payload.substr(0, sep);
                    std::cout << Id << std::endl;
                }
            }
        }
        else if (msg.compare(0, 11, "addproduct:") == 0) {
            std::string payload = msg.substr(11);
            std::string res = UserManager::AddProduct(Id, payload);
            send(clientSocket, res.c_str(), res.size(), 0);
        }
        else if (msg.compare(0, 9, "changeId:") == 0) {
            std::string payload = msg.substr(9);
            std::string res = UserManager::ChangeId(Id, payload);
            send(clientSocket, res.c_str(), res.size(), 0);
            if (res == "success") {
                Id = payload;
            }
        }
        else if (msg.compare(0, 9, "changePw:") == 0) {
            std::string payload = msg.substr(9);
            std::string res = UserManager::ChangePw(Id, payload);
            send(clientSocket, res.c_str(), res.size(), 0);
        }
        else if (msg.compare(0, 13, "deleteaccount") == 0) {
            std::string payload = msg;
            std::string res = UserManager::DeleteAccount(Id, payload);
            send(clientSocket, res.c_str(), res.size(), 0);
        }
        else if (msg.compare(0, 11, "userchange:") == 0) {
            std::string payload = msg.substr(11);
            std::string res = UserManager::UserChange(payload);
            send(clientSocket, res.c_str(), res.size(), 0);
        }
        else if (msg.compare(0, 9, "userlist:") == 0) {
            std::string payload = msg.substr(9);
            std::string res = UserManager::UserList(payload);
            send(clientSocket, res.c_str(), res.size(), 0);
        }
        else if (msg.compare(0, 12, "productlist:") == 0) {
            std::string payload = msg.substr(12);
            std::string res = UserManager::ProductList(payload);
            send(clientSocket, res.c_str(), res.size(), 0);
        }
        else if (msg.compare(0, 12, "asset") == 0) {
            std::string res = UserManager::Asset(Id);
            send(clientSocket, res.c_str(), res.size(), 0);
        }
    }

    std::cout << "클라이언트 연결 종료" << std::endl;
    closesocket(clientSocket);
}
