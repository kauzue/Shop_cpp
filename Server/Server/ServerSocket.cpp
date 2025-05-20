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

// ���� ���� (���� ����, ���ε�, ����)
bool ServerSocket::Start(int port) {
    if (!InitWinSock()) {
        std::cerr << "WinSock �ʱ�ȭ ����\n";
        return false;
    }

    socket = ::socket(AF_INET, SOCK_STREAM, 0);
    if (socket == INVALID_SOCKET) {
        std::cerr << "���� ���� ����\n";
        return false;
    }

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(socket, (SOCKADDR*)&addr, sizeof(addr)) == SOCKET_ERROR) {
        std::cerr << "���ε� ����\n";
        return false;
    }

    if (listen(socket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "���� ����\n";
        return false;
    }

    std::cout << "���� IP �ּ�: " << GetLocalIPAddress() << "\n";
    std::cout << "���� ��Ʈ: " << port << "\n";

    return true;
}

// Ŭ���̾�Ʈ ó�� �Լ�
void HandleClient(SOCKET client) {
    char buffer[1024] = {};
    while (true) {
        int len = recv(client, buffer, sizeof(buffer), 0);
        if (len <= 0) break;

        std::string msg(buffer, len);
        std::cout << "[Ŭ���̾�Ʈ] " << msg << "\n";

        // Ŭ���̾�Ʈ���� ���� ����
        send(client, msg.c_str(), msg.size(), 0);
    }

    closesocket(client);
}

// Ŭ���̾�Ʈ ���� ����
void ServerSocket::AcceptClients() {
    std::cout << "Ŭ���̾�Ʈ ���� ��� ��...\n";

    while (true) {
        SOCKET client = accept(socket, nullptr, nullptr);
        if (client == INVALID_SOCKET) continue;

        clients.push_back(client);
        std::thread(HandleClient, client).detach();
    }
}

// IPv4 �ּ� �������� (������ ����)
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
