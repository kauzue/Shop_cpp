#pragma once

#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
    class Client;
}

class Client : public QMainWindow {
    Q_OBJECT

public:
    explicit Client(QWidget* parent = nullptr);
    ~Client();

private slots:
    void OnConnectClicked();
    void OnExitClicked();
    void OnReadyRead();

private:
    Ui::Client* ui;
    QTcpSocket* socket;
    void ShowError(const QString& message);
};
