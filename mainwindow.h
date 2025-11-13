#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loginui.h"
#include "accountwindow.h"
#include <vector>
#include "UserDefs.h"
#include "ObjectDefs.h"
#include "catalogueitemui.h"
#include "Catalogue.h"
#include "UserRepo.h"
#include "LoanRepo.h"
#include "checkoutControl.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Catalogue& c, PatronRepo& pr, LoanRepo&, QWidget *parent = nullptr);
    ~MainWindow();
    void loadCatalogue();
    Patron* getUser(){return currentUser;}

private slots:
    void on_pushButton_clicked();
    void handleLoginAttempt(const QString& username, const QString& password);

private:
    Ui::MainWindow *ui;
    loginUI *l;
    AccountWindow *acc;
    Catalogue& catalogue;
    PatronRepo& patrons;
    LoanRepo& loans;;
    Patron* currentUser;

    void quit();
    void login();
    void view();
    void loginSuccessHandler(Patron* patron);
    void handleCheckout(Item* item);
    void logout();
};
#endif // MAINWINDOW_H
