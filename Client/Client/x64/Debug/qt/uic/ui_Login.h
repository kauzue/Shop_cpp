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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelNickname;
    QLineEdit *nicknameEdit;
    QLabel *labelPassword;
    QLineEdit *passwordEdit;
    QHBoxLayout *buttonLayout;
    QPushButton *loginBtn;
    QPushButton *signupBtn;
    QPushButton *backBtn;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(500, 300);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldGrowthPolicy::ExpandingFieldsGrow);
        labelNickname = new QLabel(centralwidget);
        labelNickname->setObjectName("labelNickname");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelNickname->sizePolicy().hasHeightForWidth());
        labelNickname->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelNickname);

        nicknameEdit = new QLineEdit(centralwidget);
        nicknameEdit->setObjectName("nicknameEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(nicknameEdit->sizePolicy().hasHeightForWidth());
        nicknameEdit->setSizePolicy(sizePolicy1);

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, nicknameEdit);

        labelPassword = new QLabel(centralwidget);
        labelPassword->setObjectName("labelPassword");
        sizePolicy.setHeightForWidth(labelPassword->sizePolicy().hasHeightForWidth());
        labelPassword->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelPassword);

        passwordEdit = new QLineEdit(centralwidget);
        passwordEdit->setObjectName("passwordEdit");
        sizePolicy1.setHeightForWidth(passwordEdit->sizePolicy().hasHeightForWidth());
        passwordEdit->setSizePolicy(sizePolicy1);
        passwordEdit->setEchoMode(QLineEdit::EchoMode::Password);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, passwordEdit);


        verticalLayout->addLayout(formLayout);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        loginBtn = new QPushButton(centralwidget);
        loginBtn->setObjectName("loginBtn");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(loginBtn->sizePolicy().hasHeightForWidth());
        loginBtn->setSizePolicy(sizePolicy2);

        buttonLayout->addWidget(loginBtn);

        signupBtn = new QPushButton(centralwidget);
        signupBtn->setObjectName("signupBtn");
        sizePolicy2.setHeightForWidth(signupBtn->sizePolicy().hasHeightForWidth());
        signupBtn->setSizePolicy(sizePolicy2);

        buttonLayout->addWidget(signupBtn);

        backBtn = new QPushButton(centralwidget);
        backBtn->setObjectName("backBtn");
        sizePolicy2.setHeightForWidth(backBtn->sizePolicy().hasHeightForWidth());
        backBtn->setSizePolicy(sizePolicy2);

        buttonLayout->addWidget(backBtn);


        verticalLayout->addLayout(buttonLayout);

        Login->setCentralWidget(centralwidget);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "\353\241\234\352\267\270\354\235\270", nullptr));
        labelNickname->setText(QCoreApplication::translate("Login", "\353\213\211\353\204\244\354\236\204", nullptr));
        labelPassword->setText(QCoreApplication::translate("Login", "\353\271\204\353\260\200\353\262\210\355\230\270", nullptr));
        loginBtn->setText(QCoreApplication::translate("Login", "\355\231\225\354\235\270", nullptr));
        signupBtn->setText(QCoreApplication::translate("Login", "\355\232\214\354\233\220\352\260\200\354\236\205", nullptr));
        backBtn->setText(QCoreApplication::translate("Login", "\354\235\264\354\240\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
