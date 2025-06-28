#include "Signup.h"
#include "ui_Signup.h"
#include "Login.h"
#include <QMessageBox>

Signup::Signup(QWidget* parent, QTcpSocket* socket)
    : QMainWindow(parent), ui(new Ui::Signup), socket(socket)
{
    ui->setupUi(this);
}

Signup::~Signup()
{
    delete ui;
}

void Signup::on_signupBtn_clicked()
{
    QString nickname = ui->nicknameEdit->text().trimmed();
    QString password = ui->passwordEdit->text();
    QString confirm = ui->confirmEdit->text();

    if (nickname.isEmpty() || password.isEmpty() || confirm.isEmpty()) {
        QMessageBox::warning(this, "입력 오류", "모든 항목을 입력하세요.");
        return;
    }

    if (password != confirm) {
        QMessageBox::warning(this, "입력 오류", "비밀번호가 일치하지 않습니다.");
        return;
    }

	QString msg = "signup:" + nickname + ":" + password;
	socket->write(msg.toUtf8());
	socket->flush();

    if (socket->waitForReadyRead(3000)) {
		QString response = QString::fromUtf8(socket->readAll()).trimmed();
        if (response == "success") {
            QMessageBox::information(this, "회원가입 성공", "회원가입이 완료되었습니다.");
            Login* loginWindow = new Login(nullptr, socket);
            loginWindow->setAttribute(Qt::WA_DeleteOnClose);
            loginWindow->show();
            this->close();
        }
        else if (response == "duplicate") {
            QMessageBox::warning(this, "중복", "이미 존재하는 닉네임입니다.");
        }
        else {
            QMessageBox::warning(this, "오류", "오류 : " + response);
        }
    }
    else {
        QMessageBox::warning(this, "오류", "서버로 부터 응답이 없습니다.");
    }
}

void Signup::on_backBtn_clicked()
{
    Login* loginWindow = new Login(nullptr, socket);
    loginWindow->setAttribute(Qt::WA_DeleteOnClose);
    loginWindow->show();
    this->close();
}

void Signup::resizeEvent(QResizeEvent* event) {
    QWidget::resizeEvent(event);

    int fontSize = width() / 40;

    QFont font = ui->nicknameEdit->font();
    font.setPointSize(fontSize);
	ui->labelNickname->setFont(font);
	ui->labelPassword->setFont(font);
	ui->labelConfirm->setFont(font);
    ui->nicknameEdit->setFont(font);
    ui->passwordEdit->setFont(font);
    ui->confirmEdit->setFont(font);
    ui->signupBtn->setFont(font);
    ui->backBtn->setFont(font);
}
