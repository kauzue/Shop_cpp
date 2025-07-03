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

std::string UserManager::UserChange(const std::string& payload)
{
    size_t firstSep = payload.find(':');
    size_t secondSep = payload.find(':', firstSep + 1);
    size_t thirdSep = payload.find(':', secondSep + 1);
    if (firstSep == std::string::npos || secondSep == std::string::npos) {
        return "error";
    }

    std::string Id = payload.substr(0, firstSep);
    std::string userId = payload.substr(firstSep + 1, secondSep - firstSep - 1);
    std::string userPw = payload.substr(secondSep + 1, thirdSep - secondSep - 1);
    std::hash<std::string> hasher;
    std::string newHash = std::to_string(hasher(userPw));
    std::string userAsset = payload.substr(thirdSep + 1);

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
			users.emplace_back(userId, newHash, userAsset);
            found = true;
        }
        else {
            users.emplace_back(storedId, storedHash, storedAsset);
        }
    }

    in.close();

    if (!found) {
        return "notfound";
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

std::string UserManager::UserList(const std::string& payload)
{
    int page = std::stoi(payload);
    int startIdx = page * 4 + 1;
    int user = 0;
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

        users.emplace_back(storedId, storedHash, storedAsset);

        user++;
    }

    in.close();

    std::string response;
    for (int i = startIdx; i < startIdx + 4 && i < users.size(); i++) {
        auto& [Id, Pw, asset] = users[i];
        response += Id + "," + Pw + "," + asset + "\n";
    }

    user -= 1;
    page = user / 4;

    if (user % 4 == 0) {
        page -= 1;
        return std::to_string(page) + "\n" + response;
    }
    else {
        return std::to_string(page) + "\n" + response;
    }
}

std::string UserManager::ProductList(const std::string& payload)
{
    int page = std::stoi(payload);
    int startIdx = page * 4 + 1;
    int product = 0;
    std::ifstream in("product.csv");
    if (!in.is_open()) {
        return "error";
    }

    std::vector<std::tuple<std::string, std::string, std::string, std::string>> products;
    std::string line;
    bool found = false;

    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string storedName, storedPrice, storedQuantity, storedUser;
        std::getline(ss, storedName, ',');
        std::getline(ss, storedPrice, ',');
        std::getline(ss, storedQuantity, ',');
        std::getline(ss, storedUser);

        products.emplace_back(storedName, storedPrice, storedQuantity, storedUser);
        product++;
    }

    in.close();

    std::string response;
    for (int i = startIdx; i < startIdx + 4 && i < products.size(); i++) {
        auto& [name, price, quantity, User] = products[i];
        response += name + "," + price + "," + quantity + "," + User + "\n";
    }

    product -= 1;
    page = product / 4;

    if (product % 4 == 0) {
        page -= 1;
        return std::to_string(page) + "\n" + response;
    }
    else {
        return std::to_string(page) + "\n" + response;
    }
}

std::string UserManager::Asset(const std::string& Id)
{
    std::ifstream in("user.csv");
    if (!in.is_open()) {
        return "error";
    }

    std::string line;

    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string storedId, storedHash, storedAsset;
        std::getline(ss, storedId, ',');
        std::getline(ss, storedHash, ',');
        std::getline(ss, storedAsset);

        if (storedId == Id) {
            in.close();
            return storedAsset;
        }
    }

    in.close();
    
    return "not found";
}

std::string UserManager::BuyProduct(const std::string& Id, const std::string& product)
{
    int num = 0;
    int targetQuantity;
    std::string seller;
    size_t sep = product.find(':');
    std::ifstream iu("user.csv");
    if (!iu.is_open()) {
        return "error";
    }

    std::ifstream ip("product.csv");
    if (!iu.is_open()) {
        return "error";
    }

    int targetLine = std::stoi(product.substr(0, sep)) * 4 + std::stoi(product.substr(sep + 1));
    std::vector < std::tuple<std::string, std::string, std::string, std::string>> products;
    std::vector < std::tuple<std::string, std::string, std::string>> users1;
    std::vector < std::tuple<std::string, std::string, std::string>> users2;
    std::string line1;
    std::string line2;
    std::string line3;
    bool found = false;
    bool sufficient = false;

    while (std::getline(ip, line1)) {
        std::stringstream ss1(line1);
        std::string storedName, storedPrice, storedQuantity, storedUser;
        std::getline(ss1, storedName, ',');
        std::getline(ss1, storedPrice, ',');
        std::getline(ss1, storedQuantity, ',');
        std::getline(ss1, storedUser);

        if (targetLine == num) {
            seller = storedUser;
            while (std::getline(iu, line2)) {
                std::stringstream ss2(line2);
                std::string storedId, storedHash, storedAsset;
                std::getline(ss2, storedId, ',');
                std::getline(ss2, storedHash, ',');
                std::getline(ss2, storedAsset);

                if (storedId == Id) {
                    if (std::stoi(storedAsset) >= std::stoi(storedPrice)) {
                        users1.emplace_back(storedId, storedHash, std::to_string(std::stoi(storedAsset) - std::stoi(storedPrice)));
                        sufficient = true;
                    }
                }
                else {
                    users1.emplace_back(storedId, storedHash, storedAsset);
                }
            }

            std::ofstream ou("user.csv", std::ios::trunc);
            if (!ou.is_open()) {
                return "error";
            }

            for (const auto& user : users1) {
                ou << std::get<0>(user) << "," << std::get<1>(user) << "," << std::get<2>(user) << "\n";
            }
            ou.close();
            iu.close();

            std::ifstream iu("user.csv");
            if (!iu.is_open()) {
                return "error";
            }
            while (std::getline(iu, line3)) {
                if (sufficient) {
                    std::stringstream ss£³(line3);
                    std::string storedId, storedHash, storedAsset;
                    std::getline(ss£³, storedId, ',');
                    std::getline(ss£³, storedHash, ',');
                    std::getline(ss£³, storedAsset);

                    if (storedId == seller) {
                        users2.emplace_back(storedId, storedHash, std::to_string(std::stoi(storedAsset) + std::stoi(storedPrice)));
                    }
                    else {
                        users2.emplace_back(storedId, storedHash, storedAsset);
                    }
                }
            }
            iu.close();

            targetQuantity = std::stoi(storedQuantity) - 1;
            if (sufficient) {
                if (targetQuantity != 0) {
                    products.emplace_back(storedName, storedPrice, std::to_string(targetQuantity), storedUser);
                }
            }
            else {
                products.emplace_back(storedName, storedPrice, storedQuantity, storedUser);
            }
            
            found = true;
        }
        else {
            products.emplace_back(storedName, storedPrice, storedQuantity, storedUser);
        }
        num++;
    }

    ip.close();

    if (!found) {
        return "not found";
    }

    if (!sufficient) {
        return "not sufficient";
    }

    std::ofstream ou("user.csv", std::ios::trunc);
    if (!ou.is_open()) {
        return "error";
    }

    for (const auto& user : users2) {
        ou << std::get<0>(user) << "," << std::get<1>(user) << "," << std::get<2>(user) << "\n";
    }
    ou.close();

    std::ofstream op("product.csv", std::ios::trunc);
    if (!op.is_open()) {
        return "error";
    }

    for (const auto& product : products) {
        op << std::get<0>(product) << "," << std::get<1>(product) << "," << std::get<2>(product) << "," << std::get<3>(product) << "\n";
    }
    op.close();

    return "success";
}