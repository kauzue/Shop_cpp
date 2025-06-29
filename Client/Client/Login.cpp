#include "Login.h"
#include "ui_Login.h"
#include "Signup.h"
#include "ServerConnect.h"
#include "MainMenu.h"
#include <QMessageBox>

Login::Login(QWidget* parent, QTcpSocket* socket)
    : QMainWindow(parent), ui(new Ui::Login), socket(socket)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::setServerInfo(const QString& ip, quint16 port)
{
    serverIp = ip;
    serverPort = port;
}

void Login::on_loginBtn_clicked()
{
    QString nickname = ui->nicknameEdit->text().trimmed();
    QString password = ui->passwordEdit->text();

    if (nickname.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "입력 오류", "닉네임과 비밀번호를 모두 입력하세요.");
        return;
    }

    QString msg = "login:" + nickname + ":" + password;
    socket->write(msg.toUtf8());
    socket->flush();

    if (socket->waitForReadyRead(3000)) {
        QString response = QString::fromUtf8(socket->readAll()).trimmed();
        if (response == "success") {
            QMessageBox::information(this, "로그인 성공", "로그인에 성공했습니다.");

            MainMenu* MainMenuWindow = new MainMenu(nullptr, socket);
            MainMenuWindow->setAttribute(Qt::WA_DeleteOnClose);
            MainMenuWindow->show();
            this->close();
        }
        else if (response == "success:admin") {
            QMessageBox::information(this, "관리자", "관리자 계정으로 로그인하였습니다.");

            //이거 수정해서 관리자 화면 띄우면 됨
            /*Login* loginWindow = new Login(nullptr, socket);
            loginWindow->setAttribute(Qt::WA_DeleteOnClose);
            loginWindow->show();
            this->close();*/
        }
        else if (response == "fail") {
            QMessageBox::warning(this, "실패", "아이디 혹은 비밀번호가 일치하지 않습니다.");
        }
        else {
            QMessageBox::warning(this, "오류", "오류 : " + response);
        }
    }
    else {
        QMessageBox::warning(this, "오류", "서버로 부터 응답이 없습니다.");
    }
}

void Login::on_signupBtn_clicked()
{
    Signup* signupWindow = new Signup(nullptr, socket);
    signupWindow->setAttribute(Qt::WA_DeleteOnClose);
    signupWindow->show();
    this->close();
}

void Login::on_backBtn_clicked()
{
    socket->disconnectFromHost();
    if (socket->state() != QAbstractSocket::UnconnectedState) {
        socket->waitForDisconnected(3000);
    }
    ServerConnect* serverConnectWindow = new ServerConnect;
    serverConnectWindow->setAttribute(Qt::WA_DeleteOnClose);
    serverConnectWindow->show();
    this->close();
}

void Login::resizeEvent(QResizeEvent* event) {
    QWidget::resizeEvent(event);

    int fontSize = width() / 40;

    QFont font = ui->nicknameEdit->font();
    font.setPointSize(fontSize);
	ui->labelNickname->setFont(font);
	ui->labelPassword->setFont(font);
    ui->nicknameEdit->setFont(font);
    ui->passwordEdit->setFont(font);
    ui->loginBtn->setFont(font);
    ui->signupBtn->setFont(font);
	ui->backBtn->setFont(font);
}
