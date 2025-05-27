#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QTcpSocket* socket, QWidget* parent)
    : QMainWindow(parent), ui(new Ui::Login), socket(socket) {
    ui->setupUi(this);

    connect(ui->loginBtn, &QPushButton::clicked, this, &Login::onLoginClicked);
    connect(ui->exitBtn, &QPushButton::clicked, this, &Login::onExitClicked);
}

Login::~Login() {
    delete ui;
}

void Login::onLoginClicked() {
    QString id = ui->idEdit->text();
    QString pw = ui->pwEdit->text();

    if (id == "admin" && pw == "1234") {
        QMessageBox::information(this, "로그인 성공", "환영합니다.");
        // 다음 화면 전환 구현
    }
    else {
        QMessageBox::warning(this, "로그인 실패", "아이디 또는 비밀번호가 잘못되었습니다.");
    }
}

void Login::onExitClicked() {
    if (socket && socket->state() == QAbstractSocket::ConnectedState) {
        socket->disconnectFromHost();
    }
    this->close();
}
