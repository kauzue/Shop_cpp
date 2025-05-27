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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
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
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_id;
    QLineEdit *idEdit;
    QLabel *label_pw;
    QLineEdit *pwEdit;
    QHBoxLayout *buttonLayout;
    QPushButton *loginBtn;
    QPushButton *exitBtn;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(400, 300);
        centralWidget = new QWidget(Login);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName("formLayout");
        label_id = new QLabel(centralWidget);
        label_id->setObjectName("label_id");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_id);

        idEdit = new QLineEdit(centralWidget);
        idEdit->setObjectName("idEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, idEdit);

        label_pw = new QLabel(centralWidget);
        label_pw->setObjectName("label_pw");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_pw);

        pwEdit = new QLineEdit(centralWidget);
        pwEdit->setObjectName("pwEdit");
        pwEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, pwEdit);


        verticalLayout->addLayout(formLayout);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setSpacing(6);
        buttonLayout->setObjectName("buttonLayout");
        loginBtn = new QPushButton(centralWidget);
        loginBtn->setObjectName("loginBtn");

        buttonLayout->addWidget(loginBtn);

        exitBtn = new QPushButton(centralWidget);
        exitBtn->setObjectName("exitBtn");

        buttonLayout->addWidget(exitBtn);


        verticalLayout->addLayout(buttonLayout);

        Login->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Login);
        statusBar->setObjectName("statusBar");
        Login->setStatusBar(statusBar);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        label_id->setText(QCoreApplication::translate("Login", "\354\225\204\354\235\264\353\224\224", nullptr));
        label_id->setStyleSheet(QCoreApplication::translate("Login", "font-size: 16px;", nullptr));
        idEdit->setStyleSheet(QCoreApplication::translate("Login", "font-size: 16px;", nullptr));
        label_pw->setText(QCoreApplication::translate("Login", "\353\271\204\353\260\200\353\262\210\355\230\270", nullptr));
        label_pw->setStyleSheet(QCoreApplication::translate("Login", "font-size: 16px;", nullptr));
        pwEdit->setStyleSheet(QCoreApplication::translate("Login", "font-size: 16px;", nullptr));
        loginBtn->setText(QCoreApplication::translate("Login", "\353\241\234\352\267\270\354\235\270", nullptr));
        loginBtn->setStyleSheet(QCoreApplication::translate("Login", "font-size: 18px; padding: 8px 16px;", nullptr));
        exitBtn->setText(QCoreApplication::translate("Login", "\354\242\205\353\243\214", nullptr));
        exitBtn->setStyleSheet(QCoreApplication::translate("Login", "font-size: 16px; padding: 6px 12px;", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
