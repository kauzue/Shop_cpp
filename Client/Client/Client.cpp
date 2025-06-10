#include "client.h"
#include "ui_client.h"
#include "login.h"
#include <QMessageBox>

Client::Client(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::Client), socket(new QTcpSocket(this)) {
    ui->setupUi(this);

    connect(ui->connectBtn, &QPushButton::clicked, this, &Client::OnConnectClicked);
    connect(ui->exitBtn, &QPushButton::clicked, this, &Client::OnExitClicked);
    connect(socket, &QTcpSocket::readyRead, this, &Client::OnReadyRead);
}

Client::~Client() {
    socket->disconnectFromHost();
    delete ui;
}

void Client::OnConnectClicked() {
    QString ip = ui->ipEdit->text();
    quint16 port = ui->portEdit->text().toUShort();

    socket->connectToHost(ip, port);
    if (!socket->waitForConnected(3000)) {
        ShowError("서버에 연결할 수 없습니다.");
        return;
    }

    Login* loginWindow = new Login(this, socket);  // socket 포인터 넘겨줌
    loginWindow->show();
    this->hide();
}

void Client::OnExitClicked() {
    socket->disconnectFromHost();
    QApplication::quit();
}

void Client::OnReadyRead() {
    // 서버에서 초기 메시지 수신 처리 (예: 환영 메시지)
}

void Client::ShowError(const QString& message) {
    ui->statusLabel->setText(message);
}
