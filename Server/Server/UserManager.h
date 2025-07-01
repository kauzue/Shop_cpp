#pragma once
#include <string>

class UserManager {
public:
    static std::string Signup(const std::string& payload);
    static std::string Login(const std::string& payload);
    static std::string AddProduct(const std::string& Id, const std::string& payload);
    static std::string ChangeId(const std::string& Id, const std::string& payload);
    static std::string ChangePw(const std::string& Id, const std::string& payload);
};
