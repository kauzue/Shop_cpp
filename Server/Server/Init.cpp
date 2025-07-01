#include "Init.h"
#include <fstream>

void Init::CheckFiles() {
    std::ifstream user("user.csv");
    if (!user) {
        std::ofstream out("user.csv");
        out << "���̵�,��й�ȣ(�ؽ�),�����ݾ�\n";
    }

    std::ifstream admin("admin.txt");
    if (!admin) {
        std::ofstream out("admin.txt");
    }

	std::ifstream product("product.csv");
    if (!product) {
        std::ofstream out("product.csv");
        out << "�̸�,����,����,�Ǹ���\n";
    }
}
