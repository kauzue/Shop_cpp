/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_id;
    QLineEdit *idEdit;
    QLabel *label_password;
    QLineEdit *pwEdit;
    QLabel *statusLabel;
    QPushButton *loginBtn;
    QPushButton *signupBtn;
    QPushButton *exitBtn;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(400, 300);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName("formLayout");
        label_id = new QLabel(centralwidget);
        label_id->setObjectName("label_id");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_id);

        idEdit = new QLineEdit(centralwidget);
        idEdit->setObjectName("idEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, idEdit);

        label_password = new QLabel(centralwidget);
        label_password->setObjectName("label_password");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_password);

        pwEdit = new QLineEdit(centralwidget);
        pwEdit->setObjectName("pwEdit");
        pwEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, pwEdit);


        verticalLayout->addLayout(formLayout);

        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName("statusLabel");

        verticalLayout->addWidget(statusLabel);

        loginBtn = new QPushButton(centralwidget);
        loginBtn->setObjectName("loginBtn");

        verticalLayout->addWidget(loginBtn);

        signupBtn = new QPushButton(centralwidget);
        signupBtn->setObjectName("signupBtn");

        verticalLayout->addWidget(signupBtn);

        exitBtn = new QPushButton(centralwidget);
        exitBtn->setObjectName("exitBtn");

        verticalLayout->addWidget(exitBtn);

        Login->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Login);
        statusbar->setObjectName("statusbar");
        Login->setStatusBar(statusbar);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        label_id->setText(QCoreApplication::translate("Login", "ID", nullptr));
        label_password->setText(QCoreApplication::translate("Login", "\353\271\204\353\260\200\353\262\210\355\230\270", nullptr));
        statusLabel->setText(QString());
        statusLabel->setStyleSheet(QCoreApplication::translate("Login", "color: red;", nullptr));
        loginBtn->setText(QCoreApplication::translate("Login", "\353\241\234\352\267\270\354\235\270", nullptr));
        signupBtn->setText(QCoreApplication::translate("Login", "\355\232\214\354\233\220\352\260\200\354\236\205", nullptr));
        exitBtn->setText(QCoreApplication::translate("Login", "\354\242\205\353\243\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
