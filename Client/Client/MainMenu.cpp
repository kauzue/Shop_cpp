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
    currentPage = 0;
    updateList();
}

void MainMenu::updateList()
{
    QString msg = "productlist:" + QString::number(currentPage);
    socket->write(msg.toUtf8());
    socket->flush();

    if (socket->waitForReadyRead(3000)) {
        QString allData = QString::fromUtf8(socket->readAll()).trimmed();
        QStringList lines = allData.split("\n");

        if (lines.isEmpty()) {
            return;
        }

        QString totalPage = lines[0];
        if (totalPage == "-1") {
            QMessageBox::warning(this, "오류", "현재 판매중인 상품이 없습니다.");
            ui->contentStack->hide();
            return;
        }
        else if (currentPage > totalPage.toInt()) {
            QMessageBox::warning(this, "오류", "현재가 마지막 페이지입니다.");
            return;
        }
        ui->pageLabel->setText(QString("페이지 " + QString::number(currentPage) + " / " + totalPage));

        while (QLayoutItem* child = ui->productListLayout->takeAt(0)) {
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
            if (fields.size() != 4) continue;

            QString productName = fields[0];
            QString productPrice = fields[1];
            QString productQuantity = fields[2];
            QString productUser = fields[3];

            QHBoxLayout* row = new QHBoxLayout;

            QString text = "이름 : " + productName + " / 개수 : " + productPrice + " / 수량 : " + productQuantity + " / 판매자 : " + productUser;

            QPushButton* productBuyBtn = new QPushButton(text);
            productBuyBtn->setToolTip(text);

            row->addWidget(productBuyBtn);
            ui->productListLayout->addLayout(row);
        }
    }
}

void MainMenu::on_prevPageBtn_clicked()
{
    if (currentPage > 0) {
        currentPage--;
        updateList();
    }
    else {
        QMessageBox::warning(this, "오류", "첫 페이지입니다.");
    }
}

void MainMenu::on_nextPageBtn_clicked()
{
    currentPage++;
    updateList();
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
    QString msg = "asset";
    socket->write(msg.toUtf8());
    socket->flush();

    if (socket->waitForReadyRead(3000)) {
        QString response = QString::fromUtf8(socket->readAll()).trimmed();
        ui->assetLabel->setText("보유 자산 : " + response);
    }
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
            loginWindow->setWindowTitle("로그인");
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

    for (int i = 0; i < ui->productListLayout->count(); ++i) {
        QLayoutItem* item = ui->productListLayout->itemAt(i);
        QHBoxLayout* rowLayout = qobject_cast<QHBoxLayout*>(item->layout());
        if (!rowLayout) continue;

        for (int j = 0; j < rowLayout->count(); ++j) {
            QPushButton* btn = qobject_cast<QPushButton*>(rowLayout->itemAt(j)->widget());
            if (!btn) continue;

            btn->setFont(font);

            QString fullText = btn->toolTip();
            QFontMetrics fm(font);
            int maxTextWidth = btn->width() - 20;

            QString elided = fm.elidedText(fullText, Qt::ElideRight, maxTextWidth);
            btn->setText(elided);
        }
    }
}