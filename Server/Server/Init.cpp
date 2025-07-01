#include "Init.h"
#include <fstream>

void Init::CheckFiles() {
    std::ifstream user("user.csv");
    if (!user) {
        std::ofstream out("user.csv");
        out << "아이디,비밀번호(해시),보유금액\n";
    }

    std::ifstream admin("admin.txt");
    if (!admin) {
        std::ofstream out("admin.txt");
    }

	std::ifstream product("product.csv");
    if (!product) {
        std::ofstream out("product.csv");
        out << "이름,개수,수량,판매자\n";
    }
}
