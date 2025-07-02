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

AdminMenu::~AdminMenu()
{
    delete ui;
}


void AdminMenu::on_manageUserBtn_clicked()
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

void AdminMenu::on_viewUserListBtn_clicked()
{
    ui->contentStack->setCurrentWidget(ui->userListPage);
    currentPage = 0;
    updateList();
}

void AdminMenu::updateList()
{
    QString msg = "userlist:" + QString::number(currentPage);
    socket->write(msg.toUtf8());
    socket->flush();

    if (socket->waitForReadyRead(3000)) {
        QString allData = QString::fromUtf8(socket->readAll()).trimmed();
        QStringList lines = allData.split("\n");

        if (lines.isEmpty())
            return;

        QString totalPage = lines[0];
        if (currentPage > totalPage.toInt()) {
            QMessageBox::warning(this, "오류", "현재가 마지막 페이지입니다.");
            return;
        }
        ui->userPageLabel->setText(QString("페이지 " + QString::number(currentPage) + " / " + totalPage));

        while (QLayoutItem* child = ui->userListContainer->takeAt(0)) {
            if (child->layout()) {
                QLayout* innerLayout = child->layout();
                QLayoutItem* innerChild;
                while ((innerChild = innerLayout->takeAt(0)) != nullptr) {
                    if (innerChild->widget())
                        delete innerChild->widget();
                    delete innerChild;
                }
            }
            else if (child->widget()) {
                delete child->widget();
            }
        }

        for (int i = 1; i < lines.size(); ++i) {
            QString line = lines[i].trimmed();
            if (line.isEmpty()) continue;

            QStringList fields = line.split(",");
            if (fields.size() != 3) continue;

            QString userId = fields[0];
            QString userPw = fields[1];
            QString userAsset = fields[2];

            QHBoxLayout* row = new QHBoxLayout;

            QLabel* idLabel = new QLabel("ID: " + userId);
            QLabel* assetLabel = new QLabel("자산: " + userAsset);

            row->addWidget(idLabel);
            row->addWidget(assetLabel);

            ui->userListContainer->addLayout(row);
        }
    }
    resizeEvent(nullptr);
}

void AdminMenu::on_prevUserPageBtn_clicked()
{
    if (currentPage > 0) {
        currentPage--;
        updateList();
    }
    else {
        QMessageBox::warning(this, "오류", "첫 페이지입니다.");
    }
}

void AdminMenu::on_nextUserPageBtn_clicked()
{
	currentPage++;
    updateList();
}

void AdminMenu::on_modifyUserBtn_clicked()
{
    ui->contentStack->setCurrentWidget(ui->changeUserPage);
}

void AdminMenu::on_confirmUserChangeBtn_clicked()
{
    QString Id = ui->userId->text().trimmed();
    QString newId = ui->userIdEdit->text().trimmed();
    QString newPw = ui->userPwEdit->text().trimmed();
    QString newAsset = ui->userAssetEdit->text().trimmed();

    if (Id.isEmpty() || newId.isEmpty() || newPw.isEmpty() || newAsset.isEmpty()) {
        QMessageBox::warning(this, "오류", "모든 항목을 입력하세요");
        return;
    }

    QString msg = "userchange:" + Id + ":" + newId + ":" + newPw + ":" + newAsset;
    socket->write(msg.toUtf8());
    socket->flush();

    if (socket->waitForReadyRead(3000)) {
        QString response = QString::fromUtf8(socket->readAll()).trimmed();
        if (response == "success") {
            QMessageBox::information(this, "성공", "유저 정보를 수정하였습니다.");
            ui->contentStack->hide();
        }
        else if (response == "notfound") {
            QMessageBox::warning(this, "오류", "해당 유저를 찾을 수 없습니다.");
        }
        else {
            QMessageBox::warning(this, "오류", "오류 : " + response);
        }
    }
}

void AdminMenu::on_logoutBtn_clicked()
{
    Login* loginWindow = new Login(nullptr, socket);
    loginWindow->setAttribute(Qt::WA_DeleteOnClose);
    loginWindow->show();
    this->close();
}

void AdminMenu::on_exitBtn_clicked()
{
    socket->disconnectFromHost();
    if (socket->state() != QAbstractSocket::UnconnectedState) {
        socket->waitForDisconnected(3000);
    }
    this->close();
}

void AdminMenu::resizeEvent(QResizeEvent* event)
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
	ui->userId->setFont(font);
    ui->userIdEdit->setFont(font);
    ui->userPwEdit->setFont(font);
    ui->userAssetEdit->setFont(font);
    ui->confirmUserChangeBtn->setFont(font);
    ui->logoutBtn->setFont(font);
    ui->exitBtn->setFont(font);

    for (int i = 0; i < ui->userListContainer->count(); ++i) {
        QLayoutItem* item = ui->userListContainer->itemAt(i);
        if (!item) continue;

        QHBoxLayout* rowLayout = qobject_cast<QHBoxLayout*>(item->layout());
        if (!rowLayout) continue;

        for (int j = 0; j < rowLayout->count(); ++j) {
            QWidget* w = rowLayout->itemAt(j)->widget();
            if (w) {
                w->setFont(font);
            }
        }
    }
}