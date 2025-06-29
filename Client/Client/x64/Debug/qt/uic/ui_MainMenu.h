/********************************************************************************
** Form generated from reading UI file 'MainMenu.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QHBoxLayout *mainLayout;
    QVBoxLayout *leftMenuLayout;
    QPushButton *productBtn;
    QPushButton *friendBtn;
    QPushButton *profileBtn;
    QPushButton *exitBtn;
    QStackedWidget *contentStack;
    QWidget *productPage;
    QVBoxLayout *productLayout;
    QSpacerItem *topSpacer;
    QPushButton *viewProductBtn;
    QPushButton *addProductBtn;
    QSpacerItem *bottomSpacer;
    QWidget *profilePage;
    QVBoxLayout *profileLayout;
    QSpacerItem *topProfileSpacer;
    QPushButton *changeIdBtn;
    QPushButton *changePwBtn;
    QPushButton *assetBtn;
    QPushButton *logoutBtn;
    QPushButton *deleteAccountBtn;
    QSpacerItem *bottomProfileSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName("MainMenu");
        MainMenu->resize(1000, 600);
        centralwidget = new QWidget(MainMenu);
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
        productBtn = new QPushButton(centralwidget);
        productBtn->setObjectName("productBtn");

        leftMenuLayout->addWidget(productBtn);

        friendBtn = new QPushButton(centralwidget);
        friendBtn->setObjectName("friendBtn");

        leftMenuLayout->addWidget(friendBtn);

        profileBtn = new QPushButton(centralwidget);
        profileBtn->setObjectName("profileBtn");

        leftMenuLayout->addWidget(profileBtn);

        exitBtn = new QPushButton(centralwidget);
        exitBtn->setObjectName("exitBtn");

        leftMenuLayout->addWidget(exitBtn);


        mainLayout->addLayout(leftMenuLayout);

        contentStack = new QStackedWidget(centralwidget);
        contentStack->setObjectName("contentStack");
        productPage = new QWidget();
        productPage->setObjectName("productPage");
        productLayout = new QVBoxLayout(productPage);
        productLayout->setObjectName("productLayout");
        topSpacer = new QSpacerItem(20, 100, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        productLayout->addItem(topSpacer);

        viewProductBtn = new QPushButton(productPage);
        viewProductBtn->setObjectName("viewProductBtn");

        productLayout->addWidget(viewProductBtn);

        addProductBtn = new QPushButton(productPage);
        addProductBtn->setObjectName("addProductBtn");

        productLayout->addWidget(addProductBtn);

        bottomSpacer = new QSpacerItem(20, 100, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        productLayout->addItem(bottomSpacer);

        contentStack->addWidget(productPage);
        profilePage = new QWidget();
        profilePage->setObjectName("profilePage");
        profileLayout = new QVBoxLayout(profilePage);
        profileLayout->setObjectName("profileLayout");
        topProfileSpacer = new QSpacerItem(20, 50, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        profileLayout->addItem(topProfileSpacer);

        changeIdBtn = new QPushButton(profilePage);
        changeIdBtn->setObjectName("changeIdBtn");

        profileLayout->addWidget(changeIdBtn);

        changePwBtn = new QPushButton(profilePage);
        changePwBtn->setObjectName("changePwBtn");

        profileLayout->addWidget(changePwBtn);

        assetBtn = new QPushButton(profilePage);
        assetBtn->setObjectName("assetBtn");

        profileLayout->addWidget(assetBtn);

        logoutBtn = new QPushButton(profilePage);
        logoutBtn->setObjectName("logoutBtn");

        profileLayout->addWidget(logoutBtn);

        deleteAccountBtn = new QPushButton(profilePage);
        deleteAccountBtn->setObjectName("deleteAccountBtn");

        profileLayout->addWidget(deleteAccountBtn);

        bottomProfileSpacer = new QSpacerItem(20, 50, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        profileLayout->addItem(bottomProfileSpacer);

        contentStack->addWidget(profilePage);

        mainLayout->addWidget(contentStack);


        verticalLayout->addLayout(mainLayout);

        MainMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainMenu);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 21));
        MainMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(MainMenu);
        statusbar->setObjectName("statusbar");
        MainMenu->setStatusBar(statusbar);

        retranslateUi(MainMenu);

        contentStack->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "\354\203\201\354\240\220", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainMenu", "\354\203\201\354\240\220", nullptr));
        productBtn->setText(QCoreApplication::translate("MainMenu", "\354\203\201\355\222\210", nullptr));
        friendBtn->setText(QCoreApplication::translate("MainMenu", "\354\271\234\352\265\254", nullptr));
        profileBtn->setText(QCoreApplication::translate("MainMenu", "\353\202\264 \355\224\204\353\241\234\355\225\204", nullptr));
        exitBtn->setText(QCoreApplication::translate("MainMenu", "\354\242\205\353\243\214", nullptr));
        viewProductBtn->setText(QCoreApplication::translate("MainMenu", "\354\203\201\355\222\210 \353\252\251\353\241\235", nullptr));
        addProductBtn->setText(QCoreApplication::translate("MainMenu", "\354\203\201\355\222\210 \353\223\261\353\241\235", nullptr));
        changeIdBtn->setText(QCoreApplication::translate("MainMenu", "\354\225\204\354\235\264\353\224\224 \353\263\200\352\262\275", nullptr));
        changePwBtn->setText(QCoreApplication::translate("MainMenu", "\353\271\204\353\260\200\353\262\210\355\230\270 \353\263\200\352\262\275", nullptr));
        assetBtn->setText(QCoreApplication::translate("MainMenu", "\353\263\264\354\234\240 \354\236\220\354\202\260 \355\231\225\354\235\270", nullptr));
        logoutBtn->setText(QCoreApplication::translate("MainMenu", "\353\241\234\352\267\270\354\225\204\354\233\203", nullptr));
        deleteAccountBtn->setText(QCoreApplication::translate("MainMenu", "\352\263\204\354\240\225 \354\202\255\354\240\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
