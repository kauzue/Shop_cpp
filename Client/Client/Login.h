#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget* parent = nullptr);
    ~Login();

private slots:
    void OnLoginClicked();  // 로그인 버튼 눌렀을 때

private:
    Ui::Login* ui;
};
