#pragma once

#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
    class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget* parent = nullptr, QTcpSocket* socket = nullptr);
    ~Login();

private slots:
    void OnLoginBtnClicked();
    void OnSignupBtnClicked();
    void OnExitBtnClicked();

private:
    Ui::Login* ui;
    QTcpSocket* socket;
};
