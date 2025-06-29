#include "MainMenu.h"
#include "ui_MainMenu.h"
#include "Signup.h"

MainMenu::MainMenu(QWidget* parent, QTcpSocket* socket)
    : QMainWindow(parent), ui(new Ui::MainMenu), socket(socket)
{
    ui->setupUi(this);
    ui->contentStack->hide();
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_productBtn_clicked()
{
    if(ui->contentStack->currentWidget() != ui->productPage) {
        ui->contentStack->setCurrentWidget(ui->productPage);
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
    ui->contentStack->hide();
}

void MainMenu::on_addProductBtn_clicked()
{
	ui->contentStack->hide();
}

void MainMenu::on_friendBtn_clicked()
{
    ui->contentStack->hide();
}

void MainMenu::on_profileBtn_clicked()
{
    if (ui->contentStack->currentWidget() != ui->profilePage) {
        ui->contentStack->setCurrentWidget(ui->profilePage);
    }
    if (!ui->contentStack->isVisible()) {
        ui->contentStack->show();
    }
    else {
        ui->contentStack->hide();
    }
}

void MainMenu::on_changeIDBtn_clicked()
{
	ui->contentStack->hide();
}

void MainMenu::on_changePWBtn_clicked()
{
	ui->contentStack->hide();
}

void MainMenu::on_assetBtn_clicked()
{
	ui->contentStack->hide();
}

void MainMenu::on_logoutBtn_clicked()
{
    Signup* signupWindow = new Signup(nullptr, socket);
    signupWindow->setAttribute(Qt::WA_DeleteOnClose);
    signupWindow->show();
    this->close();
}

void MainMenu::on_deleteAccountBtn_clicked()
{
    ui->contentStack->hide();
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
    ui->addProductBtn->setFont(font);
    ui->friendBtn->setFont(font);
    ui->profileBtn->setFont(font);
    ui->changeIdBtn->setFont(font);
    ui->changePwBtn->setFont(font);
    ui->assetBtn->setFont(font);
    ui->logoutBtn->setFont(font);
    ui->deleteAccountBtn->setFont(font);
    ui->exitBtn->setFont(font);
}