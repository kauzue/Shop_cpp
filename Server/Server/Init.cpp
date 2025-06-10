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
            userCreate << "id,password\n"; // 헤더 줄 추가
            std::cout << "[시스템] user.csv 파일이 생성되었습니다.\n";
        }
    }

    std::ifstream adminCheck(adminFile);
    if (!adminCheck.is_open()) {
        std::ofstream adminCreate(adminFile);
        if (adminCreate.is_open()) {
            adminCreate << "admin";
            std::cout << "[시스템] admin.txt 파일이 생성되었습니다.\n";
        }
    }
}
