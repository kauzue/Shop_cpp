#include "Init.h"
#include <fstream>
#include <iostream>

Init::Init() {
    userFile = "user.csv";
    adminFile = "admin.txt";
}

void Init::CheckAndCreateFiles() {
    std::ifstream userCheck(userFile);
    if (!userCheck.is_open()) {
        std::ofstream userCreate(userFile);
        if (userCreate.is_open()) {
            userCreate << "id,password\n"; // ��� �� �߰�
            std::cout << "[�ý���] user.csv ������ �����Ǿ����ϴ�.\n";
        }
    }

    std::ifstream adminCheck(adminFile);
    if (!adminCheck.is_open()) {
        std::ofstream adminCreate(adminFile);
        if (adminCreate.is_open()) {
            adminCreate << "admin";
            std::cout << "[�ý���] admin.txt ������ �����Ǿ����ϴ�.\n";
        }
    }
}
