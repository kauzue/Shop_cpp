#pragma once

#include <QMainWindow>
#include <QTcpSocket>

#define MAX_INT 2147483647

namespace Ui {
    class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget* parent = nullptr, QTcpSocket* socket = nullptr);
    ~MainMenu();

private slots:
    void on_productBtn_clicked();
    void on_viewProductBtn_clicked();
    void updateList();
    void on_prevPageBtn_clicked();
    void on_nextPageBtn_clicked();
    void on_addProductBtn_clicked();
    void on_confirmAddProductBtn_clicked();
    void on_friendBtn_clicked();
    void on_profileBtn_clicked();
	void on_changeIdBtn_clicked();
	void on_confirmChangeIdBtn_clicked();
	void on_changePwBtn_clicked();
	void on_confirmChangePwBtn_clicked();
    void on_assetBtn_clicked();
    void on_logoutBtn_clicked();
    void on_deleteAccountBtn_clicked();
    void on_exitBtn_clicked();
    void resizeEvent(QResizeEvent* evnet);

private:
    Ui::MainMenu* ui;
    QTcpSocket* socket;
    int currentPage;
};
