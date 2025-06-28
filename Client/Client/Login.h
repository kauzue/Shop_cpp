#pragma once

#include <QMainWindow>
#include <QtcpSocket>

namespace Ui {
    class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget* parent = nullptr, QTcpSocket* socket = nullptr);
    ~Login();

    void setServerInfo(const QString& ip, quint16 port);

private slots:
    void on_loginBtn_clicked();
    void on_signupBtn_clicked();
    void on_backBtn_clicked();
    void resizeEvent(QResizeEvent* evnet);

private:
    Ui::Login* ui;
    QString serverIp;
    quint16 serverPort;
    QTcpSocket* socket;
};
