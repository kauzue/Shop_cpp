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
    QLabel *labelIP;
    QLineEdit *ipEdit;
    QLabel *labelPort;
    QLineEdit *portEdit;
    QLabel *errorLabel;
    QHBoxLayout *buttonLayout;
    QPushButton *connectBtn;
    QPushButton *exitBtn;

    void setupUi(QMainWindow *ServerConnect)
    {
        if (ServerConnect->objectName().isEmpty())
            ServerConnect->setObjectName("ServerConnect");
        ServerConnect->resize(360, 180);
        actionConnect = new QAction(ServerConnect);
        actionConnect->setObjectName("actionConnect");
        centralwidget = new QWidget(ServerConnect);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        labelIP = new QLabel(centralwidget);
        labelIP->setObjectName("labelIP");

        gridLayout->addWidget(labelIP, 0, 0, 1, 1);

        ipEdit = new QLineEdit(centralwidget);
        ipEdit->setObjectName("ipEdit");

        gridLayout->addWidget(ipEdit, 0, 1, 1, 1);

        labelPort = new QLabel(centralwidget);
        labelPort->setObjectName("labelPort");

        gridLayout->addWidget(labelPort, 1, 0, 1, 1);

        portEdit = new QLineEdit(centralwidget);
        portEdit->setObjectName("portEdit");

        gridLayout->addWidget(portEdit, 1, 1, 1, 1);

        errorLabel = new QLabel(centralwidget);
        errorLabel->setObjectName("errorLabel");
        errorLabel->setVisible(false);
        errorLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(errorLabel, 2, 0, 1, 2);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        connectBtn = new QPushButton(centralwidget);
        connectBtn->setObjectName("connectBtn");

        buttonLayout->addWidget(connectBtn);

        exitBtn = new QPushButton(centralwidget);
        exitBtn->setObjectName("exitBtn");

        buttonLayout->addWidget(exitBtn);


        gridLayout->addLayout(buttonLayout, 3, 0, 1, 2, Qt::AlignCenter);

        ServerConnect->setCentralWidget(centralwidget);

        retranslateUi(ServerConnect);

        QMetaObject::connectSlotsByName(ServerConnect);
    } // setupUi

    void retranslateUi(QMainWindow *ServerConnect)
    {
        ServerConnect->setWindowTitle(QCoreApplication::translate("ServerConnect", "\354\204\234\353\262\204 \354\227\260\352\262\260", nullptr));
        labelIP->setText(QCoreApplication::translate("ServerConnect", "\354\204\234\353\262\204 IP:", nullptr));
        labelPort->setText(QCoreApplication::translate("ServerConnect", "\354\204\234\353\262\204 \355\217\254\355\212\270:", nullptr));
        errorLabel->setText(QString());
        errorLabel->setStyleSheet(QCoreApplication::translate("ServerConnect", "color: red;", nullptr));
        connectBtn->setText(QCoreApplication::translate("ServerConnect", "\355\231\225\354\235\270", nullptr));
        exitBtn->setText(QCoreApplication::translate("ServerConnect", "\354\242\205\353\243\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerConnect: public Ui_ServerConnect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERCONNECT_H
