#include <fstream>
#include <sstream>
#include <functional>
#include <iostream>

#include "UserManager.h"
#include "ClientHandler.h"

std::string UserManager::Signup(const std::string& payload) {
    size_t sep = payload.find(':');
    if (sep == std::string::npos) return "error";

    std::string Id = payload.substr(0, sep);
    std::string password = payload.substr(sep + 1);

    std::ifstream in("user.csv");
    std::string line;
    while (std::getline(in, line)) {
        std::istringstream ss(line);
        std::string existing;
        std::getline(ss, existing, ',');
        if (existing == Id)
            return "duplicate";
    }

    std::hash<std::string> hasher;
    size_t hash = hasher(password);

    std::ofstream out("user.csv", std::ios::app);
    out << Id << "," << hash << "," << "1000" << "\n";

    return "success";
}

std::string UserManager::Login(const std::string& payload) {
    size_t sep = payload.find(':');
    if (sep == std::string::npos) {
        return "error";
    }

    std::string Id = payload.substr(0, sep);
    std::string password = payload.substr(sep + 1);
    std::hash<std::string> hasher;
    size_t hash = hasher(password);

    std::ifstream in("user.csv");
    std::string line;
    while (std::getline(in, line)) {
        std::istringstream ss(line);
        std::string storedId, storedHash, storedAsset;
        std::getline(ss, storedId, ',');
        std::getline(ss, storedHash, ',');
        std::getline(ss, storedAsset);

        if (storedId == Id && storedHash == std::to_string(hash)) {
            std::ifstream admin("admin.txt");
            std::string adminId;
            while (std::getline(admin, adminId)) {
                if (adminId == Id)
                    return "success:admin";
            }
            return "success";
        }
    }

    in.close();

    return "fail";
}

std::string UserManager::AddProduct(const std::string& Id, const std::string& payload)
{
    size_t firstSep = payload.find(':');
    size_t secondSep = payload.find(':', firstSep + 1);
    if (firstSep == std::string::npos || secondSep == std::string::npos) {
		return "error";
    }

	std::string productName = payload.substr(0, firstSep);
	std::string productPrice = payload.substr(firstSep + 1, secondSep - firstSep - 1);
    std::string productQuantity = payload.substr(secondSep + 1);

    std::ofstream out("product.csv", std::ios::app);
    out << productName << "," << productPrice << "," << productQuantity << "," << Id << "\n";

    return "success";
}

std::string UserManager::ChangeId(const std::string& Id, const std::string& payload)
{
    std::string newId = payload;

    std::ifstream in("user.csv");
    if (!in.is_open()) {
        return "error";
    }

    std::vector<std::tuple<std::string, std::string, std::string>> users;
    std::string line;
    bool found = false;

    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string storedId, storedHash, storedAsset;
        std::getline(ss, storedId, ',');
        std::getline(ss, storedHash, ',');
        std::getline(ss, storedAsset);

        if (storedId == newId) {
            return "duplicate";
        }

        if (storedId == Id) {
            users.emplace_back(newId, storedHash, storedAsset);
            found = true;
        }
        else {
            users.emplace_back(storedId, storedHash, storedAsset);
        }
    }

    in.close();

    if (!found) {
        return "error";
    }

    std::ofstream out("user.csv", std::ios::trunc);
    if (!out.is_open()) {
        return "error";
    }

    for (const auto& user : users) {
        out << std::get<0>(user) << "," << std::get<1>(user) << "," << std::get<2>(user) << "\n";
    }

    out.close();
    return "success";
}

std::string UserManager::ChangePw(const std::string& Id, const std::string& payload)
{
    std::string newPw = payload;
    std::hash<std::string> hasher;
    std::string newHash = std::to_string(hasher(newPw));

    std::ifstream in("user.csv");
    if (!in.is_open()) {
        return "error";
    }

    std::vector<std::tuple<std::string, std::string, std::string>> users;
    std::string line;
    bool found = false;

    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string storedId, storedHash, storedAsset;
        std::getline(ss, storedId, ',');
        std::getline(ss, storedHash, ',');
        std::getline(ss, storedAsset);

        if (storedId == Id) {
            users.emplace_back(storedId, newHash, storedAsset);
            found = true;
        }
        else {
            users.emplace_back(storedId, storedHash, storedAsset);
        }
    }

    in.close();

    if (!found) {
        return "error";
    }

    std::ofstream out("user.csv", std::ios::trunc);
    if (!out.is_open()) {
        return "error";
    }

    for (const auto& user : users) {
        out << std::get<0>(user) << "," << std::get<1>(user) << "," << std::get<2>(user) << "\n";
    }

    out.close();
    return "success";
}

std::string UserManager::DeleteAccount(const std::string& Id, const std::string& payload)
{
    std::ifstream in("user.csv");
    if (!in.is_open()) {
        return "error";
    }

    std::vector<std::tuple<std::string, std::string, std::string>> users;
    std::string line;
    bool found = false;

    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string storedId, storedHash, storedAsset;
        std::getline(ss, storedId, ',');
        std::getline(ss, storedHash, ',');
        std::getline(ss, storedAsset);

        if (storedId == Id) {
            found = true;
        }
        else {
            users.emplace_back(storedId, storedHash, storedAsset);
        }
    }

    in.close();

    if (!found) {
        return "error";
    }

    std::ofstream out("user.csv", std::ios::trunc);
    if (!out.is_open()) {
        return "error";
    }

    for (const auto& user : users) {
        out << std::get<0>(user) << "," << std::get<1>(user) << "," << std::get<2>(user) << "\n";
    }

    out.close();
    return "success";
}