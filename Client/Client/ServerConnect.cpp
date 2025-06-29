#include "ServerConnect.h"
#include "ui_ServerConnect.h"
#include "Login.h"
#include <QTcpSocket>
#include <QIntValidator>

ServerConnect::ServerConnect(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::ServerConnect)
{
    ui->setupUi(this);
    ui->portEdit->setValidator(new QIntValidator(1, 65535, this));
    ui->errorLabel->setVisible(false);
    socket = new QTcpSocket();
}

ServerConnect::~ServerConnect()
{
    delete ui;
}

void ServerConnect::on_connectBtn_clicked()
{
    QString ip = ui->ipEdit->text().trimmed();
    QString portStr = ui->portEdit->text().trimmed();

    if (ip.isEmpty() || portStr.isEmpty()) {
        ui->errorLabel->setText("IP와 포트를 모두 입력하세요.");
        ui->errorLabel->setVisible(true);
        return;
    }

    bool ok;
    quint16 port = portStr.toUShort(&ok);
    if (!ok) {
        ui->errorLabel->setText("포트 번호가 올바르지 않습니다.");
        ui->errorLabel->setVisible(true);
        return;
    }

    socket->connectToHost(ip, port);

    if (!socket->waitForConnected(3000)) {
        ui->errorLabel->setText("서버에 연결할 수 없습니다.");
        ui->errorLabel->setVisible(true);
        return;
    }

    Login* loginWindow = new Login(nullptr, socket);
    loginWindow->setAttribute(Qt::WA_DeleteOnClose);
    loginWindow->setWindowTitle("로그인 - " + ip + ":" + QString::number(port));
    loginWindow->show();
    this->close();
}

void ServerConnect::on_exitBtn_clicked()
{
    this->close();
}

void ServerConnect::resizeEvent(QResizeEvent* event) {
    QWidget::resizeEvent(event);

    int fontSize = width() / 40;

    QFont font = ui->ipEdit->font();
    font.setPointSize(fontSize);
	ui->labelIP->setFont(font);
	ui->labelPort->setFont(font);
    ui->ipEdit->setFont(font);
    ui->portEdit->setFont(font);
	ui->connectBtn->setFont(font);
    ui->exitBtn->setFont(font);
    ui->errorLabel->setFont(font);
}
