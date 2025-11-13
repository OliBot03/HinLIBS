#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loginui.h"
#include "accountwindow.h"
#include <vector>
#include "UserDefs.h"
#include "ObjectDefs.h"
#include "catalogueitemui.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void loadCatalogue();
    void setCatalogue(std::vector<Item> items);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    loginUI *l;
    AccountWindow *acc;
    vector<Item> catalogue;

    void quit();
    void login();
    void view();
    void loginSuccessHandler(const QString &username);
    void logout();
};
#endif // MAINWINDOW_H
