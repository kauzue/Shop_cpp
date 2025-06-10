/********************************************************************************
** Form generated from reading UI file '.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI__H
#define UI__H

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
    QLabel *label_pw;
    QLineEdit *pwEdit;
    QLabel *label_pw_confirm;
    QLineEdit *pwConfirmEdit;
    QLabel *statusLabel;
    QPushButton *registerButton;
    QPushButton *cancelButton;
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

        label_pw = new QLabel(centralwidget);
        label_pw->setObjectName("label_pw");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_pw);

        pwEdit = new QLineEdit(centralwidget);
        pwEdit->setObjectName("pwEdit");
        pwEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, pwEdit);

        label_pw_confirm = new QLabel(centralwidget);
        label_pw_confirm->setObjectName("label_pw_confirm");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_pw_confirm);

        pwConfirmEdit = new QLineEdit(centralwidget);
        pwConfirmEdit->setObjectName("pwConfirmEdit");
        pwConfirmEdit->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, pwConfirmEdit);


        verticalLayout->addLayout(formLayout);

        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName("statusLabel");

        verticalLayout->addWidget(statusLabel);

        registerButton = new QPushButton(centralwidget);
        registerButton->setObjectName("registerButton");

        verticalLayout->addWidget(registerButton);

        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName("cancelButton");

        verticalLayout->addWidget(cancelButton);

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
        label_pw->setText(QCoreApplication::translate("Signup", "\353\271\204\353\260\200\353\262\210\355\230\270", nullptr));
        label_pw_confirm->setText(QCoreApplication::translate("Signup", "\353\271\204\353\260\200\353\262\210\355\230\270 \355\231\225\354\235\270", nullptr));
        statusLabel->setText(QString());
        statusLabel->setStyleSheet(QCoreApplication::translate("Signup", "color: red;", nullptr));
        registerButton->setText(QCoreApplication::translate("Signup", "\355\232\214\354\233\220\352\260\200\354\236\205", nullptr));
        cancelButton->setText(QCoreApplication::translate("Signup", "\354\267\250\354\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Signup: public Ui_Signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI__H
