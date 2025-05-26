/********************************************************************************
** Form generated from reading UI file 'Client.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *ipEdit;
    QLabel *label_2;
    QLineEdit *portEdit;
    QLabel *statusLabel;
    QPushButton *connectBtn;
    QPushButton *exitBtn;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName("Client");
        Client->resize(600, 400);
        centralWidget = new QWidget(Client);
        centralWidget->setObjectName("centralWidget");
        mainLayout = new QVBoxLayout(centralWidget);
        mainLayout->setSpacing(10);
        mainLayout->setContentsMargins(15, 15, 15, 15);
        mainLayout->setObjectName("mainLayout");
        widget = new QWidget(centralWidget);
        widget->setObjectName("widget");
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(10);
        gridLayout_2->setContentsMargins(15, 15, 15, 15);
        gridLayout_2->setObjectName("gridLayout_2");
        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        ipEdit = new QLineEdit(widget);
        ipEdit->setObjectName("ipEdit");
        ipEdit->setStyleSheet(QString::fromUtf8("\n"
"											QLineEdit {\n"
"											border: none;\n"
"											border-radius: 15px;\n"
"											background-color: #eeeeee;\n"
"											padding: 10px;\n"
"											font-size: 14px;\n"
"											}\n"
"										"));

        gridLayout_2->addWidget(ipEdit, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        portEdit = new QLineEdit(widget);
        portEdit->setObjectName("portEdit");
        portEdit->setStyleSheet(QString::fromUtf8("\n"
"											QLineEdit {\n"
"											border: none;\n"
"											border-radius: 15px;\n"
"											background-color: #eeeeee;\n"
"											padding: 10px;\n"
"											font-size: 14px;\n"
"											}\n"
"										"));

        gridLayout_2->addWidget(portEdit, 1, 1, 1, 1);

        statusLabel = new QLabel(widget);
        statusLabel->setObjectName("statusLabel");

        gridLayout_2->addWidget(statusLabel, 2, 1, 1, 1);

        connectBtn = new QPushButton(widget);
        connectBtn->setObjectName("connectBtn");
        connectBtn->setStyleSheet(QString::fromUtf8("\n"
"											QPushButton {\n"
"											background-color: #90caf9;\n"
"											border: none;\n"
"											border-radius: 15px;\n"
"											padding: 10px;\n"
"											font-size: 14px;\n"
"											}\n"
"											QPushButton:hover {\n"
"											background-color: #64b5f6;\n"
"											}\n"
"										"));

        gridLayout_2->addWidget(connectBtn, 3, 1, 1, 1);

        exitBtn = new QPushButton(widget);
        exitBtn->setObjectName("exitBtn");
        exitBtn->setStyleSheet(QString::fromUtf8("\n"
"											QPushButton {\n"
"											background-color: #ef9a9a;\n"
"											border: none;\n"
"											border-radius: 15px;\n"
"											padding: 10px;\n"
"											font-size: 14px;\n"
"											}\n"
"											QPushButton:hover {\n"
"											background-color: #e57373;\n"
"											}\n"
"										"));

        gridLayout_2->addWidget(exitBtn, 4, 1, 1, 1);


        mainLayout->addWidget(widget);

        Client->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(Client);
        mainToolBar->setObjectName("mainToolBar");
        Client->addToolBar(mainToolBar);
        statusBar = new QStatusBar(Client);
        statusBar->setObjectName("statusBar");
        Client->setStatusBar(statusBar);

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QMainWindow *Client)
    {
        Client->setWindowTitle(QCoreApplication::translate("Client", "Client", nullptr));
        label->setText(QCoreApplication::translate("Client", "\354\204\234\353\262\204 IP", nullptr));
        label_2->setText(QCoreApplication::translate("Client", "\355\217\254\355\212\270 \353\262\210\355\230\270", nullptr));
        statusLabel->setText(QCoreApplication::translate("Client", "\354\227\260\352\262\260 \354\203\201\355\203\234: \354\227\206\354\235\214", nullptr));
        connectBtn->setText(QCoreApplication::translate("Client", "\354\204\234\353\262\204 \354\240\221\354\206\215", nullptr));
        exitBtn->setText(QCoreApplication::translate("Client", "\354\242\205\353\243\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
