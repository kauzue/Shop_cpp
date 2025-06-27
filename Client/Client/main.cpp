#include <QApplication>
#include "ServerConnect.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    ServerConnect w;
    w.show();
    return a.exec();
}
