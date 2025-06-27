#pragma once
#include <string>

class UserManager {
public:
    static std::string Signup(const std::string& payload);
    static std::string Login(const std::string& payload);
};
