#pragma once

#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
    class Login;
}

class Login : public QMainWindow {
    Q_OBJECT

public:
    explicit Login(QTcpSocket* socket, QWidget* parent = nullptr);
    ~Login();

private slots:
    void onLoginClicked();
    void onExitClicked();

private:
    Ui::Login* ui;
    QTcpSocket* socket;  // 서버 연결용 소켓
};
