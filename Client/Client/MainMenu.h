#pragma once

#include <QMainWindow>
#include <QTcpSocket>

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
    void on_addProductBtn_clicked();
    void on_friendBtn_clicked();
    void on_profileBtn_clicked();
	void on_changeIDBtn_clicked();
	void on_changePWBtn_clicked();
	void on_logoutBtn_clicked();
    void on_assetBtn_clicked();
    void on_logoutBtn_clicked();
    void on_deleteAccountBtn_clicked();
    void on_exitBtn_clicked();
    void resizeEvent(QResizeEvent* evnet);

private:
    Ui::MainMenu* ui;
    QTcpSocket* socket;
};
