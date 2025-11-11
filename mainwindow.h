#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loginui.h"
#include "accountwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    loginUI *l;
    AccountWindow *acc;

    void quit();
    void login();
    void view();
    void loginSuccessHandler(const QString &username);
    void logout();
};
#endif // MAINWINDOW_H
