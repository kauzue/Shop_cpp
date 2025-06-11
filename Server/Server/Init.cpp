#include "Init.h"
#include <fstream>
#include <filesystem>

void Init::CheckAndCreateFiles() {
    namespace fs = std::filesystem;

    if (!fs::exists("user.csv")) {
        std::ofstream file("user.csv");
        file << "nickname,password\n";
        file.close();
    }

    if (!fs::exists("admin.txt")) {
        std::ofstream file("admin.txt");
        file << "admin:adminpass\n";
        file.close();
    }
}
