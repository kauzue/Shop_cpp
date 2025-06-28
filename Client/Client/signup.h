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
    void on_signupBtn_clicked();
    void on_backBtn_clicked();
    void resizeEvent(QResizeEvent* evnet);

private:
    Ui::Signup* ui;
    QTcpSocket* socket;
};
