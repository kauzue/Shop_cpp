/********************************************************************************
** Form generated from reading UI file 'Client.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_ip;
    QLineEdit *ipEdit;
    QLabel *label_port;
    QLineEdit *portEdit;
    QLabel *statusLabel;
    QPushButton *connectBtn;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *exitBtn;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName("Client");
        Client->resize(640, 480);
        centralWidget = new QWidget(Client);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName("formLayout");
        label_ip = new QLabel(centralWidget);
        label_ip->setObjectName("label_ip");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_ip);

        ipEdit = new QLineEdit(centralWidget);
        ipEdit->setObjectName("ipEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, ipEdit);

        label_port = new QLabel(centralWidget);
        label_port->setObjectName("label_port");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_port);

        portEdit = new QLineEdit(centralWidget);
        portEdit->setObjectName("portEdit");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, portEdit);


        verticalLayout->addLayout(formLayout);

        statusLabel = new QLabel(centralWidget);
        statusLabel->setObjectName("statusLabel");

        verticalLayout->addWidget(statusLabel);

        connectBtn = new QPushButton(centralWidget);
        connectBtn->setObjectName("connectBtn");

        verticalLayout->addWidget(connectBtn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        exitBtn = new QPushButton(centralWidget);
        exitBtn->setObjectName("exitBtn");

        horizontalLayout->addWidget(exitBtn);


        verticalLayout->addLayout(horizontalLayout);

        Client->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Client);
        statusBar->setObjectName("statusBar");
        Client->setStatusBar(statusBar);

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QMainWindow *Client)
    {
        Client->setWindowTitle(QCoreApplication::translate("Client", "Client", nullptr));
        label_ip->setText(QCoreApplication::translate("Client", "\354\204\234\353\262\204 IP", nullptr));
        label_ip->setStyleSheet(QCoreApplication::translate("Client", "font-size: 18px;", nullptr));
        ipEdit->setStyleSheet(QCoreApplication::translate("Client", "font-size: 18px;", nullptr));
        label_port->setText(QCoreApplication::translate("Client", "\355\217\254\355\212\270 \353\262\210\355\230\270", nullptr));
        label_port->setStyleSheet(QCoreApplication::translate("Client", "font-size: 18px;", nullptr));
        portEdit->setStyleSheet(QCoreApplication::translate("Client", "font-size: 18px;", nullptr));
        statusLabel->setText(QString());
        statusLabel->setStyleSheet(QCoreApplication::translate("Client", "color: red; font-size: 16px;", nullptr));
        connectBtn->setText(QCoreApplication::translate("Client", "\354\204\234\353\262\204 \354\240\221\354\206\215", nullptr));
        connectBtn->setStyleSheet(QCoreApplication::translate("Client", "font-size: 18px; padding: 6px;", nullptr));
        exitBtn->setText(QCoreApplication::translate("Client", "\354\242\205\353\243\214", nullptr));
        exitBtn->setStyleSheet(QCoreApplication::translate("Client", "font-size: 16px; padding: 8px 16px;", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
