/********************************************************************************
** Form generated from reading UI file 'signup.ui'
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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Signup
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_id;
    QLineEdit *idEdit;
    QLabel *label_password;
    QLineEdit *pwEdit;
    QLabel *label_confirm;
    QLineEdit *confirmEdit;
    QLabel *statusLabel;
    QPushButton *signupBtn;
    QPushButton *exitBtn;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Signup)
    {
        if (Signup->objectName().isEmpty())
            Signup->setObjectName("Signup");
        Signup->resize(400, 320);
        centralwidget = new QWidget(Signup);
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

        label_confirm = new QLabel(centralwidget);
        label_confirm->setObjectName("label_confirm");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_confirm);

        confirmEdit = new QLineEdit(centralwidget);
        confirmEdit->setObjectName("confirmEdit");
        confirmEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, confirmEdit);


        verticalLayout->addLayout(formLayout);

        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName("statusLabel");

        verticalLayout->addWidget(statusLabel);

        signupBtn = new QPushButton(centralwidget);
        signupBtn->setObjectName("signupBtn");

        verticalLayout->addWidget(signupBtn);

        exitBtn = new QPushButton(centralwidget);
        exitBtn->setObjectName("exitBtn");

        verticalLayout->addWidget(exitBtn);

        Signup->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Signup);
        statusbar->setObjectName("statusbar");
        Signup->setStatusBar(statusbar);

        retranslateUi(Signup);

        QMetaObject::connectSlotsByName(Signup);
    } // setupUi

    void retranslateUi(QMainWindow *Signup)
    {
        Signup->setWindowTitle(QCoreApplication::translate("Signup", "\355\232\214\354\233\220\352\260\200\354\236\205", nullptr));
        label_id->setText(QCoreApplication::translate("Signup", "ID", nullptr));
        label_password->setText(QCoreApplication::translate("Signup", "\353\271\204\353\260\200\353\262\210\355\230\270", nullptr));
        label_confirm->setText(QCoreApplication::translate("Signup", "\353\271\204\353\260\200\353\262\210\355\230\270 \355\231\225\354\235\270", nullptr));
        statusLabel->setText(QString());
        statusLabel->setStyleSheet(QCoreApplication::translate("Signup", "color: red;", nullptr));
        signupBtn->setText(QCoreApplication::translate("Signup", "\355\232\214\354\233\220\352\260\200\354\236\205", nullptr));
        exitBtn->setText(QCoreApplication::translate("Signup", "\354\242\205\353\243\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Signup: public Ui_Signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
