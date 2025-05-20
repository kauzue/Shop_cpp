#include "ServerSocket.h"
#include <iostream>
#include <thread>
#include <ws2tcpip.h>
#include <iphlpapi.h>

#pragma comment(lib, "iphlpapi.lib")

ServerSocket::ServerSocket() : socket(INVALID_SOCKET) {}

ServerSocket::~ServerSocket() {
    for (SOCKET client : clients) {
        closesocket(client);
    }
    closesocket(socket);
    WSACleanup();
}

bool ServerSocket::InitWinSock() {
    WSADATA wsaData;
    return WSAStartup(MAKEWORD(2, 2), &wsaData) == 0;
}

// 서버 시작 (소켓 생성, 바인딩, 리슨)
bool ServerSocket::Start(int port) {
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
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(socket, (SOCKADDR*)&addr, sizeof(addr)) == SOCKET_ERROR) {
        std::cerr << "바인딩 실패\n";
        return false;
    }

    if (listen(socket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "리슨 실패\n";
        return false;
    }

    std::cout << "서버 IP 주소: " << GetLocalIPAddress() << "\n";
    std::cout << "서버 포트: " << port << "\n";

    return true;
}

// 클라이언트 처리 함수
void HandleClient(SOCKET client) {
    char buffer[1024] = {};
    while (true) {
        int len = recv(client, buffer, sizeof(buffer), 0);
        if (len <= 0) break;

        std::string msg(buffer, len);
        std::cout << "[클라이언트] " << msg << "\n";

        // 클라이언트에게 에코 응답
        send(client, msg.c_str(), msg.size(), 0);
    }

    closesocket(client);
}

// 클라이언트 연결 수락
void ServerSocket::AcceptClients() {
    std::cout << "클라이언트 연결 대기 중...\n";

    while (true) {
        SOCKET client = accept(socket, nullptr, nullptr);
        if (client == INVALID_SOCKET) continue;

        clients.push_back(client);
        std::thread(HandleClient, client).detach();
    }
}

// IPv4 주소 가져오기 (루프백 제외)
std::string ServerSocket::GetLocalIPAddress() {
    ULONG outBufLen = 15000;
    IP_ADAPTER_ADDRESSES* pAddresses = (IP_ADAPTER_ADDRESSES*)malloc(outBufLen);
    if (!pAddresses) return "Unknown";

    DWORD result = GetAdaptersAddresses(AF_INET, 0, nullptr, pAddresses, &outBufLen);
    if (result != NO_ERROR) {
        free(pAddresses);
        return "Unknown";
    }

    std::string ip = "Unknown";
    for (IP_ADAPTER_ADDRESSES* adapter = pAddresses; adapter != nullptr; adapter = adapter->Next) {
        if (adapter->OperStatus != IfOperStatusUp) continue;

        for (IP_ADAPTER_UNICAST_ADDRESS* unicast = adapter->FirstUnicastAddress;
            unicast != nullptr; unicast = unicast->Next) {

            SOCKADDR_IN* sa = (SOCKADDR_IN*)unicast->Address.lpSockaddr;
            char buf[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &sa->sin_addr, buf, INET_ADDRSTRLEN);

            std::string ipStr(buf);
            if (ipStr != "127.0.0.1") {
                ip = ipStr;
                break;
            }
        }

        if (ip != "Unknown") break;
    }

    free(pAddresses);
    return ip;
}
