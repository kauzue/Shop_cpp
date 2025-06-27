#include "Init.h"
#include <fstream>

void Init::CheckFiles() {
    std::ifstream user("user.csv");
    if (!user) {
        std::ofstream out("user.csv");
        out << "nickname,hashed_password\n";
    }

    std::ifstream admin("admin.txt");
    if (!admin) {
        std::ofstream out("admin.txt");
    }
}
