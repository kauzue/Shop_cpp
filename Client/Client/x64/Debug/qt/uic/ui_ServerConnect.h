/********************************************************************************
** Form generated from reading UI file 'ServerConnect.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERCONNECT_H
#define UI_SERVERCONNECT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerConnect
{
public:
    QAction *actionConnect;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *errorLabel;
    QHBoxLayout *buttonLayout;
    QPushButton *connectBtn;
    QPushButton *exitBtn;
    QFormLayout *formLayout_2;
    QLabel *labelIP;
    QLabel *labelPort;
    QLineEdit *ipEdit;
    QLineEdit *portEdit;

    void setupUi(QMainWindow *ServerConnect)
    {
        if (ServerConnect->objectName().isEmpty())
            ServerConnect->setObjectName("ServerConnect");
        ServerConnect->resize(500, 300);
        actionConnect = new QAction(ServerConnect);
        actionConnect->setObjectName("actionConnect");
        centralwidget = new QWidget(ServerConnect);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        errorLabel = new QLabel(centralwidget);
        errorLabel->setObjectName("errorLabel");
        errorLabel->setVisible(false);
        errorLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(errorLabel, 3, 0, 1, 2);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        connectBtn = new QPushButton(centralwidget);
        connectBtn->setObjectName("connectBtn");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(connectBtn->sizePolicy().hasHeightForWidth());
        connectBtn->setSizePolicy(sizePolicy);

        buttonLayout->addWidget(connectBtn);

        exitBtn = new QPushButton(centralwidget);
        exitBtn->setObjectName("exitBtn");
        sizePolicy.setHeightForWidth(exitBtn->sizePolicy().hasHeightForWidth());
        exitBtn->setSizePolicy(sizePolicy);

        buttonLayout->addWidget(exitBtn);


        gridLayout->addLayout(buttonLayout, 4, 0, 1, 2);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        labelIP = new QLabel(centralwidget);
        labelIP->setObjectName("labelIP");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelIP->sizePolicy().hasHeightForWidth());
        labelIP->setSizePolicy(sizePolicy1);

        formLayout_2->setWidget(0, QFormLayout::ItemRole::LabelRole, labelIP);

        labelPort = new QLabel(centralwidget);
        labelPort->setObjectName("labelPort");
        sizePolicy1.setHeightForWidth(labelPort->sizePolicy().hasHeightForWidth());
        labelPort->setSizePolicy(sizePolicy1);

        formLayout_2->setWidget(1, QFormLayout::ItemRole::LabelRole, labelPort);

        ipEdit = new QLineEdit(centralwidget);
        ipEdit->setObjectName("ipEdit");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ipEdit->sizePolicy().hasHeightForWidth());
        ipEdit->setSizePolicy(sizePolicy2);

        formLayout_2->setWidget(0, QFormLayout::ItemRole::FieldRole, ipEdit);

        portEdit = new QLineEdit(centralwidget);
        portEdit->setObjectName("portEdit");
        sizePolicy2.setHeightForWidth(portEdit->sizePolicy().hasHeightForWidth());
        portEdit->setSizePolicy(sizePolicy2);

        formLayout_2->setWidget(1, QFormLayout::ItemRole::FieldRole, portEdit);


        gridLayout->addLayout(formLayout_2, 0, 0, 1, 2);

        ServerConnect->setCentralWidget(centralwidget);

        retranslateUi(ServerConnect);

        QMetaObject::connectSlotsByName(ServerConnect);
    } // setupUi

    void retranslateUi(QMainWindow *ServerConnect)
    {
        ServerConnect->setWindowTitle(QCoreApplication::translate("ServerConnect", "\354\204\234\353\262\204 \354\227\260\352\262\260", nullptr));
        errorLabel->setStyleSheet(QCoreApplication::translate("ServerConnect", "color: red;", nullptr));
        errorLabel->setText(QString());
        connectBtn->setText(QCoreApplication::translate("ServerConnect", "\355\231\225\354\235\270", nullptr));
        exitBtn->setText(QCoreApplication::translate("ServerConnect", "\354\242\205\353\243\214", nullptr));
        labelIP->setText(QCoreApplication::translate("ServerConnect", "\354\204\234\353\262\204 IP", nullptr));
        labelPort->setText(QCoreApplication::translate("ServerConnect", "\354\204\234\353\262\204 \355\217\254\355\212\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerConnect: public Ui_ServerConnect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERCONNECT_H
