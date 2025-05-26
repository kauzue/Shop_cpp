#pragma execution_character_set("utf-8")

#include "Login.h"
#include "ui_Login.h"

Login::Login(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::Login)
{
    ui->setupUi(this);

    // 상태 메시지 숨기기 (로그인 실패 메시지용)
    ui->statusLabel->clear();
    ui->statusLabel->setVisible(false);

    // 로그인 버튼 클릭 연결
    connect(ui->loginBtn, &QPushButton::clicked, this, &Login::OnLoginClicked);
}

Login::~Login()
{
    delete ui;
}

void Login::OnLoginClicked()
{
    QString id = ui->idEdit->text();
    QString pw = ui->pwEdit->text();

    // 예시 조건: ID = "user", PW = "1234"
    if (id == "user" && pw == "1234") {
        // 로그인 성공 시 다음 창으로 이동 처리 가능
        // QMessageBox::information(this, "로그인", "로그인 성공!");
        close(); // 임시로 창 닫기
    }
    else {
        ui->statusLabel->setText("아이디 또는 비밀번호가 틀렸습니다.");
        ui->statusLabel->setVisible(true);
    }
}
