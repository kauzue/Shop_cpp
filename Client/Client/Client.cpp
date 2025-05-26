#pragma execution_character_set("utf-8")

#include "Client.h"
#include "ui_Client.h"
#include "Login.h"

#include <QHostAddress>
#include <QMessageBox>
#include <QApplication>

Client::Client(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::Client)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    loginWindow = nullptr;

    ui->statusLabel->clear();

    connect(ui->connectBtn, &QPushButton::clicked, this, &Client::ConnectToServer);
    connect(socket, &QTcpSocket::connected, this, &Client::OnConnected);
    connect(socket, &QTcpSocket::errorOccurred, this, &Client::OnError);
    connect(ui->exitBtn, &QPushButton::clicked, qApp, &QApplication::quit);
}

Client::~Client()
{
    delete ui;
}

void Client::ConnectToServer()
{
    QString ip = ui->ipEdit->text();
    quint16 port = ui->portEdit->text().toUShort();

    ui->statusLabel->clear();
    socket->connectToHost(QHostAddress(ip), port);
    ui->statusLabel->setText("서버에 연결 시도 중...");
}

void Client::OnConnected()
{
    loginWindow = new Login();
    loginWindow->show();
    this->close();
}

void Client::OnError(QAbstractSocket::SocketError)
{
    ui->statusLabel->setText("서버 연결 실패: " + socket->errorString());
}