#include "ServerSocket.h"
#include <iostream>
#include <thread>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <algorithm>
#include <string>

#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

void SendMessageToClient(SOCKET client, const std::string& msg) {
    send(client, msg.c_str(), msg.size(), 0);
}

bool ServerSocket::StartServer(int port) {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup 실패\n";
        return false;
    }

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "소켓 생성 실패\n";
        return false;
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "바인딩 실패\n";
        closesocket(serverSocket);
        WSACleanup();
        return false;
    }

    listen(serverSocket, SOMAXCONN);

    char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        addrinfo hints{}, * res;
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;

        if (getaddrinfo(hostname, NULL, &hints, &res) == 0) {
            sockaddr_in* ipv4 = (sockaddr_in*)res->ai_addr;
            char ipStr[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &(ipv4->sin_addr), ipStr, INET_ADDRSTRLEN);
            std::cout << "서버가 IP: " << ipStr << ", 포트: " << port << " 에서 실행 중입니다.\n";
            freeaddrinfo(res);
        }
        else {
            std::cout << "서버가 포트 " << port << " 에서 실행 중입니다. (IP 조회 실패)\n";
        }
    }
    else {
        std::cout << "서버가 포트 " << port << " 에서 실행 중입니다. (호스트 이름 조회 실패)\n";
    }

    return true;
}

void ServerSocket::AcceptClients() {
    while (true) {
        SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);
        if (clientSocket != INVALID_SOCKET) {
            clients.push_back(clientSocket);
            std::thread(&ServerSocket::HandleClient, this, clientSocket).detach();
        }
    }
}

void ServerSocket::HandleClient(SOCKET clientSocket) {
    char buffer[1024];
    int bytesReceived;

    while ((bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytesReceived] = '\0';
        std::string message(buffer);

        if (message.rfind("SIGNUP:", 0) == 0) {
            std::string data = message.substr(7);
            size_t sep = data.find(':');
            std::string nickname = data.substr(0, sep);
            std::string password = data.substr(sep + 1);

            std::ifstream infile("user.csv");
            std::string line;
            bool duplicate = false;
            std::getline(infile, line);  // 헤더 건너뜀
            while (std::getline(infile, line)) {
                if (line.substr(0, line.find(',')) == nickname) {
                    duplicate = true;
                    break;
                }
            }
            infile.close();

            if (duplicate) {
                SendMessageToClient(clientSocket, "닉네임이 이미 존재합니다.\n");
            }
            else {
                std::ofstream outfile("user.csv", std::ios::app);
                std::hash<std::string> hasher;
                size_t hashed = hasher(password);
                outfile << nickname << "," << hashed << "\n";
                outfile.close();
                SendMessageToClient(clientSocket, "회원가입이 완료되었습니다.\n");
            }
        }
    }

    closesocket(clientSocket);
}
