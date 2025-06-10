#include "login.h"
#include "ui_login.h"
#include "signup.h"

#include <QMessageBox>

Login::Login(QWidget* parent, QTcpSocket* socket)
    : QMainWindow(parent)
    , ui(new Ui::Login)
    , socket(socket)
{
    ui->setupUi(this);

    connect(ui->loginBtn, &QPushButton::clicked, this, &Login::OnLoginBtnClicked);
    connect(ui->signupBtn, &QPushButton::clicked, this, &Login::OnSignupBtnClicked);
    connect(ui->exitBtn, &QPushButton::clicked, this, &Login::OnExitBtnClicked);
}

Login::~Login()
{
    delete ui;
}

void Login::OnLoginBtnClicked()
{
    if (!socket || socket->state() != QAbstractSocket::ConnectedState) {
        QMessageBox::critical(this, "연결 실패", "서버에 연결되어 있지 않습니다.");
        return;
    }

    QString id = ui->idEdit->text();
    QString pw = ui->pwEdit->text();

    if (id.isEmpty() || pw.isEmpty()) {
        QMessageBox::warning(this, "입력 오류", "아이디와 비밀번호를 모두 입력하세요.");
        return;
    }

    QString loginMsg = "login:" + id + ":" + pw + "\n";
    socket->write(loginMsg.toUtf8());
    socket->flush();

    if (socket->waitForReadyRead(2000)) {
        QByteArray response = socket->readAll();
        QString reply(response);

        if (reply.contains("login:success")) {
            QMessageBox::information(this, "로그인 성공", "로그인에 성공했습니다.");
            // TODO: 메인 화면으로 이동하는 코드 추가
        }
        else {
            ui->statusLabel->setText("아이디 또는 비밀번호가 잘못되었습니다.");
        }
    }
    else {
        QMessageBox::warning(this, "응답 없음", "서버로부터 응답이 없습니다.");
    }
}

void Login::OnSignupBtnClicked()
{
    Signup* signupWindow = new Signup(this, socket);
    signupWindow->show();
}

void Login::OnExitBtnClicked()
{
    if (socket && socket->isOpen()) {
        socket->disconnectFromHost();
    }
    close();
}
