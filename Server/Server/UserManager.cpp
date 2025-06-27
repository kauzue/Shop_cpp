#include "UserManager.h"
#include <fstream>
#include <sstream>
#include <functional>

std::string UserManager::Signup(const std::string& payload) {
    size_t sep = payload.find(':');
    if (sep == std::string::npos) return "error";

    std::string nickname = payload.substr(0, sep);
    std::string password = payload.substr(sep + 1);

    std::ifstream in("user.csv");
    std::string line;
    while (std::getline(in, line)) {
        std::istringstream ss(line);
        std::string existing;
        std::getline(ss, existing, ',');
        if (existing == nickname)
            return "duplicate";
    }

    std::hash<std::string> hasher;
    size_t hash = hasher(password);

    std::ofstream out("user.csv", std::ios::app);
    out << nickname << "," << hash << "\n";

    return "success";
}

std::string UserManager::Login(const std::string& payload) {
    size_t sep = payload.find(':');
    if (sep == std::string::npos) return "error";

    std::string nickname = payload.substr(0, sep);
    std::string password = payload.substr(sep + 1);
    std::hash<std::string> hasher;
    size_t hash = hasher(password);

    std::ifstream in("user.csv");
    std::string line;
    while (std::getline(in, line)) {
        std::istringstream ss(line);
        std::string storedNick, storedHash;
        std::getline(ss, storedNick, ',');
        std::getline(ss, storedHash);

        if (storedNick == nickname && storedHash == std::to_string(hash)) {
            std::ifstream admin("admin.txt");
            std::string adminName;
            while (std::getline(admin, adminName)) {
                if (adminName == nickname)
                    return "success:admin";
            }
            return "success";
        }
    }

    return "fail";
}

