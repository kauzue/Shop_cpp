#include <QIntValidator>
#include <QMessageBox>

#include "MainMenu.h"
#include "ui_MainMenu.h"
#include "Login.h"

MainMenu::MainMenu(QWidget* parent, QTcpSocket* socket)
    : QMainWindow(parent), ui(new Ui::MainMenu), socket(socket)
{
    ui->setupUi(this);
    ui->contentStack->hide();

    ui->productPriceEdit->setValidator(new QIntValidator(0, MAX_INT, this));
    ui->productQuantityEdit->setValidator(new QIntValidator(0, MAX_INT, this));
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_productBtn_clicked()
{
    if(ui->contentStack->currentWidget() != ui->productPage) {
        ui->contentStack->setCurrentWidget(ui->productPage);
        ui->contentStack->hide();
	}
    if (!ui->contentStack->isVisible()) {
        ui->contentStack->show();
    }
    else {
        ui->contentStack->hide();
    }
    
}

void MainMenu::on_viewProductBtn_clicked()
{
    ui->contentStack->setCurrentWidget(ui->viewProductPage);
}

void MainMenu::on_prevPageBtn_clicked()
{

}

void MainMenu::on_nextPageBtn_clicked()
{

}

void MainMenu::on_addProductBtn_clicked()
{
    ui->contentStack->setCurrentWidget(ui->addProductPage);
}

void MainMenu::on_confirmAddProductBtn_clicked()
{
    QString productName = ui->productNameEdit->text().trimmed();
    QString productPrice = ui->productPriceEdit->text();
    QString productQuantity = ui->productQuantityEdit->text();

    if (productName.isEmpty() || productPrice.isEmpty() || productQuantity.isEmpty()) {
        QMessageBox::warning(this, "오류", "모든 항목을 입력하세요");
        return;
    }

    QString msg = "addproduct:" + productName + ":" + productPrice + ":" + productQuantity;
    socket->write(msg.toUtf8());
    socket->flush();

    if (socket->waitForReadyRead(3000)) {
        QString response = QString::fromUtf8(socket->readAll()).trimmed();
        if (response == "success") {
            QMessageBox::information(this, "성공", "상품이 추가되었습니다.");
            ui->contentStack->hide();
        }
        else {
            QMessageBox::warning(this, "오류", "오류 : " + response);
        }
    }
}

void MainMenu::on_friendBtn_clicked()
{
    ui->contentStack->hide();
}

void MainMenu::on_profileBtn_clicked()
{
    if (ui->contentStack->currentWidget() != ui->profilePage) {
        ui->contentStack->setCurrentWidget(ui->profilePage);
        ui->contentStack->hide();
    }
    if (!ui->contentStack->isVisible()) {
        ui->contentStack->show();
    }
    else {
        ui->contentStack->hide();
    }
}

void MainMenu::on_changeIdBtn_clicked()
{
	ui->contentStack->setCurrentWidget(ui->changeIdPage);
}

void MainMenu::on_confirmChangeIdBtn_clicked()
{
    QString newId = ui->newIdEdit->text().trimmed();

    if (newId.isEmpty()) {
        QMessageBox::warning(this, "오류", "모든 항목을 입력하세요");
        return;
    }

    QString msg = "changeId:" + newId;
    socket->write(msg.toUtf8());
    socket->flush();

    if (socket->waitForReadyRead(3000)) {
        QString response = QString::fromUtf8(socket->readAll()).trimmed();
        if (response == "success") {
            QMessageBox::information(this, "성공", "아이디가 변경되었습니다.");
            ui->contentStack->hide();
        }
        else {
            QMessageBox::warning(this, "오류", "오류 : " + response);
        }
    }
}

void MainMenu::on_changePwBtn_clicked()
{
	ui->contentStack->setCurrentWidget(ui->changePwPage);
}

void MainMenu::on_confirmChangePwBtn_clicked()
{
    QString newPw = ui->newPwEdit->text().trimmed();

    if (newPw.isEmpty()) {
        QMessageBox::warning(this, "오류", "모든 항목을 입력하세요");
        return;
    }

    QString msg = "changePw:" + newPw;
    socket->write(msg.toUtf8());
    socket->flush();

    if (socket->waitForReadyRead(3000)) {
        QString response = QString::fromUtf8(socket->readAll()).trimmed();
        if (response == "success") {
            QMessageBox::information(this, "성공", "비밀번호가 변경되었습니다.");
            ui->contentStack->hide();
        }
        else {
            QMessageBox::warning(this, "오류", "오류 : " + response);
        }
    }
}

void MainMenu::on_assetBtn_clicked()
{
	ui->contentStack->setCurrentWidget(ui->assetPage);
}

void MainMenu::on_logoutBtn_clicked()
{
    Login* loginWindow = new Login(nullptr, socket);
    loginWindow->setAttribute(Qt::WA_DeleteOnClose);
    loginWindow->show();
    this->close();
}

void MainMenu::on_deleteAccountBtn_clicked()
{
    ui->contentStack->hide();
    QString msg = "deleteaccount";
    socket->write(msg.toUtf8());
    socket->flush();

    if (socket->waitForReadyRead(3000)) {
        QString response = QString::fromUtf8(socket->readAll()).trimmed();
        if (response == "success") {
            QMessageBox::information(this, "성공", "계정을 삭제하였습니다.");
            Login* loginWindow = new Login(nullptr, socket);
            loginWindow->setAttribute(Qt::WA_DeleteOnClose);
            loginWindow->setWindowTitle("로그인 - " + ip + ":" + QString::number(port));
            loginWindow->show();
            this->close();
        }
        else {
            QMessageBox::warning(this, "오류", "오류 : " + response);
        }
    }
}

void MainMenu::on_exitBtn_clicked()
{
    socket->disconnectFromHost();
    if (socket->state() != QAbstractSocket::UnconnectedState) {
        socket->waitForDisconnected(3000);
    }
    this->close();
}

void MainMenu::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);

    int fontSize = width() / 40;

    QFont font = ui->titleLabel->font();
    font.setPointSize(fontSize);
    ui->titleLabel->setFont(font);
    ui->productBtn->setFont(font);
    ui->viewProductBtn->setFont(font);
	ui->nextPageBtn->setFont(font);
	ui->pageLabel->setFont(font);
	ui->prevPageBtn->setFont(font);
    ui->addProductBtn->setFont(font);
	ui->productNameEdit->setFont(font);
	ui->productPriceEdit->setFont(font);
	ui->productQuantityEdit->setFont(font);
	ui->confirmAddProductBtn->setFont(font);
    ui->friendBtn->setFont(font);
    ui->profileBtn->setFont(font);
    ui->changeIdBtn->setFont(font);
	ui->newIdEdit->setFont(font);
	ui->confirmChangeIdBtn->setFont(font);
    ui->changePwBtn->setFont(font);
    ui->newPwEdit->setFont(font);
    ui->confirmChangePwBtn->setFont(font);
    ui->assetBtn->setFont(font);
	ui->assetLabel->setFont(font);
    ui->logoutBtn->setFont(font);
    ui->deleteAccountBtn->setFont(font);
    ui->exitBtn->setFont(font);
}