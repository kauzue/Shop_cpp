#include <QApplication>
#include "ServerConnect.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    ServerConnect server;
    server.show();
    return a.exec();
}
