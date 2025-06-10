#pragma once

#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
    class Signup;
}

class Signup : public QMainWindow
{
    Q_OBJECT

public:
    explicit Signup(QWidget* parent = nullptr, QTcpSocket* socket = nullptr);
    ~Signup();

private slots:
    void OnSignupBtnClicked();
    void OnExitBtnClicked();

private:
    Ui::Signup* ui;
    QTcpSocket* socket;
};
