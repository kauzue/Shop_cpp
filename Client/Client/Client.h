#pragma once

#include <QMainWindow>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Client; }
QT_END_NAMESPACE

class Login;

class Client : public QMainWindow
{
    Q_OBJECT

private:
    Ui::Client* ui;
    QTcpSocket* socket;
    Login* loginWindow;

public:
    Client(QWidget* parent = nullptr);
    ~Client();

private slots:
    void ConnectToServer();
    void OnConnected();
    void OnError(QAbstractSocket::SocketError socketError);
};