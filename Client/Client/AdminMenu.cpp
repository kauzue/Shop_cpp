#include <QMessageBox>

#include "AdminMenu.h"
#include "ui_AdminMenu.h"
#include "Login.h"

AdminMenu::AdminMenu(QWidget* parent, QTcpSocket* socket)
    : QMainWindow(parent), ui(new Ui::AdminMenu), socket(socket)
{
    ui->setupUi(this);
    ui->contentStack->hide();
}

Adminmenu::~AdminMenu()
{
    delete ui;
}


void on_manageUserBtn_clicked()
{
    if (ui->contentStack->currentWidget() != ui->userPage) {
        ui->contentStack->setCurrentWidget(ui->userPage);
        ui->contentStack->hide();
    }
    if (!ui->contentStack->isVisible()) {
        ui->contentStack->show();
    }
    else {
        ui->contentStack->hide();
    }
}

void on_viewUserListBtn_clicked()
{
    ui->contentStack->setCurrentWidget(ui->userListPage);
}

void on_prevUserPageBtn_clicked()
{

}

void on_nextUserPageBtn_clicked()
{

}

void on_modifyUserBtn_clicked()
{
    ui->contentStack->setCurrentWidget(ui->changeUserPage);
}

void on_confirmUserChangeBtn_clicked()
{

}

void on_logoutBtn_clicked()
{
    Login* loginWindow = new Login(nullptr, socket);
    loginWindow->setAttribute(Qt::WA_DeleteOnClose);
    loginWindow->show();
    this->close();
}

void on_exitBtn_clickked()
{
    socket->disconnectFromHost();
    if (socket->state() != QAbstractSocket::UnconnectedState) {
        socket->waitForDisconnected(3000);
    }
    this->close();
}

void resizeEvent(QResizeEvent* evnet)
{
    QWidget::resizeEvent(event);

    int fontSize = width() / 40;

    QFont font = ui->titleLabel->font();
    font.setPointSize(fontSize);
    ui->titleLabel->setFont(font);
    ui->manageUserBtn->setFont(font);
    ui->viewUserListBtn->setFont(font);
    ui->userPageLabel->setFont(font);
    ui->prevUserPageBtn->setFont(font);
    ui->nextUserPageBtn->setFont(font);
    ui->modifyUserBtn->setFont(font);
    ui->userIdEdit->setFont(font);
    ui->userPwEdit->setFont(font);
    ui->userAssetEdit->setFont(font);
    ui->confirmUserChangeBtn->setFont(font);
    ui->logoutBtn->setFont(font);
    ui->exitBtn->setFont(font);
}