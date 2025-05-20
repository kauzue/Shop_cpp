#include "ClientSocket.h"
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>  // InetPtonA 사용 위해 필요

ClientSocket::ClientSocket() : socket(INVALID_SOCKET) {}

ClientSocket::~ClientSocket() {
    closesocket(socket);
    WSACleanup();
}

bool ClientSocket::InitWinSock() {
    WSADATA wsaData;
    return WSAStartup(MAKEWORD(2, 2), &wsaData) == 0;
}

bool ClientSocket::ConnectToServer(const std::string& ip, int port) {
    if (!InitWinSock()) {
        std::cerr << "WinSock 초기화 실패\n";
        return false;
    }

    socket = ::socket(AF_INET, SOCK_STREAM, 0);
    if (socket == INVALID_SOCKET) {
        std::cerr << "소켓 생성 실패\n";
        return false;
    }

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    // ANSI 버전 함수 명시 호출
    if (InetPtonA(AF_INET, ip.c_str(), &addr.sin_addr) != 1) {
        std::cerr << "IP 주소 변환 실패\n";
        return false;
    }

    if (connect(socket, (SOCKADDR*)&addr, sizeof(addr)) == SOCKET_ERROR) {
        std::cerr << "서버 연결 실패\n";
        return false;
    }

    std::cout << "서버에 연결됨\n";
    return true;
}

bool ClientSocket::SendMessage(const std::string& msg) {
    int result = send(socket, msg.c_str(), msg.size(), 0);
    return result != SOCKET_ERROR;
}

std::string ClientSocket::ReceiveMessage() {
    char buffer[1024] = {};
    int len = recv(socket, buffer, sizeof(buffer), 0);
    if (len <= 0) return "";
    return std::string(buffer, len);
}
