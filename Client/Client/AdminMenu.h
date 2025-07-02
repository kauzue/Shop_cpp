#pragma once

#include <QMainWindow>
#include <QTcpSocket>

#define MAX_INT 2147483647

namespace Ui {
    class AdminMenu;
}

class AdminMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminMenu(QWidget* parent = nullptr, QTcpSocket* socket = nullptr);
    ~AdminMenu();

private slots:
    void on_manageUserBtn_clicked();
    void on_viewUserListBtn_clicked();
    void updateList();
    void on_prevUserPageBtn_clicked();
    void on_nextUserPageBtn_clicked();
    void on_modifyUserBtn_clicked();
    void on_confirmUserChangeBtn_clicked();
    void on_logoutBtn_clicked();
    void on_exitBtn_clicked();
    void resizeEvent(QResizeEvent* evnet);

private:
    Ui::AdminMenu* ui;
    QTcpSocket* socket;
    int currentPage;
};
