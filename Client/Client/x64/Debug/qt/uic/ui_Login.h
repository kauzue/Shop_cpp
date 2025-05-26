/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *idEdit;
    QLabel *label_2;
    QLineEdit *pwEdit;
    QLabel *statusLabel;
    QPushButton *loginBtn;
    QPushButton *exitBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(738, 516);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        idEdit = new QLineEdit(widget);
        idEdit->setObjectName("idEdit");

        gridLayout_2->addWidget(idEdit, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        pwEdit = new QLineEdit(widget);
        pwEdit->setObjectName("pwEdit");

        gridLayout_2->addWidget(pwEdit, 1, 1, 1, 1);

        statusLabel = new QLabel(widget);
        statusLabel->setObjectName("statusLabel");

        gridLayout_2->addWidget(statusLabel, 2, 1, 1, 1);

        loginBtn = new QPushButton(widget);
        loginBtn->setObjectName("loginBtn");

        gridLayout_2->addWidget(loginBtn, 3, 1, 1, 1);

        exitBtn = new QPushButton(widget);
        exitBtn->setObjectName("exitBtn");

        gridLayout_2->addWidget(exitBtn, 4, 1, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        Login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Login);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 738, 18));
        Login->setMenuBar(menubar);
        statusbar = new QStatusBar(Login);
        statusbar->setObjectName("statusbar");
        Login->setStatusBar(statusbar);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("Login", "\354\225\204\354\235\264\353\224\224", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "\353\271\204\353\260\200\353\262\210\355\230\270", nullptr));
        statusLabel->setText(QCoreApplication::translate("Login", "TextLabel", nullptr));
        loginBtn->setText(QCoreApplication::translate("Login", "\353\241\234\352\267\270\354\235\270", nullptr));
        exitBtn->setText(QCoreApplication::translate("Login", "\354\242\205\353\243\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
