#include "Init.h"
#include "ServerSocket.h"

int main() {
    Init::CheckAndCreateFiles();

    ServerSocket server;
    if (server.StartServer(8080)) {
        server.AcceptClients();
    }

    return 0;
}
