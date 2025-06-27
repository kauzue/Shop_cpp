#pragma once

#include <QMainWindow>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Signup; }
QT_END_NAMESPACE

class Signup : public QMainWindow
{
    Q_OBJECT

public:
    explicit Signup(QWidget* parent = nullptr, QTcpSocket* socket = nullptr);
    ~Signup();

private slots:
    void on_signupBtn_clicked();
    void on_backBtn_clicked();

private:
    Ui::Signup* ui;
    QTcpSocket* socket;
};
