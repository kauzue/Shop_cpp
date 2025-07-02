/********************************************************************************
** Form generated from reading UI file 'AdminMenu.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINMENU_H
#define UI_ADMINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminMenu
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QHBoxLayout *mainLayout;
    QVBoxLayout *leftMenuLayout;
    QPushButton *manageUserBtn;
    QPushButton *logoutBtn;
    QPushButton *exitBtn;
    QStackedWidget *contentStack;
    QWidget *userPage;
    QVBoxLayout *userPageLayout;
    QPushButton *viewUserListBtn;
    QPushButton *modifyUserBtn;
    QWidget *userListPage;
    QVBoxLayout *userListLayout;
    QVBoxLayout *userListContainer;
    QHBoxLayout *pageControlLayout;
    QPushButton *prevUserPageBtn;
    QLabel *userPageLabel;
    QPushButton *nextUserPageBtn;
    QWidget *changeUserPage;
    QVBoxLayout *changeUserLayout;
    QLineEdit *userId;
    QLineEdit *userIdEdit;
    QLineEdit *userPwEdit;
    QLineEdit *userAssetEdit;
    QPushButton *confirmUserChangeBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminMenu)
    {
        if (AdminMenu->objectName().isEmpty())
            AdminMenu->setObjectName("AdminMenu");
        AdminMenu->resize(1000, 600);
        centralwidget = new QWidget(AdminMenu);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        mainLayout = new QHBoxLayout();
        mainLayout->setObjectName("mainLayout");
        leftMenuLayout = new QVBoxLayout();
        leftMenuLayout->setObjectName("leftMenuLayout");
        manageUserBtn = new QPushButton(centralwidget);
        manageUserBtn->setObjectName("manageUserBtn");

        leftMenuLayout->addWidget(manageUserBtn);

        logoutBtn = new QPushButton(centralwidget);
        logoutBtn->setObjectName("logoutBtn");

        leftMenuLayout->addWidget(logoutBtn);

        exitBtn = new QPushButton(centralwidget);
        exitBtn->setObjectName("exitBtn");

        leftMenuLayout->addWidget(exitBtn);


        mainLayout->addLayout(leftMenuLayout);

        contentStack = new QStackedWidget(centralwidget);
        contentStack->setObjectName("contentStack");
        userPage = new QWidget();
        userPage->setObjectName("userPage");
        userPageLayout = new QVBoxLayout(userPage);
        userPageLayout->setObjectName("userPageLayout");
        viewUserListBtn = new QPushButton(userPage);
        viewUserListBtn->setObjectName("viewUserListBtn");

        userPageLayout->addWidget(viewUserListBtn);

        modifyUserBtn = new QPushButton(userPage);
        modifyUserBtn->setObjectName("modifyUserBtn");

        userPageLayout->addWidget(modifyUserBtn);

        contentStack->addWidget(userPage);
        userListPage = new QWidget();
        userListPage->setObjectName("userListPage");
        userListLayout = new QVBoxLayout(userListPage);
        userListLayout->setObjectName("userListLayout");
        userListContainer = new QVBoxLayout();
        userListContainer->setObjectName("userListContainer");

        userListLayout->addLayout(userListContainer);

        pageControlLayout = new QHBoxLayout();
        pageControlLayout->setObjectName("pageControlLayout");
        prevUserPageBtn = new QPushButton(userListPage);
        prevUserPageBtn->setObjectName("prevUserPageBtn");

        pageControlLayout->addWidget(prevUserPageBtn);

        userPageLabel = new QLabel(userListPage);
        userPageLabel->setObjectName("userPageLabel");
        userPageLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        pageControlLayout->addWidget(userPageLabel);

        nextUserPageBtn = new QPushButton(userListPage);
        nextUserPageBtn->setObjectName("nextUserPageBtn");

        pageControlLayout->addWidget(nextUserPageBtn);


        userListLayout->addLayout(pageControlLayout);

        contentStack->addWidget(userListPage);
        changeUserPage = new QWidget();
        changeUserPage->setObjectName("changeUserPage");
        changeUserLayout = new QVBoxLayout(changeUserPage);
        changeUserLayout->setObjectName("changeUserLayout");
        userId = new QLineEdit(changeUserPage);
        userId->setObjectName("userId");

        changeUserLayout->addWidget(userId);

        userIdEdit = new QLineEdit(changeUserPage);
        userIdEdit->setObjectName("userIdEdit");

        changeUserLayout->addWidget(userIdEdit);

        userPwEdit = new QLineEdit(changeUserPage);
        userPwEdit->setObjectName("userPwEdit");
        userPwEdit->setEchoMode(QLineEdit::EchoMode::Password);

        changeUserLayout->addWidget(userPwEdit);

        userAssetEdit = new QLineEdit(changeUserPage);
        userAssetEdit->setObjectName("userAssetEdit");

        changeUserLayout->addWidget(userAssetEdit);

        confirmUserChangeBtn = new QPushButton(changeUserPage);
        confirmUserChangeBtn->setObjectName("confirmUserChangeBtn");

        changeUserLayout->addWidget(confirmUserChangeBtn);

        contentStack->addWidget(changeUserPage);

        mainLayout->addWidget(contentStack);


        verticalLayout->addLayout(mainLayout);

        AdminMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminMenu);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 21));
        AdminMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminMenu);
        statusbar->setObjectName("statusbar");
        AdminMenu->setStatusBar(statusbar);

        retranslateUi(AdminMenu);

        contentStack->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(AdminMenu);
    } // setupUi

    void retranslateUi(QMainWindow *AdminMenu)
    {
        AdminMenu->setWindowTitle(QCoreApplication::translate("AdminMenu", "\352\264\200\353\246\254\354\236\220 \353\251\224\353\211\264", nullptr));
        titleLabel->setText(QCoreApplication::translate("AdminMenu", "\352\264\200\353\246\254\354\236\220 \355\216\230\354\235\264\354\247\200", nullptr));
        manageUserBtn->setText(QCoreApplication::translate("AdminMenu", "\354\202\254\354\232\251\354\236\220 \352\264\200\353\246\254", nullptr));
        logoutBtn->setText(QCoreApplication::translate("AdminMenu", "\353\241\234\352\267\270\354\225\204\354\233\203", nullptr));
        exitBtn->setText(QCoreApplication::translate("AdminMenu", "\354\242\205\353\243\214", nullptr));
        viewUserListBtn->setText(QCoreApplication::translate("AdminMenu", "\354\202\254\354\232\251\354\236\220 \353\252\251\353\241\235", nullptr));
        modifyUserBtn->setText(QCoreApplication::translate("AdminMenu", "\354\202\254\354\232\251\354\236\220 \354\210\230\354\240\225", nullptr));
        prevUserPageBtn->setText(QCoreApplication::translate("AdminMenu", "\354\235\264\354\240\204", nullptr));
        userPageLabel->setText(QCoreApplication::translate("AdminMenu", "\355\216\230\354\235\264\354\247\200 1 / 1", nullptr));
        nextUserPageBtn->setText(QCoreApplication::translate("AdminMenu", "\353\213\244\354\235\214", nullptr));
        userId->setPlaceholderText(QCoreApplication::translate("AdminMenu", "\354\234\240\354\240\200 \354\225\204\354\235\264\353\224\224", nullptr));
        userIdEdit->setPlaceholderText(QCoreApplication::translate("AdminMenu", "\354\210\230\354\240\225\355\225\240 \354\225\204\354\235\264\353\224\224", nullptr));
        userPwEdit->setPlaceholderText(QCoreApplication::translate("AdminMenu", "\354\203\210 \353\271\204\353\260\200\353\262\210\355\230\270", nullptr));
        userAssetEdit->setPlaceholderText(QCoreApplication::translate("AdminMenu", "\353\263\264\354\234\240 \354\236\220\354\202\260", nullptr));
        confirmUserChangeBtn->setText(QCoreApplication::translate("AdminMenu", "\355\231\225\354\235\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminMenu: public Ui_AdminMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINMENU_H
