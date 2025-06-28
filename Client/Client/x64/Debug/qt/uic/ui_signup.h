/********************************************************************************
** Form generated from reading UI file 'Signup.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

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

class Ui_Signup
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelNickname;
    QLineEdit *nicknameEdit;
    QLabel *labelPassword;
    QLineEdit *passwordEdit;
    QLabel *labelConfirm;
    QLineEdit *confirmEdit;
    QHBoxLayout *buttonLayout;
    QPushButton *signupBtn;
    QPushButton *backBtn;

    void setupUi(QMainWindow *Signup)
    {
        if (Signup->objectName().isEmpty())
            Signup->setObjectName("Signup");
        Signup->resize(500, 300);
        centralwidget = new QWidget(Signup);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelNickname = new QLabel(centralwidget);
        labelNickname->setObjectName("labelNickname");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
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

        labelConfirm = new QLabel(centralwidget);
        labelConfirm->setObjectName("labelConfirm");
        sizePolicy.setHeightForWidth(labelConfirm->sizePolicy().hasHeightForWidth());
        labelConfirm->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelConfirm);

        confirmEdit = new QLineEdit(centralwidget);
        confirmEdit->setObjectName("confirmEdit");
        sizePolicy1.setHeightForWidth(confirmEdit->sizePolicy().hasHeightForWidth());
        confirmEdit->setSizePolicy(sizePolicy1);
        confirmEdit->setEchoMode(QLineEdit::EchoMode::Password);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, confirmEdit);


        verticalLayout->addLayout(formLayout);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        signupBtn = new QPushButton(centralwidget);
        signupBtn->setObjectName("signupBtn");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(signupBtn->sizePolicy().hasHeightForWidth());
        signupBtn->setSizePolicy(sizePolicy2);

        buttonLayout->addWidget(signupBtn);

        backBtn = new QPushButton(centralwidget);
        backBtn->setObjectName("backBtn");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Ignored);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(backBtn->sizePolicy().hasHeightForWidth());
        backBtn->setSizePolicy(sizePolicy3);

        buttonLayout->addWidget(backBtn);


        verticalLayout->addLayout(buttonLayout);

        Signup->setCentralWidget(centralwidget);

        retranslateUi(Signup);

        QMetaObject::connectSlotsByName(Signup);
    } // setupUi

    void retranslateUi(QMainWindow *Signup)
    {
        Signup->setWindowTitle(QCoreApplication::translate("Signup", "\355\232\214\354\233\220\352\260\200\354\236\205", nullptr));
        labelNickname->setText(QCoreApplication::translate("Signup", "\353\213\211\353\204\244\354\236\204", nullptr));
        labelPassword->setText(QCoreApplication::translate("Signup", "\353\271\204\353\260\200\353\262\210\355\230\270", nullptr));
        labelConfirm->setText(QCoreApplication::translate("Signup", "\353\271\204\353\260\200\353\262\210\355\230\270 \355\231\225\354\235\270", nullptr));
        signupBtn->setText(QCoreApplication::translate("Signup", "\355\231\225\354\235\270", nullptr));
        backBtn->setText(QCoreApplication::translate("Signup", "\354\235\264\354\240\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Signup: public Ui_Signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
