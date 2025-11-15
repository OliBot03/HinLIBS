#ifndef ACCOUNTWINDOW_H
#define ACCOUNTWINDOW_H

#include <QMainWindow>
#include "UserDefs.h"
#include "AccountService.h"
#include "HoldRepo.h"
#include "Catalogue.h"
#include "accountitemui.h"
#include "holditemui.h"

namespace Ui {
class AccountWindow;
}

class AccountWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AccountWindow(QWidget *parent = nullptr, Patron *p = nullptr, 
                            HoldRepo *h = nullptr, Catalogue *cat = nullptr);
    ~AccountWindow();
    void setUsername(const QString &username);

private slots:
    void on_pushButton_clicked();

    void on_openLoan_clicked();

    void on_openHold_clicked();

private:
    Ui::AccountWindow *ui;
    QString username;
    Patron  *currentUser;
    HoldRepo *holds;
    Catalogue *catalogue;
};

#endif // ACCOUNTWINDOW_H
