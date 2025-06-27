#pragma once

#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
    class ServerConnect;
}

class ServerConnect : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServerConnect(QWidget* parent = nullptr);
    ~ServerConnect();

private slots:
    void on_connectBtn_clicked();
    void on_exitBtn_clicked();

private:
    Ui::ServerConnect* ui;
    QTcpSocket* socket;
};
