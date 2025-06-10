#pragma once

#include <string>

class Init {
private:
    std::string userFile;
    std::string adminFile;

public:
    Init();
    void CheckAndCreateFiles();
};
