#include "signup.h"
#include "ui_signup.h"
#include <QMessageBox>

Signup::Signup(QWidget* parent, QTcpSocket* socket)
    : QMainWindow(parent)
    , ui(new Ui::Signup)
    , socket(socket)
{
    ui->setupUi(this);

    connect(ui->signupBtn, &QPushButton::clicked, this, &Signup::OnSignupBtnClicked);
    connect(ui->exitBtn, &QPushButton::clicked, this, &Signup::OnExitBtnClicked);  // 이름 변경됨
}

Signup::~Signup()
{
    delete ui;
}

void Signup::OnSignupBtnClicked()
{
    QString id = ui->idEdit->text();
    QString pw = ui->pwEdit->text();

    if (id.isEmpty() || pw.isEmpty()) {
        QMessageBox::warning(this, "입력 오류", "아이디와 비밀번호를 입력하세요.");
        return;
    }

    QString msg = "signup:" + id + ":" + pw + "\n";
    socket->write(msg.toUtf8());
    socket->flush();

    if (socket->waitForReadyRead(2000)) {
        QString response = QString::fromUtf8(socket->readAll());
        if (response.contains("signup:success")) {
            QMessageBox::information(this, "성공", "회원가입이 완료되었습니다.");
            close();
        }
        else {
            QMessageBox::warning(this, "실패", "회원가입에 실패했습니다.");
        }
    }
    else {
        QMessageBox::warning(this, "오류", "서버 응답이 없습니다.");
    }
}

void Signup::OnExitBtnClicked()  // 이름 변경됨
{
    close();
}
